#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1024

template<typename T>
struct rmq_2d {
    typedef vector< vector<T> > mat;

    int n, m, dim, i, j;
    vector<int> hp;
    vector< vector<mat> > data;
    mat aux;

    void init(int _n, int _m) {
        n = _n; m = _m;
        dim = max(n, m);

        hp.resize(dim + 3);
        hp.clear();
        for (i = 2; i <= dim; i++) hp[i] = 1 + hp[i / 2];

        aux = vector< vector<T> >(n + 1, vector<T>(m + 1, 0));
        data = vector< vector<mat> >(hp[n] + 1, vector<mat>(hp[m] + 1, aux));

    }

    void compute_data() {
        for (int p = 1; p <= hp[m]; p++)
            for (i = 1; i <= n; i++)
                for (j = 1; j + (1 << p) - 1 <= m; j++)
                    data[0][p][i][j] = max(data[0][p - 1][i][j], data[0][p - 1][i][j + (1 << (p - 1))]);

        for (int p1 = 1; p1 <= hp[n]; p1++)
            for (int p2 = 0; p2 <= hp[m]; p2++)
                for (i = 1; i + (1 << p1) - 1 <= n; i++)
                    for (j = 1; j + (1 << p2) - 1 <= m; j++)
                        data[p1][p2][i][j] = max(data[p1 - 1][p2][i][j], data[p1 - 1][p2][i + (1 << (p1 - 1))][j]);
    }

    T query(int x1, int y1, int x2, int y2) {
        int d1 = x2 - x1 + 1;
        int d2 = y2 - y1 + 1;
        int h1 = hp[d1];
        int h2 = hp[d2];

        T v1 = max(data[h1][h2][x1][y1], data[h1][h2][x2 - (1 << h1) + 1][y1]);
        T v2 = max(data[h1][h2][x1][y2 - (1 << h2) + 1], data[h1][h2][x2 - (1 << h1) + 1][y2 - (1 << h2) + 1]);
        return max(v1, v2);
    }
};

int n, m, i, j, test, tt;
int mat[maxN][maxN];
rmq_2d<int> RMQ;

int xx1, yy1, xx2, yy2;


int solve() {
    int ans = 0;
    int limit = min(xx2 - xx1 + 1, yy2 - yy1 + 1);

    for (int step = (1 << 10); step > 0; step >>= 1)
        if (ans + step <= limit)
            if (RMQ.query(xx1 + ans + step - 1, yy1 + ans + step - 1, xx2, yy2) >= ans + step)
                ans += step;

    return ans;
}

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &mat[i][j]);

    RMQ.init(n, m);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (mat[i][j] == 0) continue;

            mat[i][j] = 1 + min(mat[i - 1][j], min(mat[i][j - 1], mat[i - 1][j - 1]));
            RMQ.data[0][0][i][j] = mat[i][j];
        }
    }

    RMQ.compute_data();

    scanf("%d", &test);
    for (tt = 1; tt <= test; tt++) {
        scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
        printf("%d\n", solve());
    }





    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

#define maxN 111

int aux[maxN][maxN];
int aux2[maxN][maxN];
class Matrix {
    public:
        int dim;
        int data[maxN][maxN];

        void init(int _dim) {
            dim = _dim;
            memset(data, 0, sizeof(data));
        }

        void set(int x, int y, int v) {
            data[x][y] = v;
        }

        void operator*=(const Matrix& who) {
            int i, j, k;

            memcpy(aux, data, sizeof(aux));
            memcpy(aux2, who.data, sizeof(aux2));
            memset(data, 0, sizeof(data));

            for (k = 1; k <= dim; k++)
                for (i = 1; i <= k; i++)
                    for (j = k; j <= dim; j++)
                        data[i][j] = max(data[i][j], aux[i][k] + aux2[k][j]);
        }

        void operator=(const Matrix& who) {
            dim = who.dim;
            memcpy(data, who.data, sizeof(data));
        }

        int getAnswer() {
            int ans = 0;
            for (int i = 1; i <= dim; i++)
                for (int j = 1; j <= dim; j++)
                    ans = max(ans, data[i][j]);
            return ans;
        }
};

int n, t, i, j;
pair<int, int> v[maxN];
int work[maxN];

Matrix unit;
int dp[maxN][maxN];

Matrix pow_matrix, ans_matrix;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d", &n, &t);
    for (i = 1; i <= n; i++) {
        scanf("%d", &v[i].first);
        v[i].second = i;
    }

    sort(v + 1, v + n + 1);
    work[ v[1].second ] = 1;

    for (i = 2; i <= n; i++) {
        if (v[i].first == v[i - 1].first)
            work[ v[i].second ] = work[ v[i - 1].second ];
        else
            work[ v[i].second ] = work[ v[i - 1].second ] + 1;
    }

    unit.init(n);
    memset(dp, 0, sizeof(dp));
    for (int st = 1; st <= n; st++) {
        for (i = 1; i <= n; i++) {
            if (work[i] < st) continue;

            int val = 1;

            for (j = 1; j < i; j++) {
                if (work[j] > work[i]) continue;
                val = max(val, dp[st][work[j]] + 1);
            }

            dp[st][work[i]] = max(dp[st][work[i]], val);
        }

        for (j = 1; j <= n; j++) {
            dp[st][j] = max(dp[st][j - 1], dp[st][j]);
            //dp[st][j] = max(dp[st - 1][j], dp[st][j]);
            unit.set(st, j, dp[st][j]);
        }
    }

    pow_matrix = unit;
    ans_matrix.init(n);

    while (t) {
        if (t & 1) ans_matrix *= pow_matrix;
        t >>= 1;
        pow_matrix *= pow_matrix;
    }

    printf("%d", ans_matrix.getAnswer());

    return 0;
}
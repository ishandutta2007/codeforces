#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 105;
const int MAXM = 305;
const int INF = (int)1e9;

struct fenwick {
    int f[MAXM];
    fenwick() {
        for (int i = 0; i < MAXM; i++)
            f[i] = -INF;
    }
    void update(int x, int val) {
        for (; x < MAXM; x += x & -x)
            f[x] = max(f[x], val);
    }
    int get(int x) {
        int ret = -INF;
        for (; x; x -= x & -x)
            ret = max(ret, f[x]);
        return ret;
    }
};

int N, T;
int a[MAXN];

struct matrix {
    int mat[MAXN][MAXN];
    matrix() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                mat[i][j] = -INF;
    }
    void identity() {
        for (int i = 0; i < N; i++)
            mat[i][i] = 0;
    }
} lis;

matrix operator *(matrix A, matrix B) {
    matrix C;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C.mat[i][j] = max(C.mat[i][j], A.mat[i][k] + B.mat[k][j]);
    return C;
}

void load() {
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

int get(vector <int> V) {
    fenwick F;
    F.update(V[0], 0);
    for (int i = 1; i < V.size(); i++) 
        F.update(V[i], F.get(V[i]) + 1);
    return max(F.get(V.back()), 0);
}

int solve() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (a[i] > a[j]) {
                lis.mat[i][j] = -INF;
                continue;
            }
            vector <int> V;
            for (int k = i; k < N; k++)
                V.push_back(a[k]);
            for (int k = 0; k <= j; k++)
                V.push_back(a[k]);
            lis.mat[i][j] = get(V);
        }
    
    matrix sol;
    sol.identity();
    for (T--; T; T >>= 1) {
        if (T & 1) sol = sol * lis;
        lis = lis * lis;
    }
    
    int res = 0;
    for (int i = 0; i < N; i++) {
        vector <int> V;
        for (int j = i; j < N; j++)
            V.push_back(a[j]);
        int tmp = get(V);
        for (int j = 0; j < N; j++) 
            res = max(res, sol.mat[j][i] + tmp);
    }
    
    return res + 1;
}

int main() {
    load();
    printf("%d\n", solve());
    return 0;
}
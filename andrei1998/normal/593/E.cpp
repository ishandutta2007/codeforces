#include <iostream>
#include <cstring>

using namespace std;

const int mod = 1000000007;

int N;

class matrix {
public:
    int mat[21][21];

    matrix (int c = 0) {
        memset(mat, 0, sizeof(mat));

        if (c)
            for (int i = 1; i <= N; ++ i)
                mat[i][i] = c;
    }

    matrix operator* (const matrix &b) const {
        matrix res;

        for (int i = 1, j, k; i <= N; ++ i)
            for (j = 1; j <= N; ++ j)
                for (k = 1; k <= N; ++ k)
                    res.mat[i][j] = (res.mat[i][j] + 1ll * mat[i][k] * b.mat[k][j]) % mod;

        return res;
    }

    matrix operator^ (int b) {
        matrix res(1), aux(*this);

        while (b) {
            if (b & 1)
                res = res * aux;
            b >>= 1;
            aux = aux * aux;
        }

        return res;
    }
} mat;

int n, m;
bool state[21];

int encode (int lin, int col) {
    return (lin - 1) * m + col;
}

int dx[5] = {1, -1, 0, 0, 0};
int dy[5] = {0, 0, 1, -1, 0};

inline void recompute () {
    for (int i = 1, j, k; i <= n; ++ i)
        for (j = 1; j <= m; ++ j) {
            for (k = 0; k < 5; ++ k) {
                int nlin = i + dx[k];
                int ncol = j + dy[k];

                if (nlin >= 1 && ncol >= 1 && nlin <= n && ncol <= m)
                    if (!state[encode(i, j)] && !state[encode(nlin, ncol)])
                        mat.mat[encode(i, j)][encode(nlin, ncol)] = 1;
                    else
                        mat.mat[encode(i, j)][encode(nlin, ncol)] = 0;
            }
        }

}

int dp[21];

/*inline void print_mat () {
    cout << "e print" << endl;
    for (int i = 1; i <= N; ++ i) {
        for (int j = 1; j <= N; ++ j)
            cout << mat.mat[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

inline void print_dp () {
    cout << "e dp " << endl;
    for (int i = 1; i <= N; ++ i)
        cout << dp[i] << " \n"[i == N];
    cout << endl;
}*/

int aux[21];
inline void update_dp (const matrix &mat) {
    memset(aux, 0, sizeof(aux));
    for (int i = 1, j; i <= N; ++ i)
        for (j = 1; j <= N; ++ j)
            aux[i] = (aux[i] + 1ll * mat.mat[i][j] * dp[j]) % mod;

    for (int i = 1; i <= N; ++ i)
        dp[i] = aux[i];
}

int main()
{
    int q = 0;
    cin >> n >> m >> q;

    N = n * m;

    recompute();

    int type, x, y, t;
    int last_t = 1;

    dp[1] = 1;


    while (q --) {
        cin >> type >> x >> y >> t;

        update_dp(mat ^ (t - last_t));

        if (type == 1)
            cout << dp[encode(x, y)] << '\n';
        else {
            state[encode(x, y)] ^= 1;
            recompute();
        }

        last_t = t;
    }

    return 0;
}
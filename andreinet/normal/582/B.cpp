#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 105;

struct Matrix {
    int a[Nmax][Nmax];

    Matrix() {
        memset(a, 0, sizeof a);
    }

    Matrix(int A[Nmax][Nmax]) {
        memcpy(a, A, sizeof a);
    }
};

int A[Nmax], B[Nmax];
int dp[Nmax][Nmax];
int aux[Nmax];

map<int, int> normVal;

int N;

void norm(int *A, int N) {
    for (int i = 1; i <= N; ++i)
        B[i] = A[i];
    sort(B + 1, B + N + 1);

    int k = 0;
    for (int i = 1; i <= N; ++i) {
        if (i == 1 || B[i] > B[i - 1]) {
            ++k;
            normVal[B[i]] = k;
        }
    }

    for (int i = 1; i <= N; ++i)
        A[i] = normVal[A[i]];
}

Matrix logPow(int x) {
    if (x == 1) return Matrix(dp);
    else if (x % 2 == 1) {
        Matrix aux = logPow(x - 1), ret;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= i; ++j) {
                for (int k = j; k <= i; ++k) {
                    ret.a[i][j] = max(ret.a[i][j],
                            dp[i][k] + aux.a[k][j]);
                }
            }
        }
        return ret;
    } else {
        Matrix aux = logPow(x / 2), ret;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= i; ++j) {
                for (int k = j; k <= i; ++k) {
                    ret.a[i][j] = max(ret.a[i][j],
                            aux.a[i][k] + aux.a[k][j]);
                }
            }
        }
        return ret;
    }
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    int T;
    cin >> N >> T;

    for (int i = 1; i <= N; ++i)
        cin >> A[i];

    norm(A, N);

    for (int i = 1; i <= N; ++i) {
        memset(aux, 0, sizeof aux);
        aux[A[i]] = 1;

        assert(A[i] <= 100);

        for (int j = 1; j <= A[i]; ++j) {
            for (int k = j; k <= A[i]; ++k) {
                if (dp[k][j] != 0) {
                    aux[j] = max(aux[j], dp[k][j] + 1);
                }
            }
        }
        for (int j = 1; j <= A[i]; ++j)
            dp[A[i]][j] = max(dp[A[i]][j], aux[j]);
    }

    /*for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cerr << dp[i][j] << " \n"[j == N];*/

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

    /*for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cerr << dp[i][j] << " \n"[j == N];*/

    Matrix answer = logPow(T);
    int ans = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            ans = max(ans, answer.a[i][j]);

    cout << ans << '\n';
}
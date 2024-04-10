#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

const int Nmax = 55;

int A[2][Nmax][Nmax];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    for (int i = 0; i <= n2; ++i)
        A[1][0][i] = 1;
    for (int i = 0; i <= n1; ++i)
        A[0][i][0] = 1;
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            for (int k = i - 1; (i - k) <= k1 && k >= 0; --k)
                if (A[1][k][j] == 0)
                    A[0][i][j] = 1;
            for (int k = j - 1; (j - k) <= k2 && k >= 0; --k)
                if (A[0][i][k] == 0)
                    A[1][i][j] = 1;
        }
    }
    cout << (A[0][n1][n2] ? "First\n": "Second\n");
}
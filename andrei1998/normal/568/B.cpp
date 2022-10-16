#include <iostream>

using namespace std;

const int NMAX = 4005;
const int mod = 1000000007;

int comb[NMAX][NMAX];
int cliques[NMAX];

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i <= n; ++ i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++ j) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            if (comb[i][j] >= mod)
                comb[i][j] -= mod;
        }
    }

    cliques[0] = 1;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= i; ++ j)
            cliques[i] = (cliques[i] + 1ll * cliques[i - j] * comb[i - 1][j - 1]) % mod;

    int ans = 0;
    for (int i = 0; i < n; ++ i)
        ans = (ans + 1ll * cliques[i] * comb[n][n - i]) % mod;

    cout << ans << '\n';
    return 0;
}
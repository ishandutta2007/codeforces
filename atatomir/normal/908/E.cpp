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

#define maxN 52
#define maxM 1024
#define mod 1000000007

int n, m, i, j;
char s[maxN][maxM];
int ord[maxM];

ll comb[maxM][maxM];
ll bell[maxM];
ll ans;

int main()
{
    //freopen("test.in","r",stdin);

    scanf("%d%d\n", &m, &n);
    for (i = 1; i <= n; i++)
        scanf("%s\n", s[i] + 1);

    for (i = 1; i <= m; i++) ord[i] = i;

    auto cmp = [](int a, int b)->int const {
        int i;

        for (i = 1; i <= n; i++)
            if (s[i][a] != s[i][b])
                break;

        if (i > n) return 0;
        return (s[i][a] < s[i][b] ? 1 : 0);
    };

    sort(ord + 1, ord + m + 1, cmp);

    bell[0] = 1;
    for (i = 0; i <= m; i++) {
        comb[i][0] = 1;
        for (j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
            if (comb[i][j] >= mod) comb[i][j] -= mod;

            bell[i] = (bell[i] + comb[i - 1][j - 1] * bell[i - j]) % mod;
        }
    }

    ans = 1LL;
    for (i = 1; i <= m; i = j) {
        for (j = i; cmp(ord[i], ord[j]) == 0 && cmp(ord[j], ord[i]) == 0; j++);
        ans *= bell[j - i];
        ans %= mod;
    }

    cout << ans;


    return 0;
}
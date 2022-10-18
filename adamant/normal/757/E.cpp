#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 42, mod = 1e9 + 7;
vector<int> primes[maxn];
int f[maxn][20];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2; i < maxn; i++)
        if(primes[i].empty())
            for(int j = i; j < maxn; j += i)
                primes[j].push_back(i);
    f[0][0] = 1;
    for(int i = 1; i < 20; i++)
        f[0][i] = 2;
    for(int i = 1; i < maxn; i++)
        for(int j = 0; j < 20; j++)
            for(int k = 0; k <= j; k++)
            {
                f[i][j] += f[i - 1][k];
                if(f[i][j] >= mod)
                    f[i][j] -= mod;
            }
    int q;
    cin >> q;
    while(q--)
    {
        int r, n;
        cin >> r >> n;
        int ans = 1;
        int tn = n;
        for(auto it: primes[n])
        {
            int k = 0;
            while(tn % it == 0)
            {
                tn /= it;
                k++;
            }
            ans = 1LL * ans * f[r][k] % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
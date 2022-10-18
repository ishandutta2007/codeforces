#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 42, mod = 1e9 + 7;
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
    int n;
    cin >> n;
    int ans = 1;
    map<int, int> cnt;
    for(int i = 0; i < n; i++)
    {
        int s;
        cin >> s;
        for(auto it: primes[s])
            cnt[it]++;
    }
    for(auto it: cnt)
        ans = max(ans, it.second);
    cout << ans << endl;
    return 0;
}
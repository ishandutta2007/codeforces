#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 42, mod = 1e9 + 7;
vector<int> primes[maxn];
int f[maxn][20];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    map<char, int> cnt;
    for(auto c: s)
        cnt[c]++;
    map<char, int> cnt2;
    string t = "Bulbasaur";
    for(auto c: t)
        cnt2[c]++;
    int ans = 10000000000;
    for(auto it: cnt2)
        ans = min(ans, cnt[it.first] / it.second);
    cout << ans << endl;

    return 0;
}
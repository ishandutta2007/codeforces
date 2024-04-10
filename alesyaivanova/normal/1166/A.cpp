#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb emplace_back
#define pf emplace_front
#define ff first
#define ss second
#define pii pair<int, int>
#define mp make_pair

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s[0]]++;
    }
    int ans = 0;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        int k = (*i).ss;
        int t = k / 2;
        int p = k - t;
        ans += t * (t - 1) / 2 + p * (p - 1) / 2;
    }
    cout << ans;
}
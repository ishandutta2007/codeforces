#include <bits/stdc++.h>

using namespace std;

#define int unsigned int
const int maxn = 2e9 + 228;
map<int, int> s;

int get(int x)
{
    int r = 0;
    for(; x > 0; x -= x & -x)
        r = max(r, s[x]);
    return r;
}

int make(int x, int c)
{
    for(; x < maxn; x += x & -x)
        s[x] = max(s[x], c);
}

main()
{
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int, int> v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v, v + n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        auto u = v[i];
        int t;
        if(u.first < u.second)
            t = 1;
        else
            t = get(u.first - u.second + 42) + 1;
        make(u.first + u.second + 42, t);
        ans = max(ans, t);
    }
    cout << ans << "\n";
    //v.first - v.second - u.first - u.second >= 0
    //u.first + u.second <= v.first - v.second
    return 0;
}
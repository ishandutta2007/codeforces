#include <bits/stdc++.h>

using namespace std;

main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    map<int, int64_t> ans;
    int n;
    cin >> n;
    int t;
    map<int, int> g, tmp;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        for(auto it: g)
            tmp[__gcd(t, it.first)] += it.second,
            ans[__gcd(t, it.first)] += it.second;
        tmp[t]++;
        ans[t]++;
        swap(tmp, g);
        tmp.clear();
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}
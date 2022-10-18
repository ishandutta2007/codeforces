#include <bits/stdc++.h>

using namespace std;

main()
 {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int d[n], s[n];
    for(int i = 0; i < n; i++)
        cin >> d[i] >> s[i];
    set<pair<int, int>> dtoi;
    for(int i = 0; i < n; i++)
        dtoi.insert({d[i], i});
    vector<pair<int, int>> e;
    while(!dtoi.empty())
    {
        int v = dtoi.begin()->second;
        dtoi.erase(dtoi.begin());
        if(d[v] == 0) continue;
        e.push_back({v, s[v]});
        dtoi.erase({d[s[v]], s[v]});
        s[s[v]] ^= v;
        d[s[v]]--;
        dtoi.insert({d[s[v]], s[v]});

    }
    cout << e.size() << "\n";
    for(auto it: e) cout << it.first << ' ' << it.second << "\n";
 }
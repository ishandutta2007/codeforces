#include <bits/stdc++.h>

using namespace std;

#define int long long
int a[300005];

main(){
    //freopen("input.txt", "r");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    set < pair < int, int > > pos;
    set < pair < int, int > > cur;
    for (int i = 1; i <= n; ++i){
        pos.insert({a[i], i});
        cur.insert({i, a[i]});
    }
    int k = 1e18;
    for (auto key : pos){
        cur.erase({key.second, key.first});
        if ((int)cur.size() == 0) break;
        auto p = (*cur.rbegin()), t = (*cur.begin());
        int d1 = abs(key.second - p.first), d2 = abs(key.second - t.first);
        k = min({k, key.first / d1, key.first / d2});
    }
    cout << k << '\n';
    return 0;
}
#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> a;
    vector<int> l(n), r(n), t(n);
    for(int i = 0; i < n; ++i){
        cin >> l[i] >> r[i] >> t[i];
        t[i]--;
        a.pb({l[i], {0, i}});
        a.pb({r[i], {1, i}});
    }
    sort(a.begin(), a.end());
    vector<multiset<int>> v(2);
    int ans = n;
    for(int i = 0; i < a.size(); ++i){
        if(a[i].s.f == 0)
            v[t[a[i].s.s]].insert(r[a[i].s.s]);
        else{
            int t1 = t[a[i].s.s];
            if(v[1-t1].size() > 0 && v[t1].find(a[i].f) != v[t1].end()){
                ans--;
                v[1-t1].erase(v[1-t1].begin());
            }
            if(v[t1].find(a[i].f) != v[t1].end())
                v[t1].erase(v[t1].find(a[i].f));
        }
    }
    cout << ans;
    return 0;
}
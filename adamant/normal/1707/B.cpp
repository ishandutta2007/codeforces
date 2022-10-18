#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    while(cnt.size() > 1) {
        map<int, int> ncnt;
        for(auto it = begin(cnt); it != end(cnt); it++) {
            if(it != begin(cnt)) {
                ncnt[it->first - prev(it)->first]++;
            }
            if(it->second > 1) {
                ncnt[0] += it->second - 1;
            }
        }
        cnt = ncnt;
    }
    cout << ((begin(cnt)->second == 1) ? begin(cnt)->first : 0) << "\n";
}
 
signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
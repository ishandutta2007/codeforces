#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 1e6 + 100;
const int mod = (int)1e9+7;
long long ans = 0;
int d[maxn];
int n;
int m;
void solve() {
    cin >> n >> m;
    vector< pair<int, int> > a(n);
    vector< pair<int, int> > b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    for(int i = 0; i < n; i++ ){
        for(int j = 0; j < m; j++) {
            if(a[i].first <= b[j].first && a[i].second <= b[j].second) {
                d[b[j].first - a[i].first] = max(d[b[j].first - a[i].first], b[j].second - a[i].second + 1);
            }
        }
    }
    for(int i = maxn-2; i >= 0; i--) {
        d[i] = max(d[i+1], d[i]);
    }
    int ans = maxn;
    for(int i = 0; i < maxn; i++) {
        ans = min(ans, i + d[i]);
    }
    cout << ans << "\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}
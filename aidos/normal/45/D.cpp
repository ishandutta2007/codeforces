
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 10;
int n, m, k;
pair<int, int> l[maxn], r[maxn];
int a[maxn];
void solve() {
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++) {
        cin >> l[2*i].first >> l[2*i+1].first;
        a[i] = l[2*i].first;
        l[2*i].second = -(i+1);
        l[2*i+1].second = i;
        for(int j = l[2*i].first; j <= l[2*i].first + n && j <= l[2*i+1].first; j++) {
            s.insert(j);
        }
    }
    sort(l,l+2*n);
    vector<int>ans(n);
    for(int i = 0; i < 2 * n; i++) {
        if(l[i].second >= 0) {
            int x = *s.lower_bound(a[l[i].second]);
            s.erase(x);
            ans[l[i].second] = x;
        }
    }
    for(int x: ans) cout << x << " ";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}
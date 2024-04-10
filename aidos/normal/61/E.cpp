
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)1e6 + 10;
int n, m, k;
int t[maxn];
int get(int pos) {
    int res = 0;
    for(int i = pos; i >= 0; i = (i&(i+1)) - 1) {
        res += t[i];
    }
    return res;
}
void add(int pos, int val) {
    for(int i = pos; i < n; i |= (i + 1)) {
        t[i] += val;
    }
}
vector<int> calc(vector<int> a) {
    vector<int> b;
    for(int x: a) b.push_back(x);
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for(int i = 0; i < a.size(); i++) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    for(int i = 0; i < n; i++) t[i] = 0;
    vector<int> cnt;
    for(int i = 0; i < n; i++) {
        cnt.push_back(get(a[i] - 1));
        add(a[i], 1);
    }
    return cnt;
}
void solve() {
    cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
        b.push_back(-x);
    }
    reverse(a.begin(), a.end());
    vector<int> cnta = calc(a);
    reverse(cnta.begin(), cnta.end());
    vector<int> cntb = calc(b);
    ll ans = 0;
    for(int i = 0; i < cnta.size(); i++) {
        ans += cnta[i] * 1ll * cntb[i];
    }
    cout<<ans<<"\n";
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
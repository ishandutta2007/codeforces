#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
pair<int, ll> d[maxn];
pair<int, ll> dp[maxn];
void upd_min(pair<int, ll> &x, pair<int, ll> y) {
    if(y.first == 0) return;
    if(x.first == 0) {
        x = y;
    } else {
        x = min(x, y);
    }
}

void upd_max(pair<int, ll> &x, pair<int, ll> y) {
    if(y.first == 0) return;
    if(x.first == 0) {
        x = y;
    } else {
        x = max(x, y);
    }
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    vector<ll> b;
    for(int i = 0; i < n; i++) {
        if(i < 5 || i + 5 >= n) {
            b.push_back(a[i]);
        }
    }
    n = b.size();
    ll ans = -(1ll<<60);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                for(int t = k + 1; t+1 < n; t++) {
                    ans = max(ans, b[i] * b[j] * b[k] * b[t] * b.back());
                }
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
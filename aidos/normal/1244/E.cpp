#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
ll k;
int a[maxn];
ll b[maxn];
ll get() {
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            b[i] = 0;
        } else {
            b[i] = b[i-1] + abs(a[i] - a[i-1]) * 1ll * i;
        }
    }
    ll op = 0;
    ll ans = (1ll<<60);
    for(int i = n-1; i >= 0; i--) {

        if(i == n-1) {
            op = 0;
        } else {
            op += abs(a[i + 1] - a[i]) * 1ll * (n - 1 - i);
        }
        if(op > k) break;
        int pos = upper_bound(b, b + n, k - op) - b;
        if(pos > i) return 0;
        ll cur_dif = abs(a[i] - a[pos - 1]);
        ll d = (k - op - b[pos-1])/pos;
        cur_dif -= d;
        ans = min(ans, cur_dif);
    }
    return ans;
}
void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    ll ans = a[n - 1] - a[0];
    ans = min(ans, get());
    reverse(a, a + n);
    ans = min(ans, get());
    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
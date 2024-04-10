#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
ll s;
bool ok(ll x) {
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        cur += a[i] - x;
    }
    return cur>=s;
}
void solve() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll l = 0, r = *min_element(a, a + n);
    int res = -1;
    while(l <= r) {
        ll mid = (l + r)/2;
        if(ok(mid)) {
            res = mid;
            l = mid+1;
        } else r = mid-1;
    }
    cout << res << "\n";
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
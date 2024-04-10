#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
ll a[maxn];
ll b[maxn];
int ok(ll r) {
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(j + 1 < k && a[i] - r > b[j]) j++;
        if(abs(a[i] - b[j]) > r) return 0;
    }
    return 1;
}
void solve() {
    cin >> n >> k;
    for(int i=0; i < n; i++) {
        cin >> a[i];
    }
    for(int i=0; i < k; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + k);
    ll l = 0, r = 1ll<<40;
    ll res = 0;
    while(l <= r) {
        ll mid = (l + r)/2;
        if(ok(mid)) {
            r = mid-1;
            res = mid;
        } else {
            l = mid + 1;
        }
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
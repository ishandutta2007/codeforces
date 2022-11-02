#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = (int)100200;
const ll inf = (1ll<<50);

int n;
int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
}
void solve() {
    cin >> n;
    int cur = ask(1, n);
    if(cur == 1 || ask(1, cur) != cur) {
        int l = cur + 1;
        int r = n;
        int ans = 0;
        while(l <= r) {
            int mid = (l + r)/2;
            if(ask(cur, mid) == cur) {
                r = mid-1;
                ans = mid;
            } else l = mid + 1;
        }

        cout << "! " << ans << endl;
    } else {
        int l = 1;
        int r = cur-1;
        int ans = 0;
        while(l <= r) {
            int mid = (l + r)/2;
            if(ask(mid, cur) == cur) {
                l = mid+1;
                ans = mid;
            } else r = mid - 1;
        }
        cout << "! " << ans << endl;
    }
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie();
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
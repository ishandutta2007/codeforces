#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
int n;
int a[maxn];
ll s[maxn];
ll p[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    p[1] = a[1];
    for(int i = 2; i <= n; i++) {
        ll t = p[i-1];
        ll d = s[i] - t * i;
        if(d <= 0) {
            p[i] = t;
        }else {
            p[i] = t + (d+i-1)/i;
        }
    }
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        ll x;
        cin >> x;
        int l = 1, r = n;
        int res = -1;
        while(l <= r) {
            int mid = (l + r)/2;
            if(p[mid] <= x && s[n] <= mid * x) {
                res = mid;
                r = mid-1;
            } else{
                l = mid+1;
            }
        }
        cout << res << "\n";
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)6e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
ll n, k;
ll get(ll l, ll r) {
    ll len = r - l + 1;
    ll sum = (r+l) * len/2 - len + 1;
    return sum;
}
void solve(){
    cin >> n >> k;
    if(n == 1) {
        cout << 0 << "\n";
        return;
    }
    if(n > get(2, k)) {
        cout << -1 << "\n";
        return;
    }
    ll l = 2, r = k;
    ll res=1;
    while(l <= r) {
        ll mid = (l + r)/2;
        if(get(mid, k) >= n) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid-1;
        }
    }
    cout<<k - res + 1 << "\n";
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
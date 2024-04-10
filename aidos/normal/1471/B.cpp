#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
void solve(){
    cin >> n >> k;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ans += a[i];
        b[i] = 1;
    }
    for(int it = 0; ; it++) {
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if(a[i] % k != 0) {
                ok = 0;
                break;
            }
            ans += b[i] * 1ll * a[i];
            b[i] *= k;
            a[i] /= k;
        }
        if(!ok) break;
    }
    cout << ans << "\n";

}




int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
typedef long long ll;
int n, q;
int a[maxn];
ll pref[maxn];
ll b[maxn];
ll mi[maxn];
void solve(){
    cin >> n;
    int cur = (n + 1)/2;
    for(int i = 1; i <= cur; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    for(int i = cur + 1; i <= n; i++) {
        a[i] = x;
    }
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i];
        b[i] = x - a[i] + b[i-1];
        mi[i] = min(b[i], mi[i-1]);
    }
    for(int i = cur; i <= n; i++) {
        if(pref[i] > 0 && pref[i] + mi[n - i] > 0) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}
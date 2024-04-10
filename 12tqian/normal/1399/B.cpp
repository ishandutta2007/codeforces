#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve_case(){
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll ans = 0;
    ll amin = 1e9;
    ll bmin = 1e9;
    for(int i = 0; i < n; i++){
        amin = min(amin, a[i]);
        bmin = min(bmin, b[i]);
    }
    for(int i = 0; i < n; i++){
        ans += max(a[i] - amin, b[i] - bmin);
    }
    cout << ans << '\n';
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int tt; cin >> tt;
    while(tt--) solve_case();
    return 0;
}
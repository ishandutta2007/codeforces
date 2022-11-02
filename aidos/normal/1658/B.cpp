#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
string s;
const  int mod = 998244353;
void solve(){
    cin>>n;
    if(n == 1) {
        cout << 0 << "\n";
        return;
    }
    if(n == 2) {
        cout << 1 << "\n";
        return;
    }
    if(n % 2 == 1) {
        cout << 0 << "\n";
        return;
    }
    ll ans = 1;
    for(int i = 0; i < n/2; i++) {
        ans = (ans * (i + 1)) % mod;
    }
    ans = (ans * ans) % mod;
    cout << ans << "\n";
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}
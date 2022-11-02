#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
bool can(ll x, ll y) {
    if(y % x != 0) return false;
    if(y/x > 0) return true;
    return false;
}
void solve(){
    ll a, b, c;
    cin >>a >> b >> c;
    if((c-a) % 2 == 0 && can(b, (c-a)/2 + a)) {
        cout << "YES\n";
    } else if(can(a, b - (c-b))) {
        cout << "YES\n";
    } else if(can(c, b + (b-a))) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
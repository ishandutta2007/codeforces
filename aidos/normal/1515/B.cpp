#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    ll n;
    cin >> n;
    ll x = sqrt(n/2 + 0.5);
    ll y = sqrt(n/4 + 0.5);
    if(x * x == n/2 && n % 2 == 0) {
        cout << "YES\n";
    } else if(y* y == n/4 && n % 4 == 0) {
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
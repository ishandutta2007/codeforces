#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];

void solve(){
    ll a, b;
    cin >> a>>b;
    ll g = __gcd(a, b);
    a /= g;
    b /= g;
    int cnt = 0;
    while(a % 2 == 0) {
        a/=2;
        cnt++;
    }
    while(b % 2 == 0) {
        b/=2;
        cnt++;
    }
    if(a != 1 || b != 1) {
        cout << -1 << "\n";
        return;
    }
    cout << (cnt + 2)/3 << "\n";
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
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int prime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}
void solve(){
    cin >> n;
    int x = n + 1;
    while(!prime(x)) x++;
    if(n + 1 == x) {
        cout << x-2 << "/" << 2ll * x << "\n";
        return;
    }
    int y = n;
    while(!prime(y)) y--;
    //1/2 - 1/y + ((n + 1) - y)/(x*y);
    ll q = 2ll * x * y;
    ll p = x *1ll* y - 2ll * x + 2ll*((n + 1) - y);
    ll g = __gcd(p, q);
    cout << p/g << "/"<< q/g << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
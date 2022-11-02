#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

void solve() {
    ll x, y;
    cin >> x >> y;
    if(x > y || x % 2 != y % 2) {
        cout << -1 << "\n";
        return;
    }

    if(x == y) {
        if(x == 0) {
            cout << 0 << "\n";
            return;
        }
        cout << "1\n" << x << "\n";
        return;
    }
    ll a = 0;
    ll b = x;
    ll c = y - x;
    for(int i = 60; i>=0;i--) {
        if(x & (1ll<<i)) continue;
        if(c >= 2*(1ll<<i)) {
            b ^= 1ll<<i;
            a ^= 1ll<<i;
            c -= 2*(1ll<<i);
        }
    }
    if(c == 0) {
        cout << 2 << "\n";
        cout << a << " "<< b << "\n";
        return;
    }
    cout << 3 << "\n";
    cout << x << " " << (y-x)/2 << " " << (y-x)/2 << "\n";
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}


#pragma clang diagnostic pop
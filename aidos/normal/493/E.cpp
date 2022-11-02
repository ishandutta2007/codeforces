#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
ll t, a, b;
void solve() {
    cin >> t >> a >> b;

    if(a == b) {
        if(t == a) {
            if(t == 1) {
                cout << "inf\n";
            } else {
                cout << 2 << "\n";
            }
        } else {
            cout << 1 << "\n";
        }
        return;
    }
    if(t >= a || a >= b) {
        cout << 0 << "\n";
        return;
    }
    ll cur = 1;
    ll s = 0;
    ll d = b;
    while(b > 0) {
        s += (b % a) * cur;
        cur *= t;
        b/=a;
    }
    while(d % a == 0) {
        d /= a;
    }

    int cnt = 0;
    if(d == 1 && t == 1) cnt = 1;
    if(s == a) {
        cout << cnt+1 << "\n";
    } else {
        cout << cnt << "\n";
    }
}

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
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
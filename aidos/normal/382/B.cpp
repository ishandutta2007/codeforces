#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn = (int) 1e6 + 10;
const int mod = (int) 1e9 + 7;
ll a, b, w, x, c;
pair<int, ll> nxt[1111][1000];
void solve() {
    cin >> a >> b >> w >> x >> c;
    for(int i = 0; i < w; i++) {
        if(i >= x) {
            nxt[i][0] = make_pair(i-x, 0);
        } else {
            nxt[i][0] = make_pair(w-(x-i), 1);
        }
    }
    for(int i = 1; i < 1000; i++) {
        for(int j = 0; j < w; j++) {
            pair<int, ll> cur = nxt[j][i-1];
            nxt[j][i] = nxt[cur.first][i-1];
            nxt[j][i].second += cur.second;
            nxt[j][i].second = min(nxt[j][i].second, (ll)1e18);
        }
    }
    if(c <= a) {
        cout << 0 << "\n";
        return;
    }
    ll ans = 0;
    for(int i = 60; i >= 0; i--) {
        if(c-(1ll<<i)>a-nxt[b][i].second) {
            c -= 1ll<<i;
            ans += 1ll<<i;
            a -= nxt[b][i].second;
            b = nxt[b][i].first;
        }
    }
    cout << ans + 1 << "\n";
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
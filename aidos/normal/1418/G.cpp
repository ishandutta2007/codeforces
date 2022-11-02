#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
int n, m;
ll h[maxn];
ll a[maxn];
ll b[maxn];
ll rand2() {
    return rand() * 1ll  * rand() + rand();
}
ll gen() {
    return (rand2() << 16) | rand2();
}
queue<int> g[maxn];
int cnt[maxn];
void solve() {
    srand(time(0));
    cin >> n;
    h[0] = 0;
    for(int i = 1; i <= n; i++) {
        a[i] = gen();
        b[i] = gen();
    }
    map<ll, int> M;
    M[0]++;
    int l = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x] = (cnt[x] + 1) % 3;
        h[i] = h[i-1];
        if(cnt[x] == 1) {
            h[i] ^= a[x];
        } else if(cnt[x] == 2) {
            h[i] ^= a[x];
            h[i] ^= b[x];
        } else {
            h[i] ^= b[x];
        }
        g[x].push(i);
        if(g[x].size() > 3) {
            int d = g[x].front();
            g[x].pop();
            while(l < d) {
                M[h[l]]--;
                l++;
            }
        }
        ans += M[h[i]];
        M[h[i]]++;
    }
    cout << ans << "\n";
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}
//
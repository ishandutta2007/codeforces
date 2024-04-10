#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
unordered_map<int, int> m[maxn];
ll b[maxn];
ll c[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i <= 30; i++) {
        m[i].reserve(2 * n);
    }
    for(int i = 0; i < n; i++) {
        int x = 0;
        for(int j = 30; j >= 0; j--) {
            if(a[i] & (1<<j)) {
                if(m[j].count(x)) c[j] += m[j][x];
                x |= 1<<j;
            } else {
                if(m[j].count(x|(1<<j))) b[j] += m[j][x|(1<<j)];
            }
            m[j][x]++;
        }
    }
    ll ans = 0;
    int x = 0;
    for(int i = 0; i <= 30; i++) {
        if(b[i] <= c[i]) {
            ans += b[i];
        } else {
            ans += c[i];
            x ^= 1<<i;
        }
    }
    cout << ans << " "<<x << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
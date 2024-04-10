#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
ll a, b;
void solve() {
    cin >> a >> b;
    int ans = 0;
    for(int i = 1; i <= 61; i++) {
        ll st = (1ll<<i) - 1;
        for(int j = 0; j < i - 1; j++) {
            ll cur = st ^ (1ll<<j);
            if(cur >= a && cur <= b) ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int a[maxn];
int n;
int cnt[22];
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < 21; j++) {
            if(x & (1<<j)) {
                cnt[j]++;
            }
        }
    }
    for(int j = 0; j < 21; j++) {
        for(int i = 0; i < cnt[j]; i++) {
            a[n - i - 1] |= (1<<j);
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += a[i] * 1ll * a[i];
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
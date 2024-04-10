#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n;
int a[maxn];
int b[maxn];
void solve() {
    cin >> n;
    pair<ll, ll> ans =make_pair(n-1, 1);
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ans = min(ans, make_pair(n-i, i));
            ans = min(ans, make_pair(n-n/i, n/i));
        }
    }
    cout << ans.second << " "<<ans.first << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
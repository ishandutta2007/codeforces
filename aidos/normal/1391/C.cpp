#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, k;
int a[maxn];
string s;
void solve() {
    cin >> n;
    ll ans = 1;
    ll b = 1;
    for(int i = 1; i <= n; i ++) ans = (ans * i) % mod;
    for(int i = 2; i <= n; i++) b = (b * 2) % mod;
    cout << (ans + mod - b) % mod << "\n";
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
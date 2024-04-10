#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)5e5 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
string s;
int n, k;
int used[maxn];
int c[maxn][3];
int a[maxn];
void solve(){
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    used[0] = 1;
    used[n + 1] = 0;
    c[1][0] = 1;
    c[n][2] = 1;
    for(int i =k-1; i >= 0; i--) {
        used[a[i]] = 1;
        if(used[a[i] - 1]) c[a[i]][0] = 1;
        if(used[a[i]]) c[a[i]][1] = 1;
        if(used[a[i] + 1]) c[a[i]][2] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            if(c[i][j] == 0) {
                ans++;
                //cout << i << " " << j-1 << "\n";
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
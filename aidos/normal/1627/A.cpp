#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 100;
typedef long long ll;
int n, k;
int a[maxn];
int b[maxn];
string s;
int cnt[maxn];

void solve(){
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int ans = maxn;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if(x == 'B') {
                if(i == r && j == c) {
                    ans = 0;
                } else if(i == r || j == c) {
                    ans = min(ans, 1);
                } else {
                    ans = min(ans, 2);
                }
            }
        }
    }
    if(ans == maxn) ans = -1;
    cout << ans << "\n";
}





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}
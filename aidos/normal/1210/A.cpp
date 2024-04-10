#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)110;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
int b[maxn];
int c[maxn];
int u[maxn][maxn];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i];
    if(n <= 6) {
        cout << m << "\n";
        return;
    }
    int ans = 0;
    for(int x = 1; x <= n; x++) {
        for(int y = x + 1; y <= n; y++) {
            memset(c, 0, sizeof c);
            memset(u, 0, sizeof u);
            int sz = 2;
            for(int i = 1; i <= n; i++) {
                if(i == x || i == y) {
                    c[i] = 1;
                }else{
                    c[i] = sz;
                    sz++;
                }
            }
            int cur = 0;
            for(int i = 0; i < m; i++) {
                int x = c[a[i]];
                int y = c[b[i]];
                if(!u[x][y]) {
                    u[x][y] = u[y][x] = 1;
                    cur++;
                }
            }
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, k;
int a[111][111];
int b[111][111];
int u[111][111];
int cnt;
int ok(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    return 1;
}
void dfs(int x, int y) {
    if(u[x][y]) return;
    u[x][y] = 1;
    cnt++;
    if(ok(x + 1, y) && a[x][y] == 0) dfs(x + 1, y);
    if(ok(x - 1, y) && a[x - 1][y] == 0) dfs(x - 1, y);
    if(ok(x, y+1) && b[x][y] == 0) dfs(x, y + 1);
    if(ok(x, y-1) && b[x][y-1] == 0) dfs(x , y-1);
}
void solve() {
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2) {
            for(int j = min(y1, y2); j < max(y1, y2); j++) {
                a[x1-1][j] = 1;
            }
        } else {
            for(int j = min(x1, x2); j < max(x1, x2); j++) {
                b[j][y1-1] = 1;
            }
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!u[i][j]) {
                cnt = 0;
                dfs(i, j);
                ans.emplace_back(cnt);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for(int x:ans) cout << x << " ";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
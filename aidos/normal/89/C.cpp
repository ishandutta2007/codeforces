
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e4 + 10;
int n, m;
string s[maxn];
vector<int> L[maxn], R[maxn], D[maxn], U[maxn];
void build() {
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= m + 1; j++) {
            if(s[i][j] == '.') {
                L[i][j] = j-1;
                R[i][j] = j+1;
                U[i][j] = i-1;
                D[i][j] = i+1;
            } else {
                L[i][j] = R[i][j] = j;
                D[i][j] = U[i][j] = i;
            }
        }
    }
}
void upd(int x, int y) {
    L[x][y] = y-1;
    R[x][y] = y+1;
    D[x][y] = x+1;
    U[x][y] = x-1;
}
int cnt;
int getD(int x, int y) {
    if(D[x][y] == x) return x;
    return D[x][y] = getD(D[x][y], y);
}
int getU(int x, int y) {
    if(U[x][y] == x) return x;
    return U[x][y] = getU(U[x][y], y);
}
int getL(int x, int y) {
    if(L[x][y] == y) return y;
    return L[x][y] = getL(x, L[x][y]);
}
int getR(int x, int y) {
    if(R[x][y] == y) return y;
    return R[x][y] = getR(x, R[x][y]);
}

void go(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m) return;
    cnt++;
    upd(x, y);
    if(s[x][y]=='D') {
        int X = getD(x, y);
        go(X, y);
    } else if(s[x][y] == 'U') {
        int X = getU(x, y);
        go(X, y);
    } else if(s[x][y] == 'L') {
        int Y = getL(x, y);
        go(x, Y);
    } else {
        int Y = getR(x, y);
        go(x, Y);
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = "#" + s[i] + "#";
    }
    for(int i = 0; i <= n + 5; i++) {
        L[i].resize(m+5);
        R[i].resize(m+5);
        D[i].resize(m+5);
        U[i].resize(m+5);
    }
    int ans = 0;
    int ans2 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) {
            if(s[i][j] == '.') continue;
            build();
            cnt = 0;
            go(i, j);
            if(ans < cnt) {
                ans = cnt;
                ans2 = 1;
            } else if(ans == cnt) {
                ans2++;
            }
        }
    }
    cout << ans << " "<< ans2 << "\n";

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
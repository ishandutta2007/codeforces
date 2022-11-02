#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5050;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, k;
int n1, n2, n3;
vector<int> g[maxn];
vector<int> A[maxn][2];
int col[maxn];
int u[maxn];
void dfs(int v, int c, int cur) {
    A[cur][c].push_back(v);
    u[v] = 1;
    col[v] = c;
    for(const int &to: g[v]) {
        if(u[to]==0) {
            dfs(to, 1-c, cur);
        }else if(col[to] == c) {
            cout << "NO\n";
            exit(0);
        }
    }
}
int dp[5050][5050];
int pr[5050][5050];
void solve() {
    cin >> n >> k;
    cin >> n1 >> n2 >> n3;
    for(int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int sz = 1;
    for(int i = 1; i <= n; i++) {
        if(u[i]) continue;
        dfs(i, 0, sz);
        sz++;
    }
    dp[0][0] = 1;
    for(int i = 1; i < sz; i++) {
        int x = A[i][0].size();
        int y = A[i][1].size();
        for(int j = 0; j <= n2; j++) {
            if(dp[i-1][j] == 0) continue;
            pr[i][j+x] = j;
            pr[i][j+y] = j;
            dp[i][j+x] = 1;
            dp[i][j+y] = 1;
        }
    }
    if(dp[sz-1][n2] == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = sz-1; i > 0; i--) {
        int x = pr[i][n2];
        if(n2 - x != A[i][0].size()) swap(A[i][0], A[i][1]);
        for(const int &to: A[i][0]) col[to] = 2;
        for(const int &to: A[i][1]) {
            if(n1 > 0) {
                col[to] = 1;
                n1--;
            }else {
                col[to] = 3;
                n3--;
            }
        }
        n2 = x;
    }
    for(int i = 1; i <= n; i++) cout << col[i];
    cout << endl;
}

int main() {
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
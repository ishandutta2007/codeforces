#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)5e5 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
string s;
int n;
vector<int> g[maxn];
vector<int> gr[maxn];
int cur;
int u[maxn];
void dfs(int v, int col) {
    u[v] = col;
    for(int to: g[v]) {
        if(u[to] == -1) {
            dfs(to, col);
        } else if(u[to] != col) {
            cur = 0;
        }
    }
    for(int to: gr[v]) {
        if(u[to] == -1) {
            dfs(to, 1-col);
        } else if(u[to] == col) {
            cur = 0;
        }
    }
}
void clr() {

    for(int i = 0; i < 2 * n; i++) {
        g[i].clear();
        gr[i].clear();
        u[i] = -1;
    }
}
void solve(){
    cin >> s;
    n = s.size();
    if(s[n-1] == '1') {
        cout << 0 << "\n";
        return;
    }
    s[n - 1] = '0';
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        clr();
        for(int j = 1; j < i; j++) {
            if(s[j] == '?') continue;
            if(s[j] == '1') {
                g[0].push_back(j);
                g[j].push_back(0);
            }
            else {
                gr[0].push_back(j);
                gr[j].push_back(0);
            }
        }
        g[n].push_back(0);
        g[0].push_back(n);
        for(int j = i; j < n; j++) {
            g[n+j-i].push_back(n + (n - 1 - i) - (j-i));
            if(s[j] == '?') continue;
            if(s[j] == '1') {
                gr[j].push_back(n+j-i);
                gr[n+j-i].push_back(j);
            } else {
                g[j].push_back(n+j-i);
                g[n+j-i].push_back(j);
            }
        }
        for(int j = 0; j < n; j++) {
            g[j].push_back(n - j - 1);
        }
        cur = 1;
        dfs(0, 1);
        for(int j = 0; j <= n + n - 1 - i; j++) {
            if(u[j] == -1) {
                dfs(j, 0);
                //cout << j << "\n";
                cur = (cur * 2ll) % mod2;
            }
        }
        //cout << cur << " " << i << "\n";
        ans = (ans + cur) % mod2;
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
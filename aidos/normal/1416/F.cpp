#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, q;
int a[maxn];
int good[maxn];
vector<int> g[maxn];
int p[maxn];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};
int u[maxn];
int T;
int b[maxn];
char c[maxn];
bool dfs(int v) {
    if(u[v] == T) return false;
    u[v] = T;
    for(int to: g[v]) {
        if(p[to] == -1) {
            p[to] = v;
            p[v] = to;
            return true;
        }
    }
    for(int to: g[v]) {
        if(good[p[to]] > 0) {
            p[p[to]] = -1;
            p[to] = v;
            p[v] = to;
            return true;
        }
    }
    for(int to: g[v]) {
        if(dfs(p[to])) {
            p[to] = v;
            p[v] = to;
            return true;
        }
    }
    return false;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i * m + j];
            good[i * m + j] = 0;
            g[i * m + j].clear();
            p[i * m + j] = -1;

            u[i * m + j] = 0;
        }
    }
    T=0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && x < n && y >= 0 && y < m) {
                    if(a[i * m + j] > a[x * m + y]) {
                        good[i * m + j] = 1;
                    } else if(a[i * m + j] == a[x * m + y]) {
                        g[i * m + j].emplace_back(x * m + y);
                    }
                }
            }
        }
    }
    vector<int> li;
    for(int i = 0; i < n * m; i++) {
        if(good[i] == 0) {
            li.emplace_back(i);
        }
    }
    while(true) {
        int ok = false;
        T++;
        for(int i = 0; i < li.size(); i++) {
            if(p[li[i]] == -1 && dfs(li[i])) {
                ok = true;
            }
        }
        if(!ok) break;
    }
    for(int i = 0; i < n * m; i++) {
        if(good[i]) continue;
        if(p[i] == -1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n * m; i++) {
        if(p[i] == -1) {
            for(int k = 0; k < 4; k++) {
                int x = i/m +dx[k];
                int y = i % m + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (a[i] > a[x * m + y]) {
                        b[i] = a[i] - a[x * m + y];
                        c[i] = dir[k];
                    }
                }
            }
        } else {
            for(int k = 0; k < 4; k++) {
                int x = i/m +dx[k];
                int y = i % m + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m) {
                    if (a[i] == a[x * m + y] && p[i] == x * m + y) {
                        if(i < x * m + y) {
                            b[i] = 1;
                        } else {
                            b[i] = a[i] - 1;
                        }
                        c[i] = dir[k];
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << b[i * m + j] << " ";
        }
        cout << "\n";
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << c[i * m + j] << " ";
        }
        cout << "\n";
    }
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
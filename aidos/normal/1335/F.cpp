#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
string s[maxn];
string t[maxn];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string d1 = "UDLR";
string d2 = "DURL";
int u[maxn];
int u2[maxn];
int T;
vector<int> cycle;
int cnt[maxn];
int p[maxn];
void dfs(int v, int pa) {
    u[v] = 1;
    int x = v/m;
    int y = v % m;
    p[v] = pa;
    for(int i = 0; i < 4; i++) {
        if(d1[i] != t[x][y]) continue;
        int X = dx[i] + x;
        int Y = dy[i] + y;
        if(X >= 0 && X < n && Y >= 0 && Y < m) {
            int to = X * m + Y;
            if(u[to] == 0) {
                dfs(to, v);
            } else if(u[to] == 1 && cycle.size() == 0) {
                int cur = v;
                while(cur != to) {
                    cycle.emplace_back(cur);
                    cur = p[cur];
                }
                cycle.emplace_back(to);
            }
        }
    }
    u[v] = 2;
}
void dfs2(int v, int len) {
    u2[v] = 1;

    int x = v/m;
    int y = v % m;
    if(s[x][y] == '0') cnt[len % cycle.size()]++;

    for(int i = 0; i < 4; i++) {
        int X = dx[i] + x;
        int Y = dy[i] + y;
        if(X >= 0 && X < n && Y >= 0 && Y < m) {
            if (d2[i] != t[X][Y]) continue;
            int to = X * m + Y;
            if(!u2[to]) {
                dfs2(to, len + 1);
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        if(d1[i] != t[x][y]) continue;
        int X = dx[i] + x;
        int Y = dy[i] + y;
        if(X >= 0 && X < n && Y >= 0 && Y < m) {
            int to = X * m + Y;
            if(!u2[to]) dfs2(to, len + 1);
        }
    }
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < n * m; i++) {
        u[i] = 0;
        u2[i] = 0;
    }

    int ans1 = 0, ans2 = 0;

    for(int i = 0; i < n * m; i++) {
        if(u2[i]) {
            continue;
        }


        cycle.clear();
        dfs(i, -1);
        for(int v: cycle) u2[v] = 1;
        for(int t = 0; t <=  cycle.size(); t++) {
            cnt[t] = 0;
        }
        for(int j = 0; j < cycle.size(); j++) {
            dfs2(cycle[j], j);
        }
        ans1 += cycle.size();
        for(int t = 0; t <= cycle.size(); t++) {
            if(cnt[t] > 0) ans2++;
        }
    }
    cout << ans1 << " "<<ans2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAXN = 205, SIGMA = 26;
char can[MAXN][2], used[MAXN];
int col[MAXN], l;
vector< pair<int, int> > g[MAXN][2];
string c, s;

bool dfs(int v) {
    used[v] = true;
    for(size_t i = 0; i < g[v][col[v]].size(); i++) {
        int u = g[v][col[v]][i].first, cc = g[v][col[v]][i].second;
        if(used[u]) {
            if(col[u] != cc)
                return false;
            continue;
        }
        col[u] = cc;
        if(!dfs(u))
            return false;
    }
    return true;
}

void dfs0(int v) {
    used[v] = true;
    for(size_t i = 0; i < g[v][col[v]].size(); i++) {
        int u = g[v][col[v]][i].first, cc = g[v][col[v]][i].second;
        if(used[u])
            continue;
        col[u] = cc;
        dfs0(u);
    }
}

bool canChange(char cc) {
    cc -= 'a';
    for(int i = cc + 1; i < l; i++)
        if(c[i] != c[cc])
            return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> c >> n >> m;
    l = c.length();
    for(int i = 0; i < m; i++) {
        int v, u;
        char cv, cu;
        cin >> v >> cv >> u >> cu;
        v--;
        u--;
        g[v][cv != c[0]].push_back(make_pair(u, cu != c[0]));
        g[u][cu == c[0]].push_back(make_pair(v, cv == c[0]));
    }
    cin >> s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < n; k++)
                used[k] = false;
            col[i] = j;
            if(dfs(i))
                can[i][j] = true;
        }
    for(int i = 0; i < n; i++)
        if(!can[i][0] && !can[i][1]) {
            cout << -1 << '\n';
            return 0;
        }
    for(int i = 0; i < n; i++)
        used[i] = false;
    int lst = -1;
    bool needChange = false, colChange = false;
    for(int i = 0; i < n; i++) {
        int cur = (c[s[i] - 'a'] != c[0]);
        if(used[i]) {
            if(col[i] != cur) {
                needChange = true;
                if(canChange(s[i])) {
                    colChange = !cur;
                    lst = i;
                }
                break;
            }
            for(int j = s[i] - 'a' + 1; j < l; j++) {
                int cur0 = (c[j] != c[0]);
                if(cur0 == col[i]) {
                    colChange = cur0;
                    lst = i;
                    break;
                }
            }
        }
        else {
            if(can[i][cur]) {
                for(int j = s[i] - 'a' + 1; j < l; j++) {
                    int cur0 = (c[j] != c[0]);
                    if(can[i][cur0]) {
                        colChange = cur0;
                        lst = i;
                        break;
                    }
                }
                col[i] = cur;
                dfs0(i);
            }
            else {
                needChange = true;
                if(canChange(s[i])) {
                    colChange = !cur;
                    lst = i;
                }
                break;
            }
        }
    }
    if(!needChange) {
        cout << s << '\n';
        return 0;
    }
    if(lst == -1) {
        cout << -1 << '\n';
        return 0;
    }
    for(int i = 0; i < n; i++)
        used[i] = false;
    for(int i = 0; i < lst; i++) {
        col[i] = (c[s[i] - 'a'] != c[0]);
        dfs0(i);
    }
    col[lst] = colChange;
    dfs0(lst);
    s[lst]++;
    while(s[lst] < 'a' + l && (c[s[lst] - 'a'] != c[0]) != colChange)
        s[lst]++;
    if(s[lst] == 'a' + l) {
        cout << -1 << '\n';
        return 0;
    }
    char a = 'a', b = 'b';
    while(b < 'a' + l && c[b - 'a'] == c[0])
        b++;
    if(b == 'a' + l) {
        cout << -1 << '\n';
        return 0;
    }
    for(int i = lst + 1; i < n; i++)
        if(used[i])
            s[i] = (col[i]? b : a);
        else {
            if(can[i][0]) {
                col[i] = 0;
                dfs0(i);
                s[i] = a;
            }
            else {
                col[i] = 1;
                dfs0(i);
                s[i] = b;
            }
        }
    cout << s << '\n';
    return 0;
}
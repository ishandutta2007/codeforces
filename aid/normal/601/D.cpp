#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <set>
#include <ctime>

using namespace std;

int P[2];
const int MOD[2] = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9},
    MAXN = 300 * 1000 + 5;
int c[MAXN], ts[MAXN], h[MAXN][2], ans, cnt;
vector<int> g[MAXN];
set< pair<int, int> > *st[MAXN];
string s;

void dfs(int v, int p) {
    ts[v] = 1;
    int maxSon = -1;
    for(size_t i = 0; i < g[v].size(); i++)
        if(g[v][i] != p) {
            for(int j = 0; j < 2; j++)
                h[g[v][i]][j] = ((long long)h[v][j] * P[j] + (s[g[v][i]] - 'a' + 1)) % MOD[j];
            dfs(g[v][i], v);
            ts[v] += ts[g[v][i]];
            if(maxSon == -1 || ts[g[v][i]] > ts[maxSon])
                maxSon = g[v][i];
        }
    if(maxSon == -1) {
        st[v] = new set< pair<int, int> >();
        st[v]->insert(make_pair(h[v][0], h[v][1]));
    }
    else {
        st[v] = st[maxSon];
        for(size_t i = 0; i < g[v].size(); i++)
            if(g[v][i] != p && g[v][i] != maxSon)
                for(set< pair<int, int> >::iterator it = st[g[v][i]]->begin();
                    it != st[g[v][i]]->end(); it++)
                    st[v]->insert(*it);
        st[v]->insert(make_pair(h[v][0], h[v][1]));
    }
    int val = st[v]->size() + c[v];
    if(val > ans) {
        ans = val;
        cnt = 1;
    }
    else if(val == ans)
        cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    P[0] = max(rand() % MOD[0], 131);
    P[1] = max(rand() % MOD[1], 239);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    cin >> s;
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    for(int i = 0; i < 2; i++)
        h[0][i] = (s[0] - 'a' + 1);
    ans = -1;
    cnt = 0;
    dfs(0, -1);
    cout << ans << '\n' << cnt << '\n';
    return 0;
}
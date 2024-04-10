#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 400005;
const int offset = 1 << 19;
const int INF = 0x3f3f3f3f;

int N;
vector <int> E[MAXN];
int disc[MAXN], fin[MAXN];
int sz[MAXN];
int timer = 1;
multiset <int> anc;
int mx[2 * offset];
int ans[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
}

void update(int x, int val) {
    x += offset;
    mx[x] = val;
    for (x /= 2; x; x /= 2)
        mx[x] = max(mx[2 * x], mx[2 * x + 1]);
}

int query(int x, int lo, int hi, int from, int to) {
    if (lo >= to || hi <= from) return 0;
    if (lo >= from && hi <= to) return mx[x];
    int mid = (lo + hi) / 2;
    return max(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
}

int query(int from, int to) {
    return query(1, 0, offset, from, to);
}

void dfs(int x, int p) {
    disc[x] = timer++;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) dfs(E[x][i], x);
    fin[x] = timer;
    sz[x] = fin[x] - disc[x];
}

void go(int x, int p) {
    if (N - sz[x] <= N / 2) anc.insert(N - sz[x]);
    update(disc[x], 0);
    vector <int> tmp, adj;
    for (int i = 0; i < E[x].size(); i++) 
        if (E[x][i] != p) {
            tmp.push_back(sz[E[x][i]]);
            adj.push_back(E[x][i]);
        }
    tmp.push_back(N - sz[x]);
    adj.push_back(p);
    int cnt = 0;
    for (int i = 0; i < tmp.size(); i++)
        cnt += tmp[i] > N / 2;
    if (!cnt) ans[x] = 1;
    else if (cnt == 1) {
        int pos = max_element(tmp.begin(), tmp.end()) - tmp.begin();
        int maks = tmp[pos], node = adj[pos], subtree = 0;
        if (node == p) subtree = max(*anc.rbegin(), max(query(1, disc[x]), query(fin[x], N + 1)));
        else subtree = query(disc[node], fin[node]);
        ans[x] = maks - subtree <= N / 2;
    }
    for (int i = 0; i < (int)adj.size() - 1; i++)
        go(adj[i], x);
    if (N - sz[x] <= N / 2) anc.erase(anc.find(N - sz[x]));
    if (sz[x] <= N / 2) update(disc[x], sz[x]);
}

void solve() {
    dfs(1, 0);
    
    for (int i = 1; i <= N; i++)
        if (sz[i] <= N / 2) update(disc[i], sz[i]);
    
    anc.insert(0);
    go(1, 0);
    
    for (int i = 1; i <= N; i++)
        printf("%d ", ans[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}
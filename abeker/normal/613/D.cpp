#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair <int, int> pii;
typedef set <pii> :: iterator it;

const int MAXN = 100005;
const int LOG = 18;

int N, Q;
vector <int> E[MAXN];
int disc[MAXN], fin[MAXN];
int anc[MAXN][LOG];
int depth[MAXN];
int timer = 1;
bool imp[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
}

void dfs(int x, int p) {
    anc[x][0] = p;
    depth[x] = depth[p] + 1;
    disc[x] = timer++;
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) dfs(E[x][i], x);
    fin[x] = timer;
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = LOG - 1; i >= 0; i--)
        if (diff >> i & 1) a = anc[a][i];
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--)
        if (anc[a][i] != anc[b][i]) {
            a = anc[a][i];
            b = anc[b][i];
        }
    return anc[a][0];
}

pii get(int a, int b) {
    int c = lca(a, b);
    return pii(depth[c], c);
}

void solve() {
    dfs(1, 0);

    for (int j = 1; j < LOG; j++)
        for (int i = 1; i <= N; i++)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];

    scanf("%d", &Q);
    while (Q--) {
        int K;
        scanf("%d", &K);
        vector <int> tmp;
        tmp.resize(K);
        for (int i = 0; i < K; i++)
            scanf("%d", &tmp[i]);
        for (int i = 0; i < K; i++)
            imp[tmp[i]] = true;

        bool adj = false;
        for (int i = 0; i < K; i++)
            adj |= imp[anc[tmp[i]][0]];

        set <pii> nodes;
        for (int i = 0; i < K; i++)
            nodes.insert(pii(disc[tmp[i]], tmp[i]));

        multiset <pii> lcas;
        it j = nodes.begin();
        for (int i = 1; i < K; i++)
            lcas.insert(get((++j) -> second, j -> second));

        int sol = 0;
        while (!lcas.empty()) {
            int curr = lcas.rbegin() -> second;
            it lo = nodes.lower_bound(pii(disc[curr] + 1, 0));
            it hi = nodes.lower_bound(pii(fin[curr], 0));
            if (hi != nodes.end() && lo != nodes.begin()) {
                lcas.insert(get(hi -> second, (--lo) -> second));
                lo++;
            }
            it i = --hi;
            if (++hi != nodes.end()) lcas.erase(lcas.find(get(hi -> second, i -> second)));
            bool f = false;
            vector <pii> todo;
            do {
                f = i == lo;
                todo.push_back(*i);
                if (i != nodes.begin()) lcas.erase(lcas.find(get((--i) -> second, i -> second)));
            } while (!f);
            for (int j = 0; j < todo.size(); j++)
                nodes.erase(todo[j]);
            sol += imp[curr] ? todo.size() : 1;
        }

        if (adj) sol = -1;
        printf("%d\n", sol);

        for (int i = 0; i < K; i++)
            imp[tmp[i]] = false;
    }
}

int main() {
    load();
    solve();
    return 0;
}
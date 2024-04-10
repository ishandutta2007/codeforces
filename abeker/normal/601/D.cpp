#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 300005;
const int BASE1 = 3137;
const int BASE2 = 10007;
const int MOD = 1000000007;

struct fenwick {
    int f[MAXN];
    fenwick() {
        memset(f, 0, sizeof f);
    }
    void update(int x, int val) {
        for (x++; x < MAXN; x += x & -x)
            f[x] += val;
    }
    int get(int x) {
        int ret = 0;
        for (x++; x; x -= x & -x)
            ret += f[x];
        return ret;
    }
    int query(int lo, int hi) {
        return get(hi) - get(lo - 1);
    }
};

int N;
int c[MAXN];
vector <int> E[MAXN];
int disc[MAXN], fin[MAXN];
int node[MAXN];
vector <int> V[MAXN];
char s[MAXN];
pii hash[MAXN];
int timer = 1;
map <pii, int> last;
fenwick F;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", c + i);
    scanf("%s", s + 1);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

inline int add(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

inline int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void dfs(int x, int p) {
    disc[x] = timer++;
    hash[x].first = hash[p].first * BASE1 + s[x];
    hash[x].second = add(mul(hash[p].second, BASE2), s[x]);
    for (int i = 0; i < E[x].size(); i++)
        if (E[x][i] != p) dfs(E[x][i], x);
    fin[x] = timer;
    V[fin[x]].push_back(x);
    node[disc[x]] = x;
}

void solve() {
    dfs(1, 0);
    for (int i = 1; i <= N + 1; i++) {
        for (int j = 0; j < V[i].size(); j++)
            c[V[i][j]] += F.query(disc[V[i][j]], i);
        int &pos = last[hash[node[i]]];
        if (pos) F.update(pos, -1);
        pos = i;
        F.update(pos, 1);
    }
    
    int maks = *max_element(c + 1, c + N + 1);
    int cnt = count(c + 1, c + N + 1, maks);
    printf("%d\n%d\n", maks, cnt);
}

int main() {
    load();
    solve();
    return 0;
}
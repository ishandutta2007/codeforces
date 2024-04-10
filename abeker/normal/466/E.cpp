#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 100005;

struct fenwick {
    int f[MAXN];
    fenwick() {
        memset(f, 0, sizeof f);
    }
    void update(int x, int val) {
        for (; x < MAXN; x += x & -x)
            f[x] += val;
    }
    int get(int x) {
        int ret = 0;
        for (; x; x -= x & -x)
            ret += f[x];
        return ret;
    }
};

int N, M;
vector <int> ch[MAXN];
int t[MAXN], x[MAXN], y[MAXN];
vector <int> V;
vector <int> Q[MAXN];
bool flag[MAXN];
int disc[MAXN], fin[MAXN];
int depth[MAXN];
int timer = 1;
bool sol[MAXN];
fenwick F;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d", t + i, x + i);
        if (t[i] != 2) scanf("%d", y + i);
    }
}

void dfs(int x, int d) {
    disc[x] = timer++;
    depth[x] = d;
    for (int i = 0; i < ch[x].size(); i++)
        dfs(ch[x][i], d + 1);
    fin[x] = timer;
}

bool check(int a, int b) {
    if (disc[b] < disc[a] || disc[b] >= fin[a])
        return false;
    return F.get(disc[b]) - F.get(disc[a]) == depth[b] - depth[a];
}

void solve() {
    for (int i = 0; i < M; i++) 
        if (t[i] == 1) {
            ch[y[i]].push_back(x[i]);
            flag[x[i]] = true;
        }
        else if (t[i] == 2) V.push_back(i);
        else if (t[i] == 3) Q[V[--y[i]]].push_back(i);
    
    for (int i = 1; i <= N; i++) 
        if (!flag[i]) dfs(i, 0);
    
    for (int i = 0; i < M; i++) 
        if (t[i] == 1) {
            F.update(disc[x[i]], 1);
            F.update(fin[x[i]], -1);
        }
        else if (t[i] == 2)
            for (int j = 0; j < Q[i].size(); j++) 
                sol[Q[i][j]] = check(x[Q[i][j]], x[i]);
    
    for (int i = 0; i < M; i++)
        if (t[i] == 3) puts(sol[i] ? "YES" : "NO");
}

int main() {
    load();
    solve();
    return 0;
}
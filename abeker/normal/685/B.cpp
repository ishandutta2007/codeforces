#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 300005;

int N, M;
vector <int> ch[MAXN];
int centroid[MAXN];
int disc[MAXN];
int subtree[MAXN], maks[MAXN];
vector <pii> path;
vector <pii> Q[MAXN];
set <pii> S;
int timer = 1;

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 2; i <= N; i++) {
        int parent;
        scanf("%d", &parent);
        ch[parent].push_back(i);
    }
}

int dfs(int x) {
    disc[x] = timer++;
    subtree[x] = 1;
    for (int i = 0; i < ch[x].size(); i++) {
        int nxt = dfs(ch[x][i]);
        maks[x] = max(maks[x], nxt);
        subtree[x] += nxt;
    }
    return subtree[x];
}

int get(int sz) {
    return lower_bound(path.begin(), path.end(), pii(-sz, 0)) - path.begin(); 
}

void go(int x) {
    path.push_back(pii(-subtree[x], x));   
    for (int i = 0; i < ch[x].size(); i++) 
        go(ch[x][i]);
    int lo = path[get(2 * subtree[x])].second;
    int pos = get(2 * maks[x] - 1);
    if (pos) {
        int hi = path[pos - 1].second;
        Q[lo].push_back(pii(disc[hi], x));
    }
    path.pop_back();
}

void finish(int x) {
    for (int i = 0; i < Q[x].size(); i++)
        S.insert(Q[x][i]);
    centroid[x] = S.lower_bound(pii(disc[x], 0)) -> second; 
    for (int i = 0; i < ch[x].size(); i++)
        finish(ch[x][i]);
    for (int i = 0; i < Q[x].size(); i++)
        S.erase(Q[x][i]);
}

void solve() {
    dfs(1);
    go(1); 
    finish(1);
    while (M--) {
        int v;
        scanf("%d", &v);
        printf("%d\n", centroid[v]);
    }
}

int main() {
    load();
    solve();
    return 0;
}
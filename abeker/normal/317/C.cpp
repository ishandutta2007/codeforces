#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 305;

struct trans {
    int x, y, d;
    trans(int x, int y, int d) : x(x), y(y), d(d) {}
    trans() : x(0), y(0), d(0) {}
};

int N, V, M;
vector <int> E[MAXN];
int a[MAXN], b[MAXN];
vector <pii> tmp;
vector <trans> ans;
bool bio[MAXN], was[MAXN];
bool todo[MAXN];
vector <int> nodes;
int who;

void load() {
    scanf("%d%d%d", &N, &V, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= N; i++)
        scanf("%d", b + i);
    while (M--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);
        tmp.push_back(pii(x, y));
    }
}

void dfs(int x) {
    bio[x] = true;
    bool f = false;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (bio[nxt]) continue;
        dfs(nxt);
        f = true;
    }
    if (!f) who = x;
}

void apply(int u, int v, int w) {
    ans.push_back(trans(u, v, w));
    a[u] -= w;
    a[v] += w;
}

void go(int x, bool f) {
    was[x] = true;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i];
        if (was[nxt]) continue;
        go(nxt, f);
        int u = x, v = nxt;
        if (f) swap(u, v);
        int w = min(a[u], V - a[v]);
        if (x == who) w = min(w, abs(a[x] - b[x]));
        apply(u, v, w);
    }
}

void output() {
    printf("a ");
    for (int i = 1; i <= N; i++)
        printf("%d ", a[i]);
    puts("");
    printf("b ");
    for (int i = 1; i <= N; i++)
        printf("%d ", b[i]);
    puts("");
}

void op() {
    for (int i = 0; i < nodes.size(); i++) {
        printf("%d: ", nodes[i]);
        for (int j = 0; j < E[nodes[i]].size(); j++)
            printf("%d ", E[nodes[i]][j]);
        puts("");
    }
}

void solve() {
    sort(tmp.begin(), tmp.end());
    tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    for (int i = 0; i < tmp.size(); i++) {
        E[tmp[i].first].push_back(tmp[i].second);
        E[tmp[i].second].push_back(tmp[i].first);
    }
    
    for (int i = 1; i <= N; i++)
        nodes.push_back(i);
            
    while (!nodes.empty()) {
        memset(bio, false, sizeof bio);
        memset(was, false, sizeof was);
        for (int i = 0; i < nodes.size(); i++) {
            int curr = nodes[i];
            if (bio[curr]) continue;
            dfs(curr);            
            todo[who] = true;
            if (a[who] != b[who])
                go(who, a[who] < b[who]);
        }
        
        vector <int> nxt;
        for (int i = 0; i < nodes.size(); i++)
            if (!todo[nodes[i]]) nxt.push_back(nodes[i]);
        nodes = nxt;
        for (int i = 0; i < nodes.size(); i++) {
            vector <int> t;
            for (int j = 0; j < E[nodes[i]].size(); j++)
                if (!todo[E[nodes[i]][j]]) 
                    t.push_back(E[nodes[i]][j]);
            E[nodes[i]] = t;                   
        }
    }
    
    bool ok = true;
    for (int i = 1; i <= N; i++)
        ok &= a[i] == b[i];
    
    if (!ok) {
        puts("NO");
        return;
    }
    
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].d);
}

int main() {
    load();
    solve();
    return 0;
}
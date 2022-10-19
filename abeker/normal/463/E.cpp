#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int MAXM = 2000005;

int N, Q;
int a[MAXN];
vector <int> E[MAXN];
int disc[MAXN], fin[MAXN];
int node[MAXN], depth[MAXN];
int parent[MAXN];
int timer = 1;

int sol[MAXN]; // pamtimo po discovery timeu

int spf[MAXM];

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXM; i++) 
        for (int j = i; j < MAXM; j += i)
            if (!spf[j]) spf[j] = i;
}

vector <int> factor(int x) {
    vector <int> res;
    while (x > 1) {
        int tmp = spf[x];
        res.push_back(tmp);
        while (!(x % tmp)) x /= tmp;
    }
    return res;
}

void load() {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++) 
        scanf("%d", a + i);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

vector <int> last[MAXM];

void dfs(int x, int p, int d) {   
    parent[x] = p;
    disc[x] = timer++;
    depth[x] = d;
    node[disc[x]] = x;
    
    vector <int> tmp = factor(a[x]); 
       
    for (int i = 0; i < tmp.size(); i++) {
        if (last[tmp[i]].empty()) continue;
        if (depth[last[tmp[i]].back()] > depth[sol[disc[x]]]) 
            sol[disc[x]] = last[tmp[i]].back();
    }
    
    for (int i = 0; i < tmp.size(); i++) 
        last[tmp[i]].push_back(x);
    
    for (int i = 0; i < E[x].size(); i++) 
        if (E[x][i] != p) dfs(E[x][i], x, d + 1);
    
    for (int i = 0; i < tmp.size(); i++) 
        last[tmp[i]].pop_back();
    fin[x] = timer;
}

int best[MAXM];

inline void update(int v, int w) {
    a[v] = w;
    for (int x = parent[v]; x; x = parent[x]) {
        vector <int> tmp = factor(a[x]);
        for (int i = 0; i < tmp.size(); i++) 
            if (!best[tmp[i]]) best[tmp[i]] = x;
    }
    for (int i = disc[v]; i < fin[v]; i++) {
        if (depth[sol[i]] > depth[v]) continue;
        sol[i] = 0;
        vector <int> tmp = factor(a[node[i]]);
        for (int j = 0; j < tmp.size(); j++)
            if (depth[sol[i]] < depth[best[tmp[j]]]) 
                sol[i] = best[tmp[j]];
        if (i == disc[v])
            for (int j = 0; j < tmp.size(); j++) 
                best[tmp[j]] = v;
    }
    for (int x = v; x; x = parent[x]) {
        vector <int> tmp = factor(a[x]);
        for (int i = 0; i < tmp.size(); i++) 
            best[tmp[i]] = 0;
    }
}

void farewell() {
    for (int i = 1; i <= N; i++) 
        assert(!sol[disc[i]] || __gcd(a[sol[disc[i]]], a[i]) > 1);
}

void solve() {
    dfs(1, 0, 1);
    while (Q--) {
        int t, v, w;
        scanf("%d%d", &t, &v);
        if (t == 1) printf("%d\n", sol[disc[v]] ? sol[disc[v]] : -1);
        else { scanf("%d", &w); update(v, w); } 
        //farewell();
    }
}

void output(const vector <int> &V) {
    for (int i = 0; i < V.size(); i++) 
        printf("%d ", V[i]);
    puts("");
}

int main() {
    load();
    sieve();
    solve();
    return 0;
}
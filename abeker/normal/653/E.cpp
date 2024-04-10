#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 300005;

int N, M, K;
set <pii> S;
int deg[MAXN];
int comp[MAXN];
vector <int> rest, adj;
bool ok[MAXN];
bool conn[MAXN];
bool bio[MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &K);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        S.insert(pii(a, b));
        S.insert(pii(b, a));
        deg[a]++;
        deg[b]++;
    }
}

void dfs(int x, int c) {
    comp[x] = c;
    for (int i = 0; i < rest.size(); i++)
        if (!S.count(pii(x, rest[i])) && !comp[rest[i]])
            dfs(rest[i], c);
}

void go(int x, bool one) {
    bio[x] = true;
    for (int i = 1 + !one; i <= N; i++)
        if (!bio[i] && !S.count(pii(x, i)))
            go(i, one);
}

bool brute() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (bio[i]) continue;
        go(i, 1);
        cnt++;
    }
    if (cnt > 1) return false;
    memset(bio, false, sizeof bio);
    cnt = 0;
    for (int i = 2; i <= N; i++) {
        if (bio[i]) continue;
        go(i, 0);
        cnt++;
    }
    return cnt <= K;
}

bool solve() {
    for (int i = 1; i <= N; i++)
        deg[i] = N - 1 - deg[i];
    
    if (deg[1] < K) return false;
    
    if (N < 1000) return brute();
    
    int best = max_element(deg + 2, deg + N + 1) - deg;
    for (int i = 2; i <= N; i++)
        if (S.count(pii(best, i))) 
            rest.push_back(i);
        else {
            adj.push_back(i);
            comp[i] = best;
        }
    
    vector <int> roots;
    for (int i = 0; i < rest.size(); i++) {
        if (comp[rest[i]]) continue;
        roots.push_back(rest[i]);
        dfs(rest[i], rest[i]);
    }
    
    for (int i = 2; i <= N; i++)
        if (!S.count(pii(1, i))) 
            ok[comp[i]] = true;
            
    for (int i = 0; i < rest.size(); i++)
        for (int j = 0; j < adj.size(); j++)
            if (!S.count(pii(rest[i], adj[j]))) 
                conn[comp[rest[i]]] = true;
    
    int tot = 1;
    bool good = ok[best];
    for (int i = 0; i < roots.size(); i++)
        if (!conn[roots[i]]) {
            if (!ok[roots[i]]) return false;
            tot++;
        }
        else good |= ok[roots[i]];
    
    return good && tot <= K;
}

int main() {
    load();
    puts(solve() ? "possible" : "impossible");
    return 0;
}
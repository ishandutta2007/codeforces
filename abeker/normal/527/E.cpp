#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 100005;

int N, M;
vector < pii > E[MAXN];
vector < pii > sol;
vector <int> odd;
int in[MAXN];
bool bio[MAXN];

void add(int a, int b) {
    E[a].push_back(pii(b, sol.size()));
    E[b].push_back(pii(a, sol.size()));
    sol.push_back(pii(a, b));
    in[b]++;
}

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
}

int dfs(int x) {
    bio[x] = true;
    int res = in[x] % 2;
    for (int i = 0; i < E[x].size(); i++) {
        int nxt = E[x][i].first;
        int idx = E[x][i].second;
        if (bio[nxt]) continue;
        int tmp = dfs(nxt);
        if (tmp) swap(sol[idx].first, sol[idx].second);
        res ^= tmp;
    }
    return res;
}

void solve() {
    
    for (int i = 1; i <= N; i++)
        if (E[i].size() & 1) odd.push_back(i);
        
    for (int i = 0; i < odd.size(); i += 2)
        add(odd[i], odd[i + 1]);
    
    if (sol.size() % 2) add(1, 1);
    
    for (int i = 1; i <= N; i++)
        if (!bio[i]) dfs(i);
    
    printf("%d\n", sol.size());
    for (int i = 0; i < sol.size(); i++)
        printf("%d %d\n", sol[i].first, sol[i].second);
}

int main() {
    load();
    solve();
    return 0;
}
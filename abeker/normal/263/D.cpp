#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N, M, K;
vector <int> E[MAXN];

void load() {
    scanf("%d%d%d", &N, &M, &K);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

int disc[MAXN];
int node[MAXN];
int timer;

void finish(int lo, int hi) {
    printf("%d\n", hi - lo + 1);
    for (int i = lo; i <= hi; i++) 
        printf("%d ", node[i]);
    printf("\n");
    exit(0);
}

void dfs(int x) {
    disc[x] = ++timer;
    node[disc[x]] = x;
    for (vector <int> :: iterator it = E[x].begin(); it != E[x].end(); it++) 
        if (!disc[*it])
            dfs(*it);
        else if (disc[x] - disc[*it] >= K)
            finish(disc[*it], disc[x]);
}

int main() {
    load();
    dfs(1);
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

struct edge {
    int a, b, c, id;
    edge(int a, int b, int c, int id) : a(a), b(b), c(c), id(id) {}
    edge() : a(0), b(0), c(0), id(0) {}
    bool operator <(const edge &rhs) const {
        return c < rhs.c;
    }
};

int N, M;
vector <edge> adj[MAXN];
edge E[MAXN];
vector <int> comp[MAXN];
int dad[MAXN];
int w[MAXN];
ll mst;

int find(int x) {
    return x == dad[x] ? x : dad[x] = find(dad[x]);
}

void join(edge curr) {
    int x = find(curr.a);
    int y = find(curr.b);
    if (x == y) return;
    mst += (ll)curr.c;
    if (comp[x].size() > comp[y].size()) swap(x, y);
    for (int i = 0; i < comp[x].size(); i++) {
        int node = comp[x][i];
        comp[y].push_back(node);
        for (int j = 0; j < adj[node].size(); j++) {
            edge tmp = adj[node][j];
            int to = tmp.a + tmp.b - node;
            if (find(to) == y) w[tmp.id] -= curr.c;
        }
    }
    dad[x] = y;
}

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &E[i].a, &E[i].b, &E[i].c);
        w[i] = E[i].c;
        E[i].id = i;
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        adj[E[i].a].push_back(E[i]);
        adj[E[i].b].push_back(E[i]);
    }
    
    for (int i = 1; i <= N; i++) {
        dad[i] = i;
        comp[i].push_back(i);
    }
    
    sort(E, E + M);
    for (int i = 0; i < M; i++) 
        join(E[i]);
    
    for (int i = 0; i < M; i++)
        printf("%I64d\n", mst + (ll)w[i]);
}

int main() {
    load();
    solve();
    return 0;
}
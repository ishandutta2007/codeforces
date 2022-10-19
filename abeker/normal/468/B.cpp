#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 100005;

int N, A, B;
int p[MAXN];
int a[MAXN], b[MAXN];
bool bio[MAXN], sol[MAXN];
map <int, int> pos;
vector <int> V;

void load() {
    scanf("%d%d%d", &N, &A, &B);
    for (int i = 0; i < N; i++)
        scanf("%d", p + i);
}

void dfs(int x) {
    bio[x] = true;
    V.push_back(x);
    if (a[x] != -1 && !bio[a[x]]) dfs(a[x]);
    if (b[x] != -1 && !bio[b[x]]) dfs(b[x]);
}

void bye() {
    puts("NO");
    exit(0);
}

void solve() {
    for (int i = 0; i < N; i++)
        pos[p[i]] = i + 1;
    
    for (int i = 0; i < N; i++) {
        a[i] = pos[A - p[i]] - 1;
        b[i] = pos[B - p[i]] - 1;
        if (a[i] == -1 && b[i] == -1) bye();
    }
    
    for (int i = 0; i < N; i++) {
        if (bio[i]) continue;
        V.clear();
        dfs(i);
        bool ac = false, bc = false;
        for (int j = 0; j < V.size(); j++) {
            if (a[V[j]] == -1) ac = true;
            if (b[V[j]] == -1) bc = true;
        }
        if (ac && bc) bye();
        for (int j = 0; j < V.size(); j++)
            sol[V[j]] = ac;
    }
    
    puts("YES");
    for (int i = 0; i < N; i++)
        printf("%d ", (int)sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}
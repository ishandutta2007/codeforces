#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 100005;

int N, M;
vector <int> v[MAXN], ch[MAXN], path; 
bool bio[MAXN];
int c[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    while (M--) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) 
        scanf("%d", c + i);
}

void dfs(int x) {
    bio[x] = 1;
    for (int i = 0; i < v[x].size(); i++) 
        if (!bio[v[x][i]]) {
            ch[x].push_back(v[x][i]);
            dfs(v[x][i]);
        }
}

void visit(int x) {
    c[x] ^= 1;
    path.push_back(x);
}

void go(int x, int p) {
    visit(x);
    for (int i = 0; i < ch[x].size(); i++) { 
        go(ch[x][i], x);
        visit(x);
    }
    if (!c[x]) return;
    if (!p) {
        visit(ch[x][0]);
        visit(x);
        visit(ch[x][0]);
    } 
    else {
        visit(p);
        visit(x);
    }
}

void solve() {
    int start = 0;
    for (int i = 1; i <= N; i++)
        if (c[i]) start = i;
    if (!start) {
        puts("0");
        return;
    }
    dfs(start);
    for (int i = 1; i <= N; i++) 
        if (!bio[i] && c[i]) {
            puts("-1");
            return;
        }
    go(start, 0);
    printf("%d\n", path.size());
    for (int i = 0; i < path.size(); i++) 
        printf("%d ", path[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}
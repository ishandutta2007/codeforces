#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 200005;

int N;
int x[MAXN], y[MAXN];
set <int> E[2 * MAXN + 1];
map <pii, char> sol;
bool bio[2 * MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", x + i, y + i);
        y[i] += MAXN;
    }
}

void euler(int node) {
    bio[node] = true;
    while (!E[node].empty()) {
        int nxt = *E[node].begin();
        E[node].erase(nxt);
        E[nxt].erase(node);
        if (node < MAXN) sol[pii(node, nxt)] = 'r';
        else sol[pii(nxt, node)] = 'b';
        euler(nxt);
    }
}

void add(int a, int b) {
    E[a].insert(b);
    E[b].insert(a);
}

void solve() {
    for (int i = 0; i < N; i++) 
        add(x[i], y[i]);
    for (int i = 0; i < 2 * MAXN; i++)
        if (E[i].size() & 1) add(i, 2 * MAXN);
    for (int i = 0; i < N; i++)
        if (!bio[x[i]]) euler(x[i]);
    for (int i = 0; i < N; i++)
        printf("%c", sol[pii(x[i], y[i])]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}
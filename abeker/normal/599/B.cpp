#include <cstdio>
using namespace std;

const int MAXN = 100005;

int N, M;
int f[MAXN], b[MAXN];
int inv[MAXN];
bool flag[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", f + i);
    for (int i = 0; i < M; i++)
        scanf("%d", b + i);
}

void solve() {
    for (int i = 1; i <= N; i++) {
        if (inv[f[i]]) flag[f[i]] = true; 
        inv[f[i]] = i;
    }
    bool amb = false;
    for (int i = 0; i < M; i++) {
        if (!inv[b[i]]) {
            puts("Impossible");
            return;
        }
        amb |= flag[b[i]];
    }
    
    if (amb) {
        puts("Ambiguity");
        return;
    }
    
    puts("Possible");
    for (int i = 0; i < M; i++)
        printf("%d ", inv[b[i]]);
    puts("");
}
 
int main() {
    load();
    solve();
    return 0;
}
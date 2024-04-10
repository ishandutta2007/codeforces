#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

int N;
int a[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) 
        scanf("%d", a + i);
}

pair <int, int> p[MAXN];

void compress() {
    for (int i = 0; i < N; i++) 
        p[i] = make_pair(a[i], i);
    sort(p, p + N);
    for (int i = 0; i < N; i++) 
        a[p[i].second] = i;
}
    
void solve() {
    int lo, hi;
    for (lo = 0; lo < N; lo++) 
        if (a[lo] != lo) break;
    if (lo == N) { printf("yes\n1 1\n"); return; }
    for (hi = N - 1; hi >= 0; hi--) 
        if (a[hi] != hi) break;
    reverse(a + lo, a + hi + 1);
    bool ok = true;
    for (int i = 0; i < N; i++) 
        ok &= a[i] == i;
    if (ok) printf("yes\n%d %d\n", lo + 1, hi + 1);
    else puts("no");
}

int main() {
    load();
    compress();
    solve();
    return 0;
}
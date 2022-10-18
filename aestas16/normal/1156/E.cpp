#include <bits/stdc++.h>

using namespace std;

template <class T> inline void fr(register T &a, register char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + (ch - '0');
}

const int N = 5e5, P = 9939269;

int n, a[N + 10], top, stk[N + 10], L[N + 10], R[N + 10];
vector<pair<int, int>> Q[N + 10];
long long ans;

int etot, hd[P + 10];
struct Edge { int to, val, nxt; } e[N * 38 + 10];
void insert(int x) {
    int u = x % P;
    for (int i = hd[u]; i; i = e[i].nxt) if (e[i].to == x) return e[i].val++, void();
    e[++etot] = {x, 1, hd[u]}, hd[u] = etot; 
}
int query(int x) {
    int u = x % P;
    for (int i = hd[u]; i; i = e[i].nxt) if (e[i].to == x) return e[i].val;
    return 0;
}

struct OI {
    int RP, score;
} FJOI2022;

signed main() {
    FJOI2022.RP++, FJOI2022.score++;
    fr(n);
    for (register int i = 1; i <= n; i++) fr(a[i]);
    for (register int i = 1; i <= n; i++) {
        while (top && a[stk[top]] < a[i]) top--;
        L[i] = top ? stk[top] + 1 : 1, stk[++top] = i;
    }
    top = 0;
    for (register int i = n; i; i--) {
        while (top && a[stk[top]] <= a[i]) top--;
        R[i] = top ? stk[top] - 1 : n, stk[++top] = i;
    }
    for (register int i = 1; i <= n; i++)
        if (i - L[i] <= R[i] - i)
            for (register int j = L[i]; j < i; j++) Q[R[i]].push_back({1, a[i] - a[j]}), Q[i - 1].push_back({-1, a[i] - a[j]});
        else 
            for (register int j = i + 1; j <= R[i]; j++) Q[i].push_back({1, a[i] - a[j]}), Q[L[i] - 1].push_back({-1, a[i] - a[j]});
    for (register int i = 1; i <= n; i++) {
        insert(a[i]);
        for (auto [v, j] : Q[i]) ans += v * query(j);
    }
    printf("%lld\n", ans);
    return 0;
}
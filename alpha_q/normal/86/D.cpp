#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int INF = 1e9 + 10;
int SQRT;

struct query {
    int l, r, id;
    bool operator < (const query &q) const {
        if (l/SQRT == q.l/SQRT) return r < q.r;
        return l/SQRT < q.l/SQRT;
    }
};

query q[N];
int n, m, cnt[N];
long long a[N], result[N], ans = 0;

void add (int pos) {
    if (a[pos] > N) return;
    ans += a[pos] * (cnt[a[pos]] + cnt[a[pos]] + 1);
    cnt[a[pos]]++;
}

void remove (int pos) {
    if (a[pos] > N) return;
    ans -= a[pos] * (cnt[a[pos]] + cnt[a[pos]] - 1);
    cnt[a[pos]]--;
}

int main (int argc, char const *argv[]) {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE

    a[0] = INF;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%I64d", a + i);
    for (int i = 1; i <= m; ++i) scanf("%d %d", &q[i].l, &q[i].r), q[i].id = i;

    SQRT = sqrt(n);
    sort (q + 1, q + m + 1);

    int l = 0, r = 0;
    for (int i = 1; i <= m; ++i) {
        while (l > q[i].l) add(--l);
        while (r < q[i].r) add(++r);
        while (l < q[i].l) remove(l++);
        while (r > q[i].r) remove(r--);
        result[q[i].id] = ans;
    }

    for (int i = 1; i <= m; ++i) printf("%I64d\n", result[i]);
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 200005;
const int MAXM = 500005;

int N, Q;
int a[MAXN], c[MAXN];
int p[MAXM];
int cnt[MAXM];
int tot;
ll sol;

void init() {
    for (int i = 2; i < MAXM; i++) {
        if (p[i]) continue;
        for (int j = i; j < MAXM; j += i)   
            if (!p[j]) p[j] = i;
    }
}

void load() {
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", a + i);   
        c[i] = 1;
    }
}

ll query(int x) {
    tot += c[x];
    vector <int> V;
    for (int t = a[x]; t > 1; t /= p[t])  
        V.push_back(p[t]);
    V.resize(unique(V.begin(), V.end()) - V.begin());
    int sz = V.size();
    for (int i = 1; i < 1 << sz; i++) {
        int num = 1;
        for (int j = 0; j < sz; j++)
            if (i >> j & 1) num *= V[j];
        sol += (ll)(__builtin_popcount(i) & 1 ? 1 : -1) * (1 + c[x] * (2 * cnt[num] - 1)) / 2;
        cnt[num] += c[x];
    }
    c[x] = -c[x];     
    return (ll)tot * (tot - 1) / 2 - sol;
}

void solve() {
    while (Q--) {
        int x;
        scanf("%d", &x);
        printf("%I64d\n", query(x));      
    }
}

int main() {
    init();
    load();
    solve();
    return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const int MAXK = 15;

struct fenwick {
    ll f[MAXN];
    fenwick() {
        memset(f, 0, sizeof f);
    }
    void update(int x, ll val) {
        for (++x; x < MAXN; x += x & -x)
            f[x] += val;
    }
    ll get(int x) {
        ll ret = 0;
        for (++x; x; x -= x & -x)
            ret += f[x];
        return ret;
    }
};

int N, K;
int a[MAXN];
fenwick F[MAXK];
ll dp[MAXK];

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

ll solve() {
    K++;
    F[0].update(0, 1);
    ll sol = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++)
            dp[j] = F[j - 1].get(a[i] - 1);
        for (int j = 1; j <= K; j++)
            F[j].update(a[i], dp[j]);
        sol += dp[K];
    }
    return sol;
}

int main() {
    load();
    cout << solve() << endl;
    return 0;
}
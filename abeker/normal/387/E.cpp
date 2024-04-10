#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;

const int MAXN = 1000005;

struct fenwick {
    int f[MAXN];
    fenwick() {
        memset(f, 0, sizeof f);
    }
    void update(int x) {
        for (; x < MAXN; x += x & -x)
            f[x]++;
    }
    int get(int x) {
        int ret = 0;
        for (; x; x -= x & -x)  
            ret += f[x];
        return ret;
    }
    int query(int lo, int hi) {
        return get(hi) - get(lo - 1);
    }
};

int N, K;
int pos[MAXN];
bool b[MAXN];
set <int> S;
fenwick F;

int input() {
    int x;
    scanf("%d", &x);
    return x;
}

void load() {
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++)
        pos[input()] = i;
    while (K--) 
        b[input()] = true;
}

ll solve() {
    ll sol = 0;
    S.insert(0);
    S.insert(N + 1);
    for (int i = 1; i <= N; i++) {
        if (b[i]) {
            S.insert(pos[i]); 
            continue;
        }
        set <int> :: iterator it = S.lower_bound(pos[i]);
        int hi = *it, lo = *(--it);
        sol += (ll)(hi - lo - 1 - F.query(lo + 1, hi - 1));
        F.update(pos[i]);
    }
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}
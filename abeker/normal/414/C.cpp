#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

const int MAXN = 21;

struct fenwick {
    int sz;
    int f[1 << MAXN];
    fenwick() {
        sz = 0;
        memset(f, 0, sizeof f);
    }
    void update(int x, int val) {
        sz += val;
        for (++x; x < 1 << MAXN; x += x & -x)
            f[x] += val;
    }
    int pref(int x) {
        int ret = 0;
        for (++x; x; x -= x & -x)
            ret += f[x];
        return ret;
    }
    int suff(int x) {
        return sz - pref(x);
    }
};

int N, M, K;
int a[1 << MAXN];
vector <int> V;
ll x[MAXN], y[MAXN];
fenwick F;

void load() {
    scanf("%d", &N);
    K = 1 << N;
    for (int i = 0; i < K; i++)
        scanf("%d", a + i);
}

void solve() {
    for (int i = 0; i < K; i++)
        V.push_back(a[i]);
    sort(V.begin(), V.end());
    for (int i = 0; i < K; i++)
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin();
    
    for (int i = 0; i <= N; i++) 
        for (int j = K - 1; j >= 0; j--) {
            x[i] += (ll)F.pref(a[j] - 1);
            y[i] += (ll)F.suff(a[j]);
            F.update(a[j], 1); 
            if (!((K - j) % (1 << i)))
                for (int k = 0; k < 1 << i; k++)
                    F.update(a[j + k], -1);
        } 
    
    scanf("%d", &M);
    while (M--) {
        int q;
        scanf("%d", &q);
        for (int i = q + 1; i <= N; i++) {
            x[i] += y[q] - x[q];
            y[i] += x[q] - y[q];
        }
        for (int i = 0; i <= q; i++)
            swap(x[i], y[i]);
        printf("%I64d\n", x[N]);
    }
}

int main() {
    load();
    solve();
    return 0;
}
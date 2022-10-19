#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 200005;
const int offset = 1 << 18;

struct tournament {
    int t[2 * offset];
    tournament() {
        for (int i = 0; i < offset; i++) 
            t[i + offset] = 1;
        for (int i = offset - 1; i >= 0; i--)
            t[i] = t[2 * i] + t[2 * i + 1];
    }
    void update(int pos) {
        pos += offset;
        t[pos] = 0;
        for (pos /= 2; pos; pos /= 2) 
            t[pos] = t[2 * pos] + t[2 * pos + 1];
    }
    int query(int x, int lo, int hi, int pos) {
        if (hi - lo == 1) return lo;
        int mid = (lo + hi) / 2;
        if (t[2 * x] >= pos) return query(2 * x, lo, mid, pos);
        return query(2 * x + 1, mid, hi, pos - t[2 * x]);
    }
};

struct fenwick {
    int f[MAXN];
    fenwick() {
        memset(f, 0, sizeof f);
    }
    void update(int x) {
        for (++x; x < MAXN; x += x & -x)
            f[x]++;
    }
    int get(int x) {
        int ret = 0;
        for (++x; x; x -= x & -x)
            ret += f[x];
        return ret;
    }
};

int N;
int p[MAXN], q[MAXN];
int idx[MAXN];
fenwick P, Q;
tournament T;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", p + i);
    for (int i = 0; i < N; i++) 
        scanf("%d", q + i);
}

void solve() {
    for (int i = N - 1; i >= 0; i--) {
        idx[i] += P.get(p[i]) + Q.get(q[i]); 
        if (i) idx[i - 1] += idx[i] / (N - i);
        idx[i] %= N - i;
        P.update(p[i]);
        Q.update(q[i]);
    }
    for (int i = 0; i < N; i++) {
        int sol = T.query(1, 0, offset, idx[i] + 1);
        printf("%d ", sol);
        T.update(sol);
    }
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}
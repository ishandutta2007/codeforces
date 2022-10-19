#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 500005;
const int offset = 1 << 19;

struct tournament1 {
    int t[2 * offset];
    tournament1() {
        memset(t, 0, sizeof t);
    }
    void update(int x, int val) {
        x += offset;
        t[x] = val;
        for (x /= 2; x; x /= 2)
            t[x] = max(t[2 * x], t[2 * x + 1]);
    }
    int query(int x, int lo, int hi, int from, int to) {
        if (lo >= to || hi <= from) return 0;
        if (lo >= from && hi <= to) return t[x];
        int mid = (lo + hi) / 2;
        return max(query(2 * x, lo, mid, from, to), query(2 * x + 1, mid, hi, from, to));
    }
};

struct tournament2 {
    int t[2 * offset];
    tournament2() {
        memset(t, 0, sizeof t);
    }
    void update(int x, int lo, int hi, int from, int to, int val) {
        if (lo >= to || hi <= from) return;
        if (lo >= from && hi <= to) {
            t[x] = max(t[x], val);
            return;
        }
        int mid = (lo + hi) / 2;
        update(2 * x, lo, mid, from, to, val);
        update(2 * x + 1, mid, hi, from, to, val);
    }
    int query(int x) {
        int res = 0;
        for (x += offset; x; x /= 2)
            res = max(res, t[x]);
        return res;
    }
};

int N, Q;
vector <int> E[MAXN];
int disc[MAXN], fin[MAXN];
int timer = 1;
tournament1 T1;
tournament2 T2;

void load() {
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
}

void dfs(int x, int p) {
    disc[x] = timer++;
    for (int i = 0; i < E[x].size(); i++) 
        if (E[x][i] != p) dfs(E[x][i], x);
    fin[x] = timer;
}

void solve() {
    dfs(1, 0);
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        int c, v;
        scanf("%d%d", &c, &v);
        if (c == 1) T2.update(1, 0, offset, disc[v], fin[v], i);
        else if (c == 2) T1.update(disc[v], i);
        else printf("%d\n", T1.query(1, 0, offset, disc[v], fin[v]) < T2.query(disc[v]));
    }
}

int main() {
    load();
    solve();
    return 0;
}
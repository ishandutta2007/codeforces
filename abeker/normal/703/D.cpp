#include <cstdio>
#include <vector>
#include <map>
using namespace std;

const int MAXN = 1000005;

int N, M;
int a[MAXN], pref[MAXN];
int l[MAXN], r[MAXN];
vector <int> Q[MAXN];
map <int, int> last;
int f[MAXN];
int ans[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
        scanf("%d%d", l + i, r + i);
}

void update(int x, int val) {
    for (x++; x < MAXN; x += x & -x)
        f[x] ^= val;
}

int get(int x) {
    int ret = 0;
    for (x++; x; x -= x & -x)
        ret ^= f[x];
    return ret;
}

int query(int lo, int hi) {
    return get(lo - 1) ^ get(hi);
}

int ask(int lo, int hi) {
    return pref[lo - 1] ^ pref[hi];
}

void solve() {
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] ^ a[i];
    
    for (int i = 0; i < M; i++)
        Q[r[i]].push_back(i);
    
    for (int i = 1; i <= N; i++) {
        int &ref = last[a[i]];
        if (ref) update(ref, a[i]);
        ref = i;
        update(ref, a[i]);
        for (int j = 0; j < Q[i].size(); j++)
            ans[Q[i][j]] = query(l[Q[i][j]], i) ^ ask(l[Q[i][j]], i);
    }
    
    for (int i = 0; i < M; i++)
        printf("%d\n", ans[i]);
}

int main() {
    load();
    solve();
    return 0;
}
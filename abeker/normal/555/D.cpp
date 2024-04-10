#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 200005;
const int INF = (int)2e9 + 5;

int N, M;
pii p[MAXN];
int pos[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
}

int get(int x, int dir) {
    if (dir == -1) return lower_bound(p + 1, p + N + 1, pii(x, -INF)) - p; 
    return upper_bound(p + 1, p + N + 1, pii(x, INF)) - p - 1;
}

int query(int x, int len, int dir) {
    if (N == 1) return 1;
    if ((ll)p[x].first - p[x - 1].first > (ll)len && (ll)p[x + 1].first - p[x].first > (ll)len) return x;
    if (abs((ll)p[x + dir].first - p[x].first) > (ll)len) return query(x, len, -dir);
    int nxt = get(p[x].first + len * dir, dir);
    int rest = len - dir * (p[nxt].first - p[x].first);
    if (2 * rest <= len) return query(nxt, rest, -dir);
    int curr = get(p[nxt].first - dir * rest, -dir);
    int diff = dir * (p[nxt].first - p[curr].first);
    rest -= diff;
    int ndir = rest / diff % 2;
    return query(ndir ? nxt : curr, rest % diff, ndir ? -dir : dir);
}

void solve() {
    p[0].first = -INF;
    p[N + 1].first = INF;
    sort(p + 1, p + N + 1);
    for (int i = 1; i <= N; i++)
        pos[p[i].second] = i;
    
    while (M--) {
        int a, l;
        scanf("%d%d", &a, &l);
        printf("%d\n", p[query(pos[a], l, 1)].second);
    }
}

int main() {
    load();
    solve();
    return 0;
}
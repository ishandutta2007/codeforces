#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;
const int LOG = 18;

int N, M;
int bits[MAXN][LOG];
ll sum[LOG];
set < pii > S[LOG];

pii get(int x, int y) {
    return *(--S[y].upper_bound(pii(x, N + 1)));
}

ll choose(int len) {
    return (ll)len * (len + 1) / 2;
}

void add(pii segment, int idx) {
    S[idx].insert(segment);
    sum[idx] += choose(segment.second - segment.first + 1);
}

void remove(pii segment, int idx) {
    S[idx].erase(segment);
    sum[idx] -= choose(segment.second - segment.first + 1);
}

void fill(int pos, int val) {
    for (int i = 0; i < LOG; i++) {
        int curr = val >> i & 1;
        if (curr == bits[pos][i]) continue;
        if (curr) {
            int lo = pos, hi = pos;
            if (bits[pos - 1][i]) {
                pii tmp = get(pos - 1, i);
                remove(tmp, i);
                lo = tmp.first;
            }
            if (bits[pos + 1][i]) {
                pii tmp = get(pos + 1, i);
                remove(tmp, i);
                hi = tmp.second;
            }
            add(pii(lo, hi), i);
        }
        else {
            pii tmp = get(pos, i);
            remove(tmp, i);
            if (tmp.first < pos) add(pii(tmp.first, pos - 1), i);
            if (tmp.second > pos) add(pii(pos + 1, tmp.second), i);
        }
        bits[pos][i] = curr;
    }
}

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        int x; scanf("%d", &x);
        fill(i, x);
    }
}

ll query() {
    ll sol = 0;
    for (int i = 0; i < LOG; i++)
        sol += sum[i] * (1ll << (ll)i);
    return sol;
}

void solve() {
    while (M--) {
        int p, v;
        scanf("%d%d", &p, &v);
        fill(p, v);
        printf("%I64d\n", query());
    }
}

int main() {
    load();
    solve();
    return 0;
}
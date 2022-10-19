#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <ll, int> pii;

const int MAXN = 200005;

struct inter {
    ll lo, hi;
    int idx;
    inter(ll lo, ll hi, int idx) : lo(lo), hi(hi), idx(idx) {}
    inter() : lo(0), hi(0), idx(0) {}
    bool operator <(const inter &rhs) const {
        if (hi != rhs.hi) return hi < rhs.hi;
        return lo < rhs.lo;
    }
};

int N, M;
ll l[MAXN], r[MAXN];
inter E[MAXN];
set <pii> S;
int sol[MAXN];

void load() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) 
        scanf("%I64d%I64d", l + i, r + i);
    for (int i = 1; i <= M; i++) {
        ll x;
        scanf("%I64d", &x);
        S.insert(pii(x, i));
    }
}

void solve() {
    for (int i = 1; i < N; i++) 
        E[i] = inter(l[i] - r[i - 1], r[i] - l[i - 1], i);
        
    sort(E + 1, E + N);
    for (int i = 1; i < N; i++) {
        set <pii> :: iterator it = S.lower_bound(pii(E[i].lo, 0));
        if (it == S.end() || it -> first > E[i].hi) {
            puts("No");
            return;
        }
        sol[E[i].idx] = it -> second;
        S.erase(it);
    }
    
    puts("Yes");
    for (int i = 1; i < N; i++)
        printf("%d ", sol[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}
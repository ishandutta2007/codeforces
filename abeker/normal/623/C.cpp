#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define x first
#define y second

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int N;
pii p[MAXN];
int sum[MAXN];
int pref_min[MAXN], pref_max[MAXN];
int suff_min[MAXN], suff_max[MAXN];
int left[MAXN], right[MAXN];

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
}

ll sqr(int val) {
    return (ll)val * val;
}

int pref_abs(int pos) {
    return pos >= 0 ? max(abs(pref_min[pos]), abs(pref_max[pos])) : 0;
}

int suff_abs(int pos) {
    return pos < N ? max(abs(suff_min[pos]), abs(suff_max[pos])) : 0;
}

int bin_abs(int pos) {
    int lo = pos, hi = N;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (abs(p[mid].x) <= abs(p[pos].x)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int bin_suff(int pos) {
    int lo = pos, hi = N;
    int val = pos ? pref_abs(pos - 1) : 0;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (suff_abs(mid) <= val) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int eval(int lo, int hi) {
    if (lo == 0 && hi == N - 1) return 0;
    int maks = max(suff_max[hi + 1], lo ? pref_max[lo - 1] : -INF);
    int mini = min(suff_min[hi + 1], lo ? pref_min[lo - 1] :  INF);
    return maks - mini;
}

ll calc(int lo, int hi) {
    return sqr(max(abs(p[lo].x), abs(p[hi].x))) + sqr(max(pref_abs(lo - 1), suff_abs(hi + 1)));
}

bool check(ll dist) {
    if (sqr(p[0].x - p[N - 1].x) <= dist || sqr(suff_min[0] - suff_max[0]) <= dist)
        return true;
    memset(sum, 0, sizeof sum);
    int it1 = 0, it2 = 0;
    ll sol = (ll)4e16;
    for (int i = 0; i < N; i++) {
        for (; it1 < N && sqr(p[it1].x - p[i].x) <= dist; it1++);
        for (it2 = max(it2, i); it2 < N && sqr(eval(i, it2)) > dist; it2++);
        if (it2 < it1) {
            sol = min(sol, calc(i, it2));
            sol = min(sol, calc(i, it1 - 1));
        }
        if (left[i] >= it2 && left[i] < it1) sol = min(sol, calc(i, left[i]));
        if (right[i] >= it2 && right[i] < it1) sol = min(sol, calc(i, right[i]));
        int lo = max(it2, left[i] + 1);
        int hi = min(it1, right[i]);
        if (lo > hi) continue;
        sum[lo]++;
        sum[hi]--;
    }
    
    for (int i = 0; i < N; i++) {
        if (i) sum[i] += sum[i - 1];
        if (sum[i]) sol = min(sol, sqr(p[i].x) + sqr(suff_abs(i + 1)));
    }
    
    return sol <= dist;
}

ll solve() {
    sort(p, p + N);
    suff_min[N] = INF;
    suff_max[N] = -INF;
    for (int i = N - 1; i >= 0; i--) {
        suff_min[i] = min(suff_min[i + 1], p[i].y);
        suff_max[i] = max(suff_max[i + 1], p[i].y);
    }
    
    pref_min[0] = pref_max[0] = p[0].y;
    for (int i = 1; i < N; i++) {
        pref_min[i] = min(pref_min[i - 1], p[i].y);
        pref_max[i] = max(pref_max[i - 1], p[i].y);
    }
    
    for (int i = 0; i < N; i++) {
        left[i] = bin_abs(i);
        right[i] = bin_suff(i) - 1;
    }
    
    ll lo = 0, hi = (ll)4e16;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    
    return lo;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}
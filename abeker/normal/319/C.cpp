#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

const int MAXN = 100005;

int N;
ll a[MAXN], b[MAXN];
vector <pii> hull;

void load() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%I64d", a + i);
    for (int i = 0; i < N; i++)
        scanf("%I64d", b + i);
}

ld ccw(pii A, pii B, pii C) {
    return (ld)A.first * (B.second - C.second) + (ld)B.first * (C.second - A.second) + (ld)C.first * (A.second - B.second);
}

void add(pii p) {
    while (hull.size() > 1 && ccw(hull[(int)hull.size() - 2], hull.back(), p) >= 0)
        hull.pop_back();
    hull.push_back(p);
}

ld dp(pii A, pii B) {
    return (ld)A.first * B.first + (ld)A.second * B.second;
}

ll bs(pii p) {
    if (hull.empty()) return 0;
    int lo = 0, hi = (int)hull.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (dp(hull[mid], p) < dp(hull[mid + 1], p)) hi = mid;
        else lo = mid + 1;
    }
    return (ll)dp(hull[lo], p);
}

ll solve() {
    ll sol;
    for (int i = 0; i < N; i++) {
        sol = bs(pii(a[i], 1));
        add(pii(b[i], sol));
    }
    return sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}
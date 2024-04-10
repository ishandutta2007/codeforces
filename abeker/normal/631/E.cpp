#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair <int, ll> pii;
typedef long double ld;

const int MAXN = 200005;

int N;
int a[MAXN];
ll pref[MAXN], suff[MAXN];
vector <pii> upper, lower;

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", a + i);
}

bool ccw(pii A, pii B, pii C) {
    return (ld)A.first * (B.second - C.second) + (ld)B.first * (C.second - A.second) + (ld)C.first * (A.second - B.second) >= 0;
}

ll dp(pii A, pii B) {
    return (ll)A.first * B.first + A.second * B.second;
}

ll get_right(int x) {
    int lo = 0, hi = (int)lower.size() - 1;
    pii tmp(a[x], -1);
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (dp(tmp, lower[mid]) < dp(tmp, lower[mid + 1])) lo = mid + 1;
        else hi = mid;
    }
    return dp(tmp, lower[lo]);
}

void add_right(int x) {
    pii tmp(x, pref[x]);
    while (lower.size() > 1 && ccw(lower[(int)lower.size() - 2], lower.back(), tmp))
        lower.pop_back();
    lower.push_back(tmp);
}

ll get_left(int x) {
    int lo = 0, hi = (int)upper.size() - 1;
    pii tmp(a[x], 1);
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (dp(tmp, upper[mid]) < dp(tmp, upper[mid + 1])) lo = mid + 1;
        else hi = mid;
    }
    return dp(tmp, upper[lo]);
}

void add_left(int x) {
    pii tmp(x, suff[x]);
    while (upper.size() > 1 && ccw(upper[(int)upper.size() - 2], upper.back(), tmp))
        upper.pop_back();
    upper.push_back(tmp);
}

ll solve() {
    for (int i = 1; i <= N; i++)
        pref[i] = pref[i - 1] + a[i];
    
    for (int i = N; i; i--)
        suff[i] = suff[i + 1] + a[i];
    
    ll val = 0;
    for (int i = 1; i <= N; i++)
        val += (ll)i * a[i];
    
    ll sol = 0;  
    for (int i = N; i; i--) {
        if (i < N) sol = max(sol, get_right(i) + pref[i] - (ll)i * a[i]);
        add_right(i);
    }    
    
    for (int i = 1; i <= N; i++) {
        if (i > 1) sol = max(sol, get_left(i) - suff[i] - (ll)i * a[i]);
        add_left(i);
    }
    
    return val + sol;
}

int main() {
    load();
    printf("%I64d\n", solve());
    return 0;
}
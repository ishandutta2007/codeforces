#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 100005;

int N, A;
int cf, cm;
ll M;
int a[MAXN], b[MAXN];
ll pref[MAXN];
pii p[MAXN];

void load() {
    scanf("%d%d%d%d%I64d", &N, &A, &cf, &cm, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", a + i);
}

bool check(int pos, int val, ll tot) {
    int idx = min(lower_bound(a, a + N, val) - a - 1, pos);
    if (idx < 0) return true;
    return (ll)(idx + 1) * val - pref[idx] <= tot;
}

int bs(int pos, ll tot) {
    int lo = 0, hi = A;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(pos, mid, tot)) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

void solve() {
    for (int i = 0; i < N; i++) {
        p[i] = pii(a[i], i);
        b[i] = a[i];
    }
    sort(p, p + N);
    sort(a, a + N);
    pref[0] = (ll)a[0];
    for (int i = 1; i < N; i++)
        pref[i] = pref[i - 1] + (ll)a[i];
        
    ll sum = 0, sol = 0;
    int best = N, opt = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (sum > M) break;
        int tmp = bs(i, M - sum);
        ll curr = (ll)(N - i - 1) * cf + (ll)tmp * cm;
        if (curr > sol) {
            sol = curr;
            best = i;
            opt = tmp;
        }
        sum += (ll)(A - a[i]);
    }
    
    if (sum <= M) {
        sol = (ll)N * cf + (ll)A * cm;
        best = -1;
        opt = A;
    }
    
    printf("%I64d\n", sol);
    for (int i = 0; i < N; i++) 
        if (i > best) b[p[i].second] = A;
        else b[p[i].second] = max(b[p[i].second], opt);
    for (int i = 0; i < N; i++)
        printf("%d ", b[i]);
    puts("");
}

int main() {
    load();
    solve();
    return 0;
}
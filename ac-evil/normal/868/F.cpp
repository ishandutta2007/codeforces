#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i, a, b) for (register int i = a, end = b; i <= end; i++)
#define repd(i, a, b) for (register int i = a, end = b; i >= end; i--)
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define INF (1<<30)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fst first
#define snd second
#define pii pair<int, int>

inline int read() {
    int w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

const int maxn = 200000 + 5;

int N, K;
int A[maxn];
ll f[maxn], g[maxn];

int cnt[maxn], pl = 1, pr = 0;
ll _ans = 0;
void add(int x) { _ans += cnt[A[x]], cnt[A[x]]++; }
void del(int x) { cnt[A[x]]--; _ans -= cnt[A[x]]; }

void solve(int L, int R, int l, int r) {
    int mid = L+R>>1, pos;
    ll minv = 1ll<<60;
    while (pr < mid) add(++pr);
    while (pr > mid) del(pr--);
    repd(i, min(r, mid), l) {
        while (pl < i) del(pl++);
        while (pl > i) add(--pl);
        if (g[i-1] + _ans < minv) pos = i, minv = g[i-1] + _ans;
    }
    f[mid] = minv;
    if (L < mid) solve(L, mid-1, l, pos);
    if (mid < R) solve(mid+1, R, pos, r);
}

int main() {
    N = read(), K = read();

    rep(i, 1, N) A[i] = read();

    memset(f, 0x3f, sizeof(f)); f[0] = 0;
    rep(i, 1, K) {
        memcpy(g, f, sizeof(g));
        memset(f, 0x3f, sizeof(f));
        solve(1, N, 0, N);
    }
    printf("%lld", f[N]);
    return 0;
}
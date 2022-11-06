#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>

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

inline ll read() {
    ll w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

const int maxn = 200000 + 5;

ll a[maxn], b[maxn];
int cnt[maxn], tot[100];
int N;

int main() {
    N = read();
    rep(i, 1, N) {
        a[i] = b[i] = read();
        while (!(b[i] & 1)) cnt[i]++, b[i] >>= 1;
        tot[cnt[i]]++;
    }

    int ans = 0;
    rep(i, 1, 99) if (tot[i] > tot[ans]) ans = i;
    printf("%d\n", N-tot[ans]);
    rep(i, 1, N) if (cnt[i] != ans) printf("%lld ", a[i]);

    return 0;
}
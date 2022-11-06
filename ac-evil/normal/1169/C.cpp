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

inline int read() {
    int w = 0, f = 1; char c;
    while (!isdigit(c = getchar())) f = c == '-' ? -1 : f;
    while (isdigit(c)) w = (w << 3) + (w << 1) + (c ^ 48), c = getchar();
    return w * f;
}

const int maxn = 300000 + 5;

int N, M, a[maxn];

bool check(int x) {
    int lev = 0;
    rep(i, 1, N) {
        if ((lev - a[i] + M) % M <= x) continue;
        else if (a[i] < lev) return false;
        lev = a[i];
    }
    return true;
}

int main() {
    N = read(), M = read();
    rep(i, 1, N) a[i] = read();
    int l = 0, r = M, ans = M;
    while (l <= r) {
        int mid = l+r>>1;
        if (check(mid)) ans = mid, r = mid-1; else l = mid+1;
    }
    printf("%d", ans);
    return 0;
}
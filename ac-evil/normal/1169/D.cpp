#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>

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

char s[maxn];
int lk[maxn];
int N;
int f[maxn];

vector<pii > vec;

bool cmp(pii a, pii b) {
    return a.snd < b.snd;
}

int main() {
    scanf("%s", s);
    N = strlen(s);
    for (register int i = N, p0 = N+1, p1 = N+1; i; i--)
        if (s[i-1] == '0') lk[i] = p0, p0 = i;
        else lk[i] = p1, p1 = i;
    rep(i, 1, N)
        for (register int x = lk[i]; (x<<1)-i <= N; x = lk[x])
            if (s[(x<<1)-i-1] == s[i-1]) { vec.pb(mp(i, (x<<1)-i)); break; }

    sort(vec.begin(), vec.end(), cmp);
    /*
    for (register int i = 0; i < vec.size(); i++) {
        printf("(%d, %d)\n", vec[i].fst, vec[i].snd);
    }
    */

    ll ans = 0;
    for (register int i = 1, l = 0, r = 0, p = 0; i <= N; i++, l = r) {
        while (r < (int)vec.size() && vec[r].snd == i) r++;
        rep(x, l, r-1) chkmax(p, vec[x].fst);
        ans += p;
    }
    printf("%lld", ans);
    return 0;
}
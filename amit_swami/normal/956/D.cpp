#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

const int N = 110000;

struct rat
{
    ll x, y;
    rat() {}
    rat(ll xx, ll yy): x(xx), y(yy) {}
};

inline bool operator < (rat r1, rat r2) { return r1.x * r2.y < r1.y * r2.x; }
inline bool operator > (rat r1, rat r2) { return r1.x * r2.y > r1.y * r2.x; }
inline bool operator == (rat r1, rat r2) { return r1.x * r2.y == r1.y * r2.x; }

rat c[N];
int cc = 0;

int a[N], b[N];
pair<rat, rat> z[N];

int t[N];

int get(int x)
{
    x++;
    int res = 0;
    for (; x > 0; x -= x & -x) res += t[x];
    return res;
}

void upd(int x, int dx)
{
    x++;
    for (; x < N; x += x & -x) t[x] += dx;
}

int main()
{
    #ifdef amit_swami
        freopen("in", "r", stdin);
        freopen("out", "w", stdout);
    #endif
    int n, w;
    scanf("%d%d", &n, &w);
    forn(i, n) scanf("%d%d", &a[i], &b[i]);
    forn(i, n)
    {
        int sw = 0;
        if (a[i] < 0) a[i] = -a[i], sw = 1;
        if (b[i] < 0) b[i] = -b[i];
        z[i] = {rat(a[i], b[i] + w), rat(a[i], b[i] - w)};
        if (sw) swap(z[i].first, z[i].second);
        c[cc++] = z[i].second;
        z[i].second.x *= -1;
    }
    sort(z, z + n);
    sort(c, c + cc);
    cc = unique(c, c + cc) - c;

    ll res = 0;
    forn(i, n)
    {
        z[i].second.x *= -1;
        int pos = lower_bound(c, c + cc, z[i].second) - c;
        res += i - get(pos - 1);
        upd(pos, 1);
    }
    printf("%lld\n", res);


    return 0;
}
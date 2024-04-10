#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define err(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;


const int N = 2e5 + 10;
const ll INF = 1e18;

int a[N], aa = 0;
int b[N], bb = 0;
ll res;
int x1, y1, x2, y2;
int v;

void f1(int Z)
{
    res = min(res, (ll)abs(y1 - Z) + abs(y2 - Z) + abs(x1 - x2));
}

void f2(int Z)
{
    res = min(res, (ll)abs(y1 - Z) + abs(y2 - Z) + (abs(x1 - x2) + v - 1) / v);
}

int main() {
#ifdef amit_swami
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n, m, cl, ce;
    scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
    forn(i, cl)
    {
        int x;
        scanf("%d", &x);
        a[aa++] = x;
    }
    forn(i, ce)
    {
        int x;
        scanf("%d", &x);
        b[bb++] = x;
    }
    sort(a, a + aa);
    sort(b, b + bb);
    int q;
    scanf("%d", &q);
    forn(_, q)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        res = INF;
        int pos = lower_bound(a, a + aa, y1) - a;
        if (pos > 0) f1(a[pos - 1]);
        if (pos < aa) f1(a[pos]);
        pos = lower_bound(b, b + bb, y1) - b;
        if (pos > 0) f2(b[pos - 1]);
        if (pos < bb) f2(b[pos]);
        if (x1 == x2) res = abs(y1 - y2);
        printf("%lld\n", res);
    }
        


    return 0;
}
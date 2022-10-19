#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
const ll INF = 1000000009000000009;

struct ban
{
    int i;
    int x, y;
    ban(){}
    ban(int i, int x, int y)
    {
        this->i = i;
        this->x = x;
        this->y = y;
    }
};
bool sox(const ban& a, const ban& b)
{
    return a.x < b.x;
}
bool soy(const ban& a, const ban& b)
{
    return a.y < b.y;
}

int n, k;
ban a[N], b[N];

ll ans = INF;

bool c[N];

void rec(int kk, int la, int ra, int lb, int rb)
{
    while (c[a[la].i])
        ++la;
    while (c[a[ra].i])
        --ra;
    while (c[b[lb].i])
        ++lb;
    while (c[b[rb].i])
        --rb;
    if (kk == 0)
    {
        int xx = a[ra].x - a[la].x;
        int yy = b[rb].y - b[lb].y;
        if (xx == 0)
            ++xx;
        if (yy == 0)
            ++yy;
        if (xx % 2 == 1)
            ++xx;
        if (yy % 2 == 1)
            ++yy;
        xx /= 2;
        yy /= 2;
        ans = min(ans, xx * 1LL * yy);
        return;
    }
    {
        vector<int> v;
        for (int i = la; a[i].x == a[la].x; ++i)
        {
            if (sz(v) == kk)
                break;
            v.push_back(a[i].i);
        }
        for (int i = 0; i < v.size(); ++i)
            c[v[i]] = true;
        rec(kk - sz(v), la, ra, lb, rb);
        for (int i = 0; i < v.size(); ++i)
            c[v[i]] = false;
    }
    {
        vector<int> v;
        for (int i = ra; a[i].x == a[ra].x; --i)
        {
            if (sz(v) == kk)
                break;
            v.push_back(a[i].i);
        }
        for (int i = 0; i < v.size(); ++i)
            c[v[i]] = true;
        rec(kk - sz(v), la, ra, lb, rb);
        for (int i = 0; i < v.size(); ++i)
            c[v[i]] = false;
    }
    {
        vector<int> v;
        for (int i = lb; b[i].y == b[lb].y; ++i)
        {
            if (sz(v) == kk)
                break;
            v.push_back(b[i].i);
        }
        for (int i = 0; i < v.size(); ++i)
            c[v[i]] = true;
        rec(kk - sz(v), la, ra, lb, rb);
        for (int i = 0; i < v.size(); ++i)
            c[v[i]] = false;
    }
    {
        vector<int> v;
        for (int i = rb; b[i].y == b[rb].y; --i)
        {
            if (sz(v) == kk)
                break;
            v.push_back(b[i].i);
        }
        for (int i = 0; i < v.size(); ++i)
            c[v[i]] = true;
        rec(kk - sz(v), la, ra, lb, rb);
        for (int i = 0; i < v.size(); ++i)
            c[v[i]] = false;
    }
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        int x1, y1_, x2, y2;
        scanf("%d%d%d%d", &x1, &y1_, &x2, &y2);
        a[i].i = i;
        a[i].x = x1 + x2;
        a[i].y = y1_ + y2;
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1, sox);
    sort(b + 1, b + n + 1, soy);
    rec(k, 1, n, 1, n);
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
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
struct ban
{
    int x, y;
};
bool operator<(const ban& a, const ban& b)
{
    return a.y < b.y;
}

int m, n;
ban a[N];

int z;
vector<int> v;
map<int, int> mp;
int rmp[N];

int q[N * 4];
ll s[N * 4];
int minu[N * 4];

void bil(int tl, int tr, int pos)
{
    q[pos] = 0;
    s[pos] = 0;
    if (tl == tr)
    {
        minu[pos] = rmp[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        ++q[pos];
        s[pos] += rmp[x];
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    q[pos] = q[pos * 2] + q[pos * 2 + 1];
    s[pos] = s[pos * 2] + s[pos * 2 + 1];
}

int qryy(int tl, int tr, int y, int pos)
{
    if (tl == tr)
    {
        if (y <= minu[pos])
            return q[pos];
        return 0;
    }
    int m = (tl + tr) / 2;
    if (y <= minu[pos * 2 + 1])
        return qryy(tl, m, y, pos * 2) + q[pos * 2 + 1];
    return qryy(m + 1, tr, y, pos * 2 + 1);
}

ll qryq(int tl, int tr, int qq, int pos)
{
    if (tl == tr)
    {
        return min(q[pos], qq) * 1LL * rmp[tl];
    }
    int m = (tl + tr) / 2;
    if (qq > q[pos * 2 + 1])
        return qryq(tl, m, qq - q[pos * 2 + 1], pos * 2) + s[pos * 2 + 1];
    return qryq(m + 1, tr, qq, pos * 2 + 1);
}

void solv()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].x, &a[i].y);
    sort(a + 1, a + n + 1);

    z = 0;
    v.clear();
    mp.clear();
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i].x);
    }
    sort(all(v));
    for (int i = 0; i < n; ++i)
    {
        if (!i || v[i] != v[i - 1])
        {
            mp[v[i]] = ++z;
            rmp[z] = v[i];
        }
    }

    bil(1, z, 1);

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ll yans = 0;
        int mm = m;
        yans += a[i].x;
        --mm;
        int mt = min(mm, qryy(1, z, a[i].y, 1));
        yans += qryq(1, z, mt, 1);
        mm -= mt;
        yans += mm * 1LL * a[i].y;
        ans = max(ans, yans);
        ubd(1, z, mp[a[i].x], 1);
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        solv();
    }
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
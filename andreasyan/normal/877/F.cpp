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
const int N = 100005, L = 22;

int n, k;
int ty[N];
int a[N];

ll p[N];
vector<ll> v;
int u[N], upk[N], umk[N];

int s;
struct ban
{
    int i;
    int l, r;
};
bool operator<(const ban& a, const ban& b)
{
    if ((a.l / s) < (b.l / s))
        return true;
    if ((a.l / s) > (b.l / s))
        return false;
    return a.r < b.r;
}

int m;
ban b[N];

ll ans[N];

ll yans;

int qpk[N], qmk[N];

void avel(int x)
{
    if (umk[x] != -1)
        ++qmk[umk[x]];
    yans += qmk[u[x - 1]];
    if (upk[x - 1] != -1)
        ++qpk[upk[x - 1]];
}

void hanl(int x)
{
    yans -= qmk[u[x - 1]];
    if (upk[x - 1] != -1)
        --qpk[upk[x - 1]];
    if (umk[x] != -1)
        --qmk[umk[x]];
}

void aver(int x)
{
    if (upk[x - 1] != -1)
        ++qpk[upk[x - 1]];
    yans += qpk[u[x]];
    if (umk[x] != -1)
        ++qmk[umk[x]];
}

void hanr(int x)
{
    yans -= qpk[u[x]];
    if (umk[x] != -1)
        --qmk[umk[x]];
    if (upk[x - 1] != -1)
        --qpk[upk[x - 1]];
}

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &ty[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (ty[i] == 1)
            p[i] += a[i];
        else
            p[i] -= a[i];
    }
    for (int i = 0; i <= n; ++i)
        v.push_back(p[i]);
    sort(all(v));
    for (int i = 0; i <= n; ++i)
    {
        u[i] = lower_bound(all(v), p[i]) - v.begin();
        upk[i] = umk[i] = -1;
        if (binary_search(all(v), p[i] + k))
            upk[i] = lower_bound(all(v), p[i] + k) - v.begin();
        if (binary_search(all(v), p[i] - k))
            umk[i] = lower_bound(all(v), p[i] - k) - v.begin();
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        b[i].i = i;
        scanf("%d%d", &b[i].l, &b[i].r);
    }
    s = sqrt(n);
    sort(b, b + m);
    int l = 1, r = 0;
    for (int i = 0; i < m; ++i)
    {
        int l1 = b[i].l;
        int r1 = b[i].r;
        while (r < r1)
        {
            ++r;
            aver(r);
        }
        while (l > l1)
        {
            --l;
            avel(l);
        }
        while (r > r1)
        {
            hanr(r);
            --r;
        }
        while (l < l1)
        {
            hanl(l);
            ++l;
        }
        ans[b[i].i] = yans;
    }
    for (int i = 0; i < m; ++i)
        printf("%lld\n", ans[i]);
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
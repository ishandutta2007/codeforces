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
const int N = 200005;

int n;
char a[N];
char b[N];

int z;
int p[N], c[N];

int q[N];

int np[N], nc[N];

int u[N], lcp[N];

void bil()
{
    b[n] = '0';
    a[n++] = 0;
    vector<pair<char, int> > v;
    for (int i = 0; i < n; ++i)
    {
        v.push_back(m_p(a[i], i));
    }
    sort(all(v));
    for (int i = 0; i < n; ++i)
    {
        p[i] = v[i].se;
    }
    z = 0;
    c[p[0]] = z++;
    for (int i = 1; i < n; ++i)
    {
        if (a[p[i]] == a[p[i - 1]])
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = z++;
    }
    for (int k = 0; (1 << k) < n; ++k)
    {
        memset(q, 0, sizeof q);
        for (int i = 0; i < n; ++i)
            q[c[i]]++;
        for (int i = 1; i < z; ++i)
            q[i] += q[i - 1];
        for (int i = n - 1; i >= 0; --i)
        {
            int j = p[i] - (1 << k);
            if (j < 0)
                j += n;
            np[--q[c[j]]] = j;
        }
        memcpy(p, np, sizeof np);
        z = 0;
        nc[p[0]] = z++;
        for (int i = 1; i < n; ++i)
        {
            if (m_p(c[p[i]], c[(p[i] + (1 << k)) % n]) == m_p(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]))
            {
                nc[p[i]] = nc[p[i - 1]];
            }
            else
            {
                nc[p[i]] = z++;
            }
        }
        memcpy(c, nc, sizeof nc);
    }
    for (int i = 0; i < n; ++i)
    {
        u[p[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n; ++i)
    {
        if (u[i] == n - 1)
        {
            k = 0;
            lcp[u[i]] = k;
            continue;
        }
        while (a[i + k] == a[p[u[i] + 1] + k])
            ++k;
        lcp[u[i]] = k;
        --k;
        k = max(k, 0);
    }
}

vector<pair<int, int> > v[N];

int p0[N], q0[N];

int fi(int x)
{
    if (x == p0[x])
        return x;
    return p0[x] = fi(p0[x]);
}

ll ans;

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p0[x] = y;
    q0[y] += q0[x];
}

void solv()
{
    scanf("%d", &n);
    scanf(" %s %s", a, b);
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == '0')
            b[i] = '1';
        else
            b[i] = '0';
    }
    reverse(a, a + n);
    reverse(b, b + n);
    bil();
    for (int i = 0; i < n - 1; ++i)
    {
        v[lcp[i]].push_back(m_p(p[i], p[i + 1]));
    }
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == '1')
        {
            ans = (n - i - 1);
            break;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        p0[i] = i;
        q0[i] = b[i] - '0';
    }
    for (int i = n; i >= 0; --i)
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            kpc(v[i][j].fi, v[i][j].se);
            ans = max(ans, q0[fi(v[i][j].fi)] * 1LL * i);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
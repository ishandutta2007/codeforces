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

int n;
char a[N];

int z;
pair<char, int> ss[N];

int p[N], c[N];

int q[N];

int np[N], nc[N];

int u[N];
int lcp[N];

bool solv()
{
    scanf(" %s", a);
    n = strlen(a);
    n++;
    for (int i = 0; i < n; ++i)
    {
        ss[i] = m_p(a[i], i);
    }
    sort(ss, ss + n);
    for (int i = 0; i < n; ++i)
    {
        p[i] = ss[i].se;
    }
    c[p[0]] = z++;
    for (int i = 1; i < n; ++i)
    {
        if (a[p[i]] == a[p[i - 1]])
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = z++;
    }
    for (int u = 0; (1 << u) < n; ++u)
    {
        memset(q, 0, sizeof q);
        for (int i = 0; i < n; ++i)
        {
            q[c[i]]++;
        }
        for (int i = 1; i < z; ++i)
        {
            q[i] += q[i - 1];
        }
        for (int i = n - 1; i >= 0; --i)
        {
            int j = (p[i] - (1 << u));
            if (j < 0)
                j += n;
            np[--q[c[j]]] = j;
        }
        z = 0;
        nc[np[0]] = z++;
        for (int i = 0; i < n; ++i)
        {
            if (m_p(c[np[i]], c[(np[i] + (1 << u)) % n]) == m_p(c[np[i - 1]], c[(np[i - 1] + (1 << u)) % n]))
                nc[np[i]] = nc[np[i - 1]];
            else
                nc[np[i]] = z++;
        }
        memcpy(c, nc, sizeof nc);
        memcpy(p, np, sizeof np);
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
            continue;
        }
        while (a[i + k] == a[p[u[i] + 1] + k])
            ++k;
        lcp[u[i]] = k;
        if (k > 0)
            --k;
    }
    ll ans = 0;
    stack<pair<int, int> > s;
    ll yans = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        int q = 1;
        while (!s.empty() && s.top().fi > lcp[i])
        {
            yans -= s.top().fi * 1LL * s.top().se;
            q += s.top().se;
            s.pop();
        }
        yans += q * 1LL * lcp[i];
        s.push(m_p(lcp[i], q));
        ans += yans;
    }
    ans += (n * 1LL * (n - 1)) / 2;
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
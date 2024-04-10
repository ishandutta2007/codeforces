#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 600005;
const int M = 1000000007;

int astt(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return ans;
}

int ast[N];
void pre()
{
    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
}

int n;
int a[N];
int m;
pair<int, int> b[N];
vector<pair<int, int> > v;

struct ban
{
    int ans;
    int ll, rr;
    int q;
    ban()
    {
        ans = 0;
        ll = 0;
        rr = 0;
        q = 0;
    }
    ban(int x)
    {
        ans = 0;
        ll = x;
        rr = x;
        q = 1;
    }
};

ban mer(const ban& a, const ban& b)
{
    ban res;
    res.q = a.q + b.q;
    res.ll = (a.ll + (b.ll * 1LL * ast[a.q]) % M) % M;
    res.rr = (b.rr + (a.rr * 1LL * ast[b.q]) % M) % M;
    res.ans = ((a.ans * 1LL * ast[b.q]) % M + (b.ans * 1LL * ast[a.q]) % M) % M;
    res.ans = (res.ans + (a.ll * 1LL * b.rr) % M) % M;
    return res;
}

ban t[N * 4];

void ubd(int tl, int tr, int x, int pos)
{
    if (tl == tr)
    {
        if (t[pos].q == 0)
            t[pos] = ban(v[x - 1].first);
        else
            t[pos] = ban();
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, pos * 2);
    else
        ubd(m + 1, tr, x, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    pre();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        v.push_back(m_p(a[i], i));
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &b[i].first, &b[i].second);
        v.push_back(m_p(b[i].second, n + i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].second <= n)
            a[v[i].second] = i + 1;
        else
            b[v[i].second - n].second = i + 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        ubd(1, n + m, a[i], 1);
    }
    int rastn = astt(ast[n], M - 2);
    printf("%d\n", (t[1].ans * 1LL * rastn) % M);
    for (int i = 1; i <= m; ++i)
    {
        ubd(1, n + m, a[b[i].first], 1);
        a[b[i].first] = b[i].second;
        ubd(1, n + m, a[b[i].first], 1);
        printf("%d\n", (t[1].ans * 1LL * rastn) % M);
    }
    return 0;
}
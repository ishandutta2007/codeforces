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
const int N = 200005, M = 1000000007;

int ast[N];
void pre()
{
    ast[0] = 1;
    for (int i = 1; i < N; ++i)
        ast[i] = (ast[i - 1] * 2) % M;
}

int n;
int x[N], y[N];

int p[N];
int qk[N], qg[N], ql[N];
int fi(int x)
{
    if (x == p[x])
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    if (x == y)
        return;
    p[x] = y;
    qg[y] += qg[x];
    qk[y] += qk[x];
    ql[y] += ql[x];
}

map<int, vector<int> > xx, yy;

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        p[i] = i;
        qg[i] = 1;
        scanf("%d%d", &x[i], &y[i]);
        xx[x[i]].push_back(i);
        yy[y[i]].push_back(i);
    }
    for (auto it = xx.begin(); it != xx.end(); ++it)
    {
        for (int i = 0; i < sz(it->se) - 1; ++i)
        {
            kpc(it->se[i], it->se[i + 1]);
        }
        qk[fi(it->se[0])] += (sz(it->se) - 1);
        ++ql[fi(it->se[0])];
    }
    for (auto it = yy.begin(); it != yy.end(); ++it)
    {
        for (int i = 0; i < sz(it->se) - 1; ++i)
        {
            kpc(it->se[i], it->se[i + 1]);
        }
        qk[fi(it->se[0])] += (sz(it->se) - 1);
        ++ql[fi(it->se[0])];
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (i != fi(i))
            continue;
        if (qk[i] == qg[i] - 1)
            ans = (ans * 1LL * (ast[ql[i]] - 1 + M)) % M;
        else
            ans = (ans * 1LL * ast[ql[i]]) % M;
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
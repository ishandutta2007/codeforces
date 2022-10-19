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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[N];

vector<int> u[N];
vector<int> v[N];

ll s[N * 4];
int maxu[N * 4], minu[N * 4], laz[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        s[pos] = tl + 2;
        maxu[pos] = tl + 2;
        minu[pos] = tl + 2;
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    s[pos] = s[pos * 2] + s[pos * 2 + 1];
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

void shi(int tl, int tr, int pos)
{
    if (laz[pos] == 0)
        return;
    int m = (tl + tr) / 2;

    s[pos * 2] = laz[pos] * 1LL * (m - tl + 1);
    maxu[pos * 2] = laz[pos];
    minu[pos * 2] = laz[pos];
    laz[pos * 2] = laz[pos];

    s[pos * 2 + 1] = laz[pos] * 1LL * (tr - m);
    maxu[pos * 2 + 1] = laz[pos];
    minu[pos * 2 + 1] = laz[pos];
    laz[pos * 2 + 1] = laz[pos];

    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        if (y <= minu[pos])
            return;
        if (y >= maxu[pos])
        {
            s[pos] = y * 1LL * (r - l + 1);
            maxu[pos] = y;
            minu[pos] = y;

            laz[pos] = y;
            return;
        }
    }
    if (tl == tr)
        return;
    shi(tl, tr, pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    s[pos] = s[pos * 2] + s[pos * 2 + 1];
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
    minu[pos] = min(minu[pos * 2], minu[pos * 2 + 1]);
}

ll q[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
            u[j].push_back(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < u[a[i]].size(); ++j)
        {
            v[u[a[i]][j]].push_back(i);
        }
    }
    bil(0, n, 1);
    q[N - 1] = (n + 1) * 1LL * (n + 2) - s[1];
    for (int i = N - 2; i >= 0; --i)
    {
        q[i] = (n + 1) * 1LL * (n + 2) - s[1];
        if (v[i].size() >= 2)
        {
            ubd(0, n, 0, v[i][0] - 1, v[i][v[i].size() - 2] + 1, 1);
            ubd(0, n, v[i][0], v[i][1] - 1, v[i][v[i].size() - 1] + 1, 1);
            ubd(0, n, v[i][1], n, n + 2, 1);
        }
    }
    ll ans = 0;
    for (int i = 1; i < N; ++i)
    {
        ans += (q[i] - q[i - 1]) * i;
    }
    printf("%lld\n", ans);
}

void solv0()
{
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            vector<int> v;
            for (int k = 1; k < i; ++k)
                v.push_back(a[k]);
            for (int k = j + 1; k <= n; ++k)
                v.push_back(a[k]);
            int maxu = 0;
            for (int k = 0; k < v.size(); ++k)
            {
                for (int k1 = k + 1; k1 < v.size(); ++k1)
                {
                    maxu = max(maxu, gcd(v[k], v[k1]));
                }
            }
            ans += maxu;
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
    solv();
    //solv0();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
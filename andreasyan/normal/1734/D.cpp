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
const ll INF = 1000000009000000009;

int n, k;
int a[N];

ll p[N];

int ur[N], ul[N];

struct ban
{
    ll minu, maxu;
    ban()
    {
        minu = INF;
        maxu = -INF;
    }
};

ban mer(const ban& l, const ban& r)
{
    ban res;
    res.maxu = max(l.maxu, r.maxu);
    res.minu = min(l.minu, r.minu);
    return res;
}

ban t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos].maxu = p[tl - 1];
        t[pos].minu = p[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = mer(t[pos * 2], t[pos * 2 + 1]);
}

ban qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return ban();
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return mer(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];

    stack<int> s;
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && p[i] >= p[s.top()])
            s.pop();
        if (s.empty())
            ur[i] = n + 1;
        else
            ur[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && p[i - 1] <= p[s.top() - 1])
            s.pop();
        if (s.empty())
            ul[i] = 0;
        else
            ul[i] = s.top();
        s.push(i);
    }

    bil(1, n, 1);

    int l = k;
    int r = k;
    while (1)
    {
        if (ur[r] <= n && p[r] - p[l - 1] + qry(1, n, r + 1, ur[r], 1).minu - p[r] >= 0)
        {
            r = ur[r];
            continue;
        }
        if (ul[l] >= 1 && p[r] - p[l - 1] + p[l - 1] - qry(1, n, ul[l], l - 1, 1).maxu >= 0)
        {
            l = ul[l];
            continue;
        }
        if (p[r] - p[l - 1] + qry(1, n, r + 1, n, 1).minu - p[r] >= 0)
        {
            cout << "YES\n";
            return;
        }
        if (p[r] - p[l - 1] + p[l - 1] - qry(1, n, 1, l - 1, 1).maxu >= 0)
        {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
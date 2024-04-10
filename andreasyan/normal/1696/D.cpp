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
const int N = 250005;

int n;
int a[N];

int urmax[N], ulmax[N];
int urmin[N], ulmin[N];

bool c[N];
int d[N];

void ubd(vector<pair<int, int> >& t, int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = m_p(y, tl);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(t, tl, m, x, y, pos * 2);
    else
        ubd(t, m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

pair<int, int> qry(vector<pair<int, int> >& t, int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(N, N);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(t, tl, m, l, min(m, r), pos * 2),
               qry(t, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        c[i] = false;
    }

    //////max///////
    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();

        if (s.empty())
            ulmax[i] = 0;
        else
            ulmax[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();

        if (s.empty())
            urmax[i] = n + 1;
        else
            urmax[i] = s.top();
        s.push(i);
    }

    //////min////////
    while (!s.empty())
        s.pop();
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] > a[i])
            s.pop();

        if (s.empty())
            ulmin[i] = 0;
        else
            ulmin[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[s.top()] > a[i])
            s.pop();

        if (s.empty())
            urmin[i] = n + 1;
        else
            urmin[i] = s.top();
        s.push(i);
    }

    ///////////////////////////////

    vector<pair<int, int> > t1, t2, t3, t4;
    t1.assign(n * 4 + 10, m_p(0, 0));
    t2.assign(n * 4 + 10, m_p(0, 0));
    t3.assign(n * 4 + 10, m_p(0, 0));
    t4.assign(n * 4 + 10, m_p(0, 0));

    for (int i = 1; i <= n; ++i)
        ubd(t1, 1, n, i, ulmax[i], 1);
    for (int i = 1; i <= n; ++i)
        ubd(t2, 1, n, i, ulmin[i], 1);

    for (int i = 1; i <= n; ++i)
        ubd(t3, 1, n, i, -urmax[i], 1);
    for (int i = 1; i <= n; ++i)
        ubd(t4, 1, n, i, -urmin[i], 1);

    queue<int> q;
    c[1] = true;
    d[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();

        while (1)
        {
            pair<int, int> u = qry(t1, 1, n, i + 1, urmin[i] - 1, 1);
            if (u.fi >= i)
                break;
            if (!c[u.se])
            {
                c[u.se] = true;
                d[u.se] = d[i] + 1;
                q.push(u.se);
            }
            ubd(t1, 1, n, u.se, N, 1);
            ubd(t2, 1, n, u.se, N, 1);
            ubd(t3, 1, n, u.se, N, 1);
            ubd(t4, 1, n, u.se, N, 1);
        }
        while (1)
        {
            pair<int, int> u = qry(t2, 1, n, i + 1, urmax[i] - 1, 1);
            if (u.fi >= i)
                break;
            if (!c[u.se])
            {
                c[u.se] = true;
                d[u.se] = d[i] + 1;
                q.push(u.se);
            }
            ubd(t1, 1, n, u.se, N, 1);
            ubd(t2, 1, n, u.se, N, 1);
            ubd(t3, 1, n, u.se, N, 1);
            ubd(t4, 1, n, u.se, N, 1);
        }

        while (1)
        {
            pair<int, int> u = qry(t3, 1, n, ulmin[i] + 1, i - 1, 1);
            if (-u.fi <= i)
                break;
            if (!c[u.se])
            {
                c[u.se] = true;
                d[u.se] = d[i] + 1;
                q.push(u.se);
            }
            ubd(t1, 1, n, u.se, N, 1);
            ubd(t2, 1, n, u.se, N, 1);
            ubd(t3, 1, n, u.se, N, 1);
            ubd(t4, 1, n, u.se, N, 1);
        }
        while (1)
        {
            pair<int, int> u = qry(t4, 1, n, ulmax[i] + 1, i - 1, 1);
            if (-u.fi <= i)
                break;
            if (!c[u.se])
            {
                c[u.se] = true;
                d[u.se] = d[i] + 1;
                q.push(u.se);
            }
            ubd(t1, 1, n, u.se, N, 1);
            ubd(t2, 1, n, u.se, N, 1);
            ubd(t3, 1, n, u.se, N, 1);
            ubd(t4, 1, n, u.se, N, 1);
        }
    }

    cout << d[n] << endl;
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
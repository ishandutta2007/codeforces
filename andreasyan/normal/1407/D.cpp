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
const int N = 300005;

int n;
int a[N];

int um[N], up[N];

int um1[N], up1[N];

int dp[N];
vector<int> vm[N], vp[N];

void ubd(vector<int>& t, int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(t, tl, m, x, y, pos * 2);
    else
        ubd(t, m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qry(vector<int>& t, int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return N;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(t, tl, m, l, min(m, r), pos * 2),
               qry(t, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();
        if (!s.empty())
            um[i] = s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] > a[i])
            s.pop();
        if (!s.empty())
            up[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[s.top()] < a[i])
            s.pop();
        if (!s.empty())
            um1[i] = s.top();
        else
            um1[i] = n;
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!s.empty() && a[s.top()] > a[i])
            s.pop();
        if (!s.empty())
            up1[i] = s.top();
        else
            up1[i] = n;
        s.push(i);
    }

    vector<int> tm, tp;
    tm.assign(n * 4 + 5, 0);
    tp.assign(n * 4 + 5, 0);
    for (int i = n; i >= 1; --i)
    {
        if (i == n)
            dp[i] = 0;
        else
        {
            if (a[i] == a[i + 1])
                dp[i] = dp[i + 1] + 1;
            else if (a[i] < a[i + 1])
                dp[i] = qry(tp, 1, n, i + 1, up1[i], 1) + 1;
            else
                dp[i] = qry(tm, 1, n, i + 1, um1[i], 1) + 1;
        }
        for (int j = 0; j < vm[i].size(); ++j)
            ubd(tm, 1, n, vm[i][j], N, 1);
        for (int j = 0; j < vp[i].size(); ++j)
            ubd(tp, 1, n, vp[i][j], N, 1);
        ubd(tm, 1, n, i, dp[i], 1);
        ubd(tp, 1, n, i, dp[i], 1);
        vm[um[i]].push_back(i);
        vp[up[i]].push_back(i);
    }

    printf("%d\n", dp[1]);
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
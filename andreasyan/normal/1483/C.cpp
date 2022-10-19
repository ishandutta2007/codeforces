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
const ll INF = 1000000009000000009;

int n;
int h[N], b[N];

ll dp[N];

ll laz[N * 4];
ll maxu[N * 4];

void shi(int pos)
{
    if (!laz[pos])
        return;
    laz[pos * 2] += laz[pos];
    maxu[pos * 2] += laz[pos];
    laz[pos * 2 + 1] += laz[pos];
    maxu[pos * 2 + 1] += laz[pos];
    laz[pos] = 0;
}

void ubd(int tl, int tr, int l, int r, ll y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        laz[pos] += y;
        maxu[pos] += y;
        return;
    }
    shi(pos);
    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);
    maxu[pos] = max(maxu[pos * 2], maxu[pos * 2 + 1]);
}

ll qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return -INF;
    if (tl == l && tr == r)
        return maxu[pos];
    shi(pos);
    int m = (tl + tr) / 2;
    return max(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && h[i] < h[s.top()])
        {
            int r = s.top();
            s.pop();
            int l = 0;
            if (!s.empty())
                l = s.top();
            ubd(0, n, l, r - 1, -b[r], 1);
        }
        int l = 0;
        if (!s.empty())
            l = s.top();
        ubd(0, n, l, i - 1, b[i], 1);
        s.push(i);
        dp[i] = qry(0, n, 0, i - 1, 1);
        ubd(0, n, i, i, dp[i], 1);
    }

    cout << dp[n] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
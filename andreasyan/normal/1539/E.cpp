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
const int N = 1000006;

int n, m;
int k[N], al[N], bl[N], ar[N], br[N];

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
        return n + 1;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(t, tl, m, l, min(m, r), pos * 2),
               qry(t, m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

vector<int> t1, t2;

int a[N], b[N];

int dp[N][2];
pair<int, int> p[N][2];

int ans[N];
void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> k[i] >> al[i] >> bl[i] >> ar[i] >> br[i];

    vector<int> v;
    for (int i = 0; i <= n; ++i)
    {
        v.push_back(al[i]);
        v.push_back(bl[i]);
        v.push_back(ar[i]);
        v.push_back(br[i]);
        v.push_back(k[i]);
    }
    sort(all(v));
    for (int i = 0; i <= n; ++i)
    {
        al[i] = lower_bound(all(v), al[i]) - v.begin() + 1;
        bl[i] = lower_bound(all(v), bl[i]) - v.begin() + 1;
        ar[i] = lower_bound(all(v), ar[i]) - v.begin() + 1;
        br[i] = lower_bound(all(v), br[i]) - v.begin() + 1;
        k[i] = lower_bound(all(v), k[i]) - v.begin() + 1;
    }

    t1.assign(sz(v) * 4 + 5, n + 1);
    t2.assign(sz(v) * 4 + 5, n + 1);
    for (int i = n; i >= 0; --i)
    {
        ubd(t1, 1, sz(v), al[i], i, 1);
        ubd(t2, 1, sz(v), bl[i], i, 1);
        a[i] = min(qry(t1, 1, sz(v), k[i] + 1, sz(v), 1),
                   qry(t2, 1, sz(v), 1, k[i] - 1, 1)) - 1;
    }

    t1.assign(sz(v) * 4 + 5, n + 1);
    t2.assign(sz(v) * 4 + 5, n + 1);
    for (int i = n; i >= 0; --i)
    {
        ubd(t1, 1, sz(v), ar[i], i, 1);
        ubd(t2, 1, sz(v), br[i], i, 1);
        b[i] = min(qry(t1, 1, sz(v), k[i] + 1, sz(v), 1),
                   qry(t2, 1, sz(v), 1, k[i] - 1, 1)) - 1;
    }

    dp[0][0] = b[0];
    dp[0][1] = a[0];

    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i][1] = -1;

        int ua = a[i - 1];
        int ub = dp[i - 1][0];
        if (ua >= i - 1 && a[i] >= i && ub >= i)
        {
            if (ub > dp[i][0])
            {
                dp[i][0] = ub;
                p[i][0] = m_p(0, 0);
            }
        }
        if (ua >= i && ub >= i - 1 && b[i] >= i)
        {
            if (ua > dp[i][1])
            {
                dp[i][1] = ua;
                p[i][1] = m_p(1, 0);
            }
        }

        ua = dp[i - 1][1];
        ub = b[i - 1];
        if (ua >= i - 1 && a[i] >= i && ub >= i)
        {
            if (ub > dp[i][0])
            {
                dp[i][0] = ub;
                p[i][0] = m_p(0, 1);
            }
        }
        if (ua >= i && ub >= i - 1 && b[i] >= i)
        {
            if (ua > dp[i][1])
            {
                dp[i][1] = ua;
                p[i][1] = m_p(1, 1);
            }
        }
    }

    if (dp[n][0] != -1 || dp[n][1] != -1)
    {
        cout << "Yes\n";
        int z;
        if (dp[n][0] != -1)
            z = 0;
        else
            z = 1;
        for (int i = n; i >= 1; --i)
        {
            ans[i] = z;
            z = p[i][z].se;
        }
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << ' ';
        cout << "\n";
    }
    else
    {
        cout << "No\n";
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
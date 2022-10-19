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
const int N = 400005;

int n;
int a[N], b[N];

vector<int> v1[N];
vector<int> v2[N];

int t[N * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] = min(t[pos], y);
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
}

int qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return N;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return min(qry(tl, m, l, min(m, r), pos * 2),
               qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

vector<int> v;

int solvv()
{
    int ans = 0;
    for (int i = 0; i < N * 4; ++i)
        t[i] = N;
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        for (int j = 0; j < v1[i].size(); ++j)
            ubd(0, sz(v), i, v1[i][j], 1);
        for (int j = 0; j < v2[i].size(); ++j)
        {
            if (qry(0, sz(v), i, sz(v), 1) <= v2[i][j])
                ans = max(ans, v[i] - v[v2[i][j]]);
        }
    }
    for (int i = 0; i < N * 4; ++i)
        t[i] = N;
    for (int i = 0; i < sz(v); ++i)
    {
        for (int j = 0; j < v1[i].size(); ++j)
            ubd(0, sz(v), i, v1[i][j], 1);
        for (int j = 0; j < v2[i].size(); ++j)
        {
            int l = v2[i][j], r = i;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (qry(0, sz(v), m, i, 1) <= v2[i][j])
                {
                    ans = max(ans, v[m] - v[v2[i][j]]);
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
        }
    }
    return ans;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
    {
        v.push_back(a[i]);
        v.push_back(b[i]);
    }
    sort(all(v));

    for (int i = 1; i <= n; ++i)
    {
        int aa = lower_bound(all(v), a[i]) - v.begin();
        int bb = lower_bound(all(v), b[i]) - v.begin();
        if (a[i] < b[i])
        {
            v1[bb].push_back(aa);
        }
        else if (a[i] > b[i])
        {
            v2[aa].push_back(bb);
        }
    }

    int ans = solvv();
    for (int i = 0; i < sz(v); ++i)
        swap(v1[i], v2[i]);
    ans = max(ans, solvv());

    ll yans = 0;
    for (int i = 1; i <= n; ++i)
        yans += abs(a[i] - b[i]);
    yans -= ans * 2;
    cout << yans << "\n";
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
        solv();
    return 0;
}
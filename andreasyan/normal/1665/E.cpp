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
const int N = 100005, m = 30;

int n;
int a[N];

int q;
int l[N], r[N];
int ans[N];
vector<int> u[N];

vector<int> v[N];
void solvv(int b)
{
    int xx = 0;
    for (int j = b + 1; j < m; ++j)
        xx |= (1 << j);

    vector<int> x;
    for (int i = 1; i <= n; ++i)
        x.push_back((a[i] & xx));
    sort(all(x));
    for (int i = 1; i <= sz(x); ++i)
        v[i].clear();

    for (int i = 1; i <= n; ++i)
    {
        if (!(a[i] & (1 << b)))
            v[lower_bound(all(x), (a[i] & xx)) - x.begin() + 1].push_back(i);
    }

    for (int i = 1; i <= q; ++i)
    {
        int qv = 0, qu = 0;

        int k = lower_bound(all(x), (ans[i] & xx)) - x.begin();
        if (0 <= k && k < sz(x) && x[k] == (ans[i] & xx))
        {
            ++k;
            if (!v[k].empty())
                qv += upper_bound(all(v[k]), r[i]) - lower_bound(all(v[k]), l[i]);
        }
        for (int j = 0; j < u[i].size(); ++j)
        {
            if (!(u[i][j] & (1 << b)))
                ++qu;
        }

        if (qv + qu >= 2)
        {
            vector<int> uu;
            for (int j = 0; j < u[i].size(); ++j)
            {
                if (!(u[i][j] & (1 << b)))
                    uu.push_back(u[i][j]);
            }
            u[i] = uu;
        }
        else
        {
            ans[i] |= (1 << b);
            if (qv == 1)
            {
                u[i].push_back(a[v[k][lower_bound(all(v[k]), l[i]) - v[k].begin()]]);
            }
        }
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> l[i] >> r[i];
        ans[i] = 0;
        u[i].clear();
    }

    for (int j = m - 1; j >= 0; --j)
    {
        solvv(j);
    }

    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
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
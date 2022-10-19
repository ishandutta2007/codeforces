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

int n;

vector<pair<int, int> > ans;

void rec(int l, int r)
{
    if (l == r)
        return;
    int m = (l + r) / 2;
    rec(l, m);
    rec(m + 1, r);
    for (int i = l, j = m + 1; i <= m; ++i, ++j)
        ans.push_back(m_p(i, j));
}

void solv()
{
    scanf("%d", &n);
    int q = 1;
    while (q * 2 <= n)
        q *= 2;
    rec(1, q);
    vector<int> v0;
    for (int i = 1; i <= q; ++i)
        v0.push_back(i);
    vector<vector<int> > vv;
    for (int i = q + 1; i <= n; ++i)
        vv.push_back({i});
    while (sz(vv) > 1)
    {
        vector<vector<int> > nvv;
        for (int i = 0; i < sz(vv); i += 2)
        {
            if (i == sz(vv) - 1)
            {
                vector<int> v;
                for (int j = 0; j < sz(vv[i]); ++j)
                {
                    ans.push_back(m_p(vv[i][j], v0.back()));
                    v.push_back(vv[i][j]);
                    v.push_back(v0.back());
                    v0.pop_back();
                }
                nvv.push_back(v);
            }
            else
            {
                vector<int> v;
                for (int j = 0; j < sz(vv[i]); ++j)
                {
                    ans.push_back(m_p(vv[i][j], vv[i + 1][j]));
                    v.push_back(vv[i][j]);
                    v.push_back(vv[i + 1][j]);
                }
                nvv.push_back(v);
            }
        }
        vv = nvv;
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); ++i)
        printf("%d %d\n", ans[i].fi, ans[i].se);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    tt = 1;
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
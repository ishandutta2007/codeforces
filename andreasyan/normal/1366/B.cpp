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

pair<int, int> hat(pair<int, int> a, pair<int, int> b)
{
    return m_p(max(a.fi, b.fi), min(a.se, b.se));
}

void solv()
{
    int n, x, m;
    scanf("%d%d%d", &n, &x, &m);
    vector<pair<int, int> > ans;
    ans.push_back(m_p(x, x));
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        for (int i = 0; i < ans.size(); ++i)
        {
            if (hat(ans[i], m_p(l, r)).fi <= hat(ans[i], m_p(l, r)).se)
            {
                ans.push_back(m_p(l, r));
                break;
            }
        }
    }
    vector<pair<int, int> > v;
    for (int i = 0; i < ans.size(); ++i)
    {
        v.push_back(m_p(ans[i].fi, 1));
        v.push_back(m_p(ans[i].se + 1, -1));
    }
    sort(all(v));
    int yans = 0;
    int p = 0;
    for (int i = 0; i < sz(v) - 1; ++i)
    {
        p += v[i].se;
        if (p > 0)
            yans += (v[i + 1].fi - v[i].fi);
    }
    printf("%d\n", yans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
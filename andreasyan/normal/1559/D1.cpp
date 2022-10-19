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
const int N = 100005;

int n, m1, m2;

int p1[N];
int p2[N];

int fi(int x, int p[])
{
    if (x == p[x])
        return x;
    return fi(p[x], p);
}

void kpc(int x, int y, int p[])
{
    x = fi(x, p);
    y = fi(y, p);
    p[x] = y;
}

void solv()
{
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; ++i)
        p1[i] = p2[i] = i;
    for (int i = 0; i < m1; ++i)
    {
        int x, y;
        cin >> x >> y;
        kpc(x, y, p1);
    }
    for (int i = 0; i < m2; ++i)
    {
        int x, y;
        cin >> x >> y;
        kpc(x, y, p2);
    }

    vector<pair<int, int> > ans;
    vector<int> v[3];
    set<int> s[3];
    for (int x = 1; x <= 1; ++x)
    {
        for (int y = x + 1; y <= n; ++y)
        {
            if (fi(x, p1) != fi(y, p1) && fi(x, p2) != fi(y, p2))
            {
                kpc(x, y, p1);
                kpc(x, y, p2);
                ans.push_back(m_p(x, y));
            }
        }
        for (int y = x + 1; y <= n; ++y)
        {
            if (fi(x, p1) == fi(y, p1) && fi(x, p2) != fi(y, p2) && s[1].find(fi(y, p2)) == s[1].end())
            {
                v[1].push_back(y);
                s[1].insert(fi(y, p2));
            }
            else if (fi(x, p1) != fi(y, p1) && fi(x, p2) == fi(y, p2) && s[2].find(fi(y, p1)) == s[2].end())
            {
                v[2].push_back(y);
                s[2].insert(fi(y, p1));
            }
        }
    }

    for (int i = 0; i < min(sz(v[1]), sz(v[2])); ++i)
    {
        int x = v[1][i];
        int y = v[2][i];
        assert(fi(x, p1) != fi(y, p1) && fi(x, p2) != fi(y, p2));
        {
            kpc(x, y, p1);
            kpc(x, y, p2);
            ans.push_back(m_p(x, y));
        }
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
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
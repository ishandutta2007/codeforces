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

struct ban
{
    int x, q, i;
    ban(){}
    ban(int x, int q, int i)
    {
        this->x = x;
        this->q = q;
        this->i = i;
    }
};

vector<ban> vv[33];

void solv()
{
    int n;
    cin >> n;

    int z = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;

        vector<int> v;
        while (1)
        {
            v.push_back(x);
            if (x == 0)
                break;
            int l = 0, r = 30;
            int u = -1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (x <= (1 << m))
                {
                    u = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            x = (1 << u) - x;
        }

        reverse(all(v));

        for (int j = 0; j < sz(v); ++j)
        {
            vv[j].push_back(ban(v[j], sz(v) - j, i));
        }
        vv[sz(v)].push_back(ban(--z, 0, i));
    }

    int ans = 0;
    int ansi = 1, ansj = 2;

    for (int i = 0; i < 33; ++i)
    {
        map<int, pair<int, int> > mp;
        for (int j = 0; j < sz(vv[i]); ++j)
        {
            mp[vv[i][j].x] = max(mp[vv[i][j].x], m_p(vv[i][j].q, vv[i][j].i));
        }

        pair<int, int> max1, max2;
        max1 = max2 = m_p(-100, -1);
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->se >= max1)
            {
                max2 = max1;
                max1 = it->se;
            }
            else if (it->se > max2)
            {
                max2 = it->se;
            }
        }

        if (max1.fi + max2.fi > ans)
        {
            ans = max1.fi + max2.fi;
            ansi = max1.se;
            ansj = max2.se;
        }
    }

    cout << ansi << ' ' << ansj << ' ' << ans << "\n";
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
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
const int N = 200005;
const int xx[4] = {1, 0, -1, 0};
const int yy[4] = {0, 1, 0, -1};

int n;
map<pair<int, int>, int> mp;

pair<int, int> ans[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        mp[m_p(x, y)] = i;
    }

    queue<pair<int, int> > q;
    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        for (int i = 0; i < 4; ++i)
        {
            int hx = it->fi.fi + xx[i];
            int hy = it->fi.se + yy[i];
            if (mp.find(m_p(hx, hy)) == mp.end())
            {
                ans[it->se] = m_p(hx, hy);
                q.push(it->fi);
                break;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int hx = x + xx[i];
            int hy = y + yy[i];
            if (mp.find(m_p(hx, hy)) != mp.end())
            {
                int h = mp[m_p(hx, hy)];
                if (ans[h] == m_p(0, 0))
                {
                    ans[h] = ans[mp[m_p(x, y)]];
                    q.push(m_p(hx, hy));
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
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
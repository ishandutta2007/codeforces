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

void solv(int n)
{
    vector<pair<int, int> > ans;
    for (int i = 1; i <= 6; ++i)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= 8; ++j)
            {
                ans.push_back(m_p(i, j));
            }
        }
        else
        {
            for (int j = 8; j >= 1; --j)
            {
                ans.push_back(m_p(i, j));
            }
        }
    }

    for (int j = 1; j <= 6; ++j)
    {
        if (j % 2 == 1)
        {
            ans.push_back(m_p(7, j));
            ans.push_back(m_p(8, j));
        }
        else
        {
            ans.push_back(m_p(8, j));
            ans.push_back(m_p(7, j));
        }
    }

    if (n == 62)
    {
        ans.push_back(m_p(7, 7));
        ans.push_back(m_p(8, 7));
        ans.push_back(m_p(8, 8));

        vector<pair<int, int> > yans = ans;
        for (int i = 0; i < sz(yans); ++i)
        {
            cout << (char)(yans[i].se - 1 + 'a');
            cout << yans[i].fi;
            cout << ' ';
        }
        cout << "\n";
        return;
    }

    ans.push_back(m_p(7, 8));
    ans.push_back(m_p(7, 7));
    ans.push_back(m_p(8, 7));
    ans.push_back(m_p(8, 8));

    bool c[9][9] = {};
    vector<pair<int, int> > yans;
    for (int i = 0; i < sz(ans); ++i)
    {
        yans.push_back(ans[i]);
        c[ans[i].fi][ans[i].se] = true;

        if (n == 1)
        {
            if (ans[i].fi == 8 || ans[i].se == 8)
            {
                yans.push_back(m_p(8, 8));
                break;
            }
            assert(false);
        }
        if (n == 2)
        {
            bool z = false;
            for (int x = 1; x <= 8; ++x)
            {
                for (int y = 1; y <= 8; ++y)
                {
                    if (c[x][y])
                        continue;
                    if (x == 8 && y == 8)
                        continue;
                    if (ans[i].fi == x || ans[i].se == y)
                    {
                        if (x == 8 || y == 8)
                        {
                            yans.push_back(m_p(x, y));
                            yans.push_back(m_p(8, 8));
                            z = true;
                            break;
                        }
                    }
                }
                if (z)
                    break;
            }
            if (z)
                break;
        }

        --n;
    }

    for (int i = 0; i < sz(yans); ++i)
    {
        cout << (char)(yans[i].se - 1 + 'a');
        cout << yans[i].fi;
        cout << ' ';
    }
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (int n = 2; n <= 63; ++n)
    {
        solv(n);
    }
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        solv(n);
    }
    return 0;
}
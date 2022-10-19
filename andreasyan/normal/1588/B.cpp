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

map<pair<int, int>, ll> mp;
ll qry(int l, int r)
{
    if (mp.find(m_p(l, r)) != mp.end())
        return mp[m_p(l, r)];
    cout << "? " << l << ' ' << r << endl;
    ll ans;
    cin >> ans;
    return mp[m_p(l, r)] = ans;
}

ll inv(int l, int r)
{
    return (r - l + 1) * 1LL * (r - l) / 2;
}

void solv()
{
    mp.clear();

    int n;
    cin >> n;

    int l = 1, r = n;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (qry(1, m) == 0)
        {
            l = m + 1;
        }
        else if (qry(1, m) == qry(1, n))
        {
            r = m - 1;
        }
        else
        {
            int x = m - (qry(1, m) - qry(1, m - 1));

            if (qry(1, x) == 0)
            {
                int i = x;
                l = i + 1;
                int j;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    if (qry(1, m) != inv(i, m))
                    {
                        j = m;
                        r = m - 1;
                    }
                    else
                        l = m + 1;
                }

                l = j + 1, r = n;
                int k;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    if (inv(i, j - 1) + inv(j, m) == qry(1, n))
                    {
                        k = m;
                        break;
                    }
                    if (inv(i, j - 1) + inv(j, m) < qry(1, n))
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m - 1;
                    }
                }

                cout << "! " << i << ' ' << j << ' ' << k << endl;
                return;
            }
            else
            {
                int j = x;
                int i = j - 1 - (qry(1, j - 1) - qry(1, j - 2));

                l = j + 1, r = n;
                int k;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    if (inv(i, j - 1) + inv(j, m) == qry(1, n))
                    {
                        k = m;
                        break;
                    }
                    if (inv(i, j - 1) + inv(j, m) < qry(1, n))
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m - 1;
                    }
                }

                cout << "! " << i << ' ' << j << ' ' << k << endl;
                return;
            }
        }
    }
    assert(false);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
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
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

int n, a, b, c;
char s[N];

ll solvv(bool z)
{
    vector<pair<char, int> > v;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] != s[i - 1])
            v.push_back(m_p(s[i], 1));
        else
            v.back().se++;
    }

    int q[2] = {};
    for (int i = 0; i < sz(v); ++i)
        q[v[i].fi - '0'] += v[i].se - 1;

    vector<int> vv;
    vector<int> vvv;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i].fi == '0')
        {
            if (i - 1 >= 0 && v[i - 1].fi == '1' && i + 1 < sz(v) && v[i + 1].fi == '1')
            {
                vv.push_back(v[i].se - 1);
            }
            else
            {
                vvv.push_back(v[i].se - 1);
            }
        }
    }

    sort(all(vv));
    reverse(all(vv));

    int qq = 0;
    while (!vv.empty() && vv.back() == 0)
    {
        ++qq;
        vv.pop_back();
    }

    sort(all(vvv));
    reverse(all(vvv));

    int qqq = 0;
    while (!vvv.empty() && vvv.back() == 0)
    {
        ++qqq;
        vvv.pop_back();
    }

    ll ans = 0;
    while (1)
    {
        if (!z)
        {
            if (qq && b > c)
            {
                --qq;
                ++q[1];

                ans -= c;
            }
            else if (q[0] && (qq == 0 || b - c <= a))
            {
                --q[0];
                if (!vv.empty())
                    vv.back()--;
                else if (!vvv.empty())
                    vvv.back()--;

                if (!vv.empty() && vv.back() == 0)
                {
                    ++qq;
                    vv.pop_back();
                }
                if (!vvv.empty() && vvv.back() == 0)
                {
                    ++qqq;
                    vvv.pop_back();
                }

                ans += a;
            }
            else if (qqq && b > c && q[1])
            {
                --qqq;

                ans -= c;
            }
            else
                break;
        }
        else
        {
            if (q[1])
            {
                --q[1];

                ans += b;
            }
            else
                break;
        }
        z ^= true;
    }

    return ans;
}

void solv()
{
    cin >> n >> a >> b >> c;
    cin >> (s + 1);

    cout << max(solvv(false), solvv(true)) << "\n";
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
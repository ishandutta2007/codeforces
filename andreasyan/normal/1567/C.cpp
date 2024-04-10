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

void solv()
{
    int n;
    cin >> n;

    vector<int> v;
    while (n)
    {
        v.push_back((n % 10));
        n /= 10;
    }

    reverse(all(v));

    ll ans = 0;
    for (int x = 0; x < (1 << sz(v)); ++x)
    {
        bool z = true;
        for (int i = 0; i < sz(v); ++i)
        {
            if ((x & (1 << i)))
            {
                if (i + 2 >= sz(v))
                {
                    z = false;
                    break;
                }
            }
        }
        if (!z)
            continue;
        for (int i = 0; i < sz(v); ++i)
        {
            if ((x & (1 << i)))
            {
                v[i]--;
                v[i + 2] += 10;
            }
        }

        ll yans = 1;
        for (int i = 0; i < sz(v); ++i)
        {
            if (v[i] >= 0)
            {
                int q = 0;
                for (int j = 0; j <= min(9, v[i]); ++j)
                {
                    if (v[i] - j <= 9)
                        ++q;
                }
                yans *= q;
            }
            else
                yans = 0;
        }

        bool h = true;
        for (int i = 0; i < sz(v); ++i)
        {
            if (v[i] < 0)
                h = false;
            if (v[i] > 9)
                h = false;
        }

        ans += yans;
        ans -= h * 2;

        for (int i = 0; i < sz(v); ++i)
        {
            if ((x & (1 << i)))
            {
                v[i]++;
                v[i + 2] -= 10;
            }
        }
    }

    cout << ans << "\n";
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
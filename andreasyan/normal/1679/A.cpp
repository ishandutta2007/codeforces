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

void solv()
{
    ll n;
    cin >> n;

    ll minu = -1;
    set<ll> s;
    for (ll q = 0; q * 4 <= n; ++q)
    {
        if (s.find((n - q * 4) % 6) != s.end())
            break;
        s.insert((n - q * 4) % 6);
        if ((n - q * 4) % 6 == 0)
        {
            minu = q + (n - q * 4) / 6;
            break;
        }
    }

    ll maxu = -1;
    s.clear();
    for (ll q = 0; q * 6 <= n; ++q)
    {
        if (s.find((n - q * 6) % 4) != s.end())
            break;
        s.insert((n - q * 6) % 4);
        if ((n - q * 6) % 4 == 0)
        {
            maxu = q + (n - q * 6) / 4;
            break;
        }
    }

    if (minu == -1)
    {
        cout << "-1\n";
    }
    else
    {
        cout << minu << ' ' << maxu << "\n";
    }
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
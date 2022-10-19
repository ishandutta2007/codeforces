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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

ll qry(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
    ll ans;
    cin >> ans;
    return ans;
}

void solv()
{
    int ans = 0;
    for (int i = 0; i < 30; ++i)
    {
        int a = 1;
        int b = 1 + (1 << (i + 1));
        for (int j = 0; j < i; ++j)
        {
            if (!(ans & (1 << j)))
            {
                a += (1 << j);
                b += (1 << j);
            }
        }
        if ((qry(a, b) % (1 << (i + 1))) == 0)
            ans |= (1 << i);
    }
    cout << "! " << ans << endl;
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
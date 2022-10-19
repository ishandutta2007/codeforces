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

ll u[20];
void pre()
{
    u[0] = 2050;
    for (int i = 1; i <= 14; ++i)
        u[i] = (u[i - 1] * 10);
    assert(u[14] * 10 > 1000000000000000000);
}

void solv()
{
    ll n;
    cin >> n;

    ll ans = 0;
    for (int i = 14; i >= 0; --i)
    {
        ans += n / u[i];
        n %= u[i];
    }

    if (n == 0)
        cout << ans << "\n";
    else
        cout << "-1\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
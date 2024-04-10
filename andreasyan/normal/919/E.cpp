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

int a, b, p;
ll x;

int ast(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * 1LL * x) % p;
        x = (x * 1LL * x) % p;
        n /= 2;
    }
    return ans;
}

void solv()
{
    cin >> a >> b >> p >> x;

    ll ans = 0;
    for (int i = 0; i <= min(x, p - 2LL); ++i)
    {
        int u = (b * 1LL * ast(ast(a, i), p - 2)) % p;

        ll y = (x - i) / (p - 1);

        u = (u - i + p) % p;
        u = (u * 1LL * ast(p - 1, p - 2)) % p;

        if (y >= u)
        {
            ans += (y - u) / p + 1;
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
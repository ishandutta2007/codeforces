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
    ll n, a, b;
    cin >> n >> a >> b;

    if (a == 1)
    {
        if (b == 1 || n % b == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
        return;
    }

    ll x = 1;
    for (int i = 0; ; ++i)
    {
        if (n < x)
            break;
        if ((n - x) % b == 0)
        {
            cout << "Yes\n";
            return;
        }
        x *= a;
    }
    cout << "No\n";
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
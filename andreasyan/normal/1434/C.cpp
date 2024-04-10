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
const int N = 1000;

ll a, b, c, d;

void por()
{
    int a[N] = {};
    cin >> c >> d;
    int q = 0;
    for (int i = 0; i < N / 2; ++i)
    {
        if (i % d == 0)
        {
            a[i + 1]++;
            a[i + c + 1]--;
        }
        q += a[i];
        cout << q << ' ';
    }
}

void solv()
{
    cin >> a >> b >> c >> d;
    if (d > c)
    {
        if (-a + c * b < 0)
        {
            cout << "-1" << endl;
            return;
        }
        cout << a << endl;
        return;
    }
    ll x = (c % d) * (c / d + 1) * b + (d - c % d) * (c / d) * b - a;
    if (x < 0)
    {
        cout << "-1" << endl;
        return;
    }
    x = a / (d * b);
    cout << (x + 1) * a - x * (x + 1) / 2 * d * b << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
    //por();
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}
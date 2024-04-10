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
const int N = 100005;

int n;
int a[N];

int b[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int m = n;
    if (m % 2 == 1)
        m -= 3;

    for (int i = 1; i <= m / 2; ++i)
        b[i] = a[m - i + 1];
    for (int i = m / 2 + 1; i <= m; ++i)
        b[i] = -a[m - i + 1];

    if (m != n)
    {
        if (a[n - 2] + a[n - 1] != 0)
        {
            b[n - 2] = a[n];
            b[n - 1] = a[n];
            b[n] = -(a[n - 2] + a[n - 1]);
        }
        else if (a[n - 2] + a[n] != 0)
        {
            b[n - 2] = a[n - 1];
            b[n - 1] = -(a[n - 2] + a[n]);
            b[n] = a[n - 1];
        }
        else
        {
            b[n - 2] = -(a[n - 1] + a[n]);
            b[n - 1] = a[n - 2];
            b[n] = a[n - 2];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << b[i] << ' ';
    }
    cout << "\n";

    ll s = 0;
    for (int i = 1; i <= n; ++i)
        s += a[i] * b[i];
    assert(s == 0);
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
        solv();
    return 0;
}
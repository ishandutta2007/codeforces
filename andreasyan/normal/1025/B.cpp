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
const int N = 150005;

int n;
int a[N], b[N];

bool stg(int x)
{
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % x != 0 && b[i] % x != 0)
            return false;
    }
    return true;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
    }

    int x = a[1];
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            if (stg(i))
            {
                cout << i << "\n";
                return;
            }
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
    {
        if (stg(x))
        {
            cout << x << "\n";
            return;
        }
    }

    x = b[1];
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            if (stg(i))
            {
                cout << i << "\n";
                return;
            }
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
    {
        if (stg(x))
        {
            cout << x << "\n";
            return;
        }
    }

    cout << "-1\n";
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
        solv();
    return 0;
}
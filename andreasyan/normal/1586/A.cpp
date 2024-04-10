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
const int N = 102;

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int s = 0;
    for (int i = 1; i <= n; ++i)
    {
        s += a[i];
    }

    bool z = false;
    for (int i = 2; i < s; ++i)
    {
        if (s % i == 0)
        {
            z = true;
            break;
        }
    }

    if (z)
    {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 1)
        {
            cout << n - 1 << "\n";
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    continue;
                cout << j << ' ';
            }
            cout << "\n";
            return;
        }
    }

    assert(false);
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
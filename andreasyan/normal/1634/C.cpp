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
const int N = 503;

void solv()
{
    int n, k;
    cin >> n >> k;

    if (k == 1)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i)
            cout << i << "\n";
        return;
    }

    if (n % 2 == 1)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 1; i <= n / 2; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            int u = (i - 1) * k + j;
            cout << u * 2 << ' ';
        }
        cout << "\n";
    }
    for (int i = 1; i <= n / 2; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            int u = (i - 1) * k + j;
            cout << u * 2 - 1 << ' ';
        }
        cout << "\n";
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
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

int n, m, k;
int a[N];

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i)
    {
        cin >> a[i];
    }

    ll q = 0;
    int maxu = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (a[i] / n > 1)
        {
            q += (a[i] / n);
            maxu = max(maxu, (a[i] / n));
        }
    }
    if ((q >= m && maxu > 2) || (q >= m && maxu == 2 && m % 2 == 0))
    {
        cout << "Yes\n";
        return;
    }

    swap(n, m);

    q = 0;
    maxu = 0;
    for (int i = 1; i <= k; ++i)
    {
        if (a[i] / n > 1)
        {
            q += (a[i] / n);
            maxu = max(maxu, (a[i] / n));
        }
    }
    if ((q >= m && maxu > 2) || (q >= m && maxu == 2 && m % 2 == 0))
    {
        cout << "Yes\n";
        return;
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
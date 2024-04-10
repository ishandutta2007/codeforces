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

int n, k, b;
ll s;

ll a[N];

void solv()
{
    cin >> n >> k >> b >> s;
    for (int i = 1; i <= n; ++i)
        a[i] = 0;
    a[1] = b * 1LL * k;
    if (a[1] > s)
    {
        cout << "-1\n";
        return;
    }
    s -= a[1];
    for (int i = 1; i <= n; ++i)
    {
        if (s >= k - 1)
        {
            a[i] += (k - 1);
            s -= (k - 1);
        }
        else
        {
            a[i] += s;
            s = 0;
        }
    }

    if (s)
    {
        cout << "-1\n";
        return;
    }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << "\n";
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
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
const int N = 200005;

int n, m;
char a[N];

int p[N];

void solv()
{
    cin >> n >> m;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1] + a[i] - '0');

    ll q = p[n] * 1LL * m;
    if (q % n != 0)
    {
        cout << "-1\n";
        return;
    }
    q /= n;

    for (int i = m; i <= n; ++i)
    {
        if (p[i] - p[i - m] == q)
        {
            cout << "1\n";
            cout << i - m + 1 << ' ' << i << "\n";
            return;
        }
    }

    for (int i = 1; i < m; ++i)
    {
        if (p[i] + p[n] - p[n - (m - i)] == q)
        {
            cout << "2\n";
            cout << "1 " << i << "\n";
            cout << n - (m - i) + 1 << ' ' << n << "\n";
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
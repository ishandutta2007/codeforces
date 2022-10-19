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

int n;
char a[N];
char b[N];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        a[i] -= '0';
        q += a[i];
    }

    if (q == 0 || q % 2 == 1)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        b[i] = a[i];
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == 0)
        {
            if (i == 1)
            {
                cout << n << ' ' << i << "\n";
                b[n] ^= 1;
                b[i] ^= 1;
            }
            else
            {
                cout << i - 1 << ' ' << i << "\n";
                b[i - 1] ^= 1;
                b[i] ^= 1;
            }
        }
    }

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i])
            v.push_back(i);
    }
    assert(sz(v) % 2 == 0);
    for (int i = 1; i < sz(v); ++i)
    {
        cout << v[0] << ' ' << v[i] << "\n";
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
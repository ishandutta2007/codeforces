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
const int N = 300005;

int n;
char c;
char a[N];

void solv()
{
    cin >> n >> c;
    cin >> (a + 1);

    bool f = true;
    for (int i = 1; i <= n; ++i)
    {
        if (c != a[i])
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        cout << "0\n";
        return;
    }

    for (int x = 1; x <= n; ++x)
    {
        bool f = true;
        for (int i = x; i <= n; i += x)
        {
            if (a[i] != c)
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            cout << "1\n";
            cout << x << "\n";
            return;
        }
    }

    cout << "2\n";
    cout << n - 1 << ' ' << n << "\n";
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
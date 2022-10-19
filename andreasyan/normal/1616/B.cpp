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
char a[N];

void solv()
{
    cin >> n;
    cin >> a;

    if (n == 1)
    {
        cout << a[0] << a[0] << "\n";
        return;
    }

    if (a[0] == a[1])
    {
        cout << a[0] << a[0] << "\n";
        return;
    }

    int m = n;
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > a[i - 1])
        {
            m = i;
            break;
        }
    }

    bool z = true;
    for (int i = 0; i < m; ++i)
    {
        if (a[i] != a[0])
        {
            z = false;
            break;
        }
    }

    if (z)
    {
        cout << a[0] << a[0] << "\n";
        return;
    }

    for (int i = 0; i < m; ++i)
        cout << a[i];
    for (int i = m - 1; i >= 0; --i)
        cout << a[i];
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
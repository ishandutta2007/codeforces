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
const int N = 1000006;

int n;
char a[N], b[N];

char c[N];

void solv()
{
    cin >> n;
    cin >> a >> b;

    if (a[0] != b[0])
    {
        for (int i = 0; i < n; ++i)
            cout << '1';
        cout << '\n';
        return;
    }

    if (b[n - 1] == '1')
    {
        cout << b << '\n';
        return;
    }

    bool z = true;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != b[i])
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        cout << b << '\n';
        return;
    }

    for (int i = 0; i < n; ++i)
        c[i] = b[i];
    for (int i = n - 1; i >= 0; --i)
    {
        if (c[i] == '1')
        {
            c[i] = '0';
            break;
        }
        else
            c[i] = '1';
    }

    z = true;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != c[i])
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        cout << b << '\n';
        return;
    }

    b[n - 1] = '1';
    cout << b << '\n';
}

void solv0()
{
    cin >> n;
    cin >> a >> b;

    int x = 0, y = 0;
    for (int i = 0; i < n; ++i)
    {
        x = (x * 2 + a[i] - '0');
        y = (y * 2 + b[i] - '0');
    }

    int ans = 0;
    for (int l = x; l <= y; ++l)
    {
        int yans = 0;
        for (int r = l; r <= y; ++r)
        {
            yans ^= r;
            ans = max(ans, yans);
        }
    }

    for (int i = n - 1; i >= 0; --i)
    {
        if ((ans & (1 << i)))
            cout << '1';
        else
            cout << '0';
    }
    cout << '\n';
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
    {
        solv();
    }
    return 0;
}
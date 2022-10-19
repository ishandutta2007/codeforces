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
char u[N];

char a[N];
char b[N];

void solv()
{
    cin >> n;
    cin >> u;

    a[n] = b[n] = 0;

    int q = 0;
    for (int i = 0; i < n; ++i)
    {
        if (u[i] == '1')
            ++q;
    }

    if (q % 2 == 1)
    {
        cout << "NO\n";
        return;
    }

    int z = 0;
    for (int i = 0; i < n; ++i)
    {
        if (u[i] == '1')
        {
            if (z < q / 2)
                a[i] = b[i] = '(';
            else
                a[i] = b[i] = ')';
            ++z;
        }
    }

    z = 0;
    for (int i = 0; i < n; ++i)
    {
        if (u[i] == '0')
        {
            if (z % 2 == 0)
            {
                a[i] = '(';
                b[i] = ')';
            }
            else
            {
                a[i] = ')';
                b[i] = '(';
            }
            ++z;
        }
    }

    int p = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '(')
            ++p;
        else
            --p;
        if (p < 0)
        {
            cout << "NO\n";
            return;
        }
    }

    p = 0;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] == '(')
            ++p;
        else
            --p;
        if (p < 0)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    cout << a << "\n";
    cout << b << "\n";
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
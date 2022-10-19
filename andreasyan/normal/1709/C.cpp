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

void solv()
{
    cin >> (a + 1);
    for (n = 1; a[n]; ++n){}
    --n;

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '?')
            v.push_back(i);
    }

    int qb = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '(')
            ++qb;
    }

    if (n / 2 - qb == sz(v) || n / 2 - qb == 0)
    {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < (n / 2 - qb - 1); ++i)
        a[v[i]] = '(';
    a[v[(n / 2 - qb - 1)]] = ')';
    a[v[(n / 2 - qb)]] = '(';
    for (int i = (n / 2 - qb + 1); i < sz(v); ++i)
        a[v[i]] = ')';

    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == '(')
            ++p;
        else if (a[i] == ')')
            --p;
        else
            assert(false);
        if (p < 0)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
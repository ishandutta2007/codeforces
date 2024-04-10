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
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    int z = -1;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[n - i + 1])
        {
            z = i;
            break;
        }
    }

    if (z == -1)
    {
        cout << "YES\n";
        return;
    }

    vector<int> v;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[z])
            v.push_back(a[i]);
    }

    bool f = true;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i] != v[sz(v) - i - 1])
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        cout << "YES\n";
        return;
    }


    v.clear();
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[n - z + 1])
            v.push_back(a[i]);
    }

    f = true;
    for (int i = 0; i < sz(v); ++i)
    {
        if (v[i] != v[sz(v) - i - 1])
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        cout << "YES\n";
        return;
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
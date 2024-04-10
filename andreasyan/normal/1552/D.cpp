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
const int N = 12;

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        a[i] = abs(a[i]);
    sort(a + 1, a + n + 1);

    if (a[1] == 0)
    {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] == a[i + 1])
        {
            cout << "YES\n";
            return;
        }
    }

    vector<int> v;
    for (int x = 0; x < (1 << n); ++x)
    {
        int s = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((x & (1 << i)))
                s += a[i + 1];
        }
        v.push_back(s);
    }
    sort(all(v));
    for (int i = 0; i < sz(v) - 1; ++i)
    {
        if (v[i] == v[i + 1])
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
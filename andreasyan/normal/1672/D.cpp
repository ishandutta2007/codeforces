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
int a[N], b[N];

int t[N];
int u[N];
int q[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        t[i] = 0;
    for (int i = n; i >= 1; --i)
    {
        u[i] = t[a[i]];
        t[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i)
        q[i] = 1;

    int j = 1;
    for (int i = 1; i <= n; ++i)
    {
        while (a[i] == b[j] && q[i] > 0)
        {
            --q[i];
            ++j;
        }
        q[u[i]] += q[i];
    }

    if (j == n + 1)
        cout << "YES\n";
    else
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
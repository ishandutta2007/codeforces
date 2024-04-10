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
const int N = 100005, M = 1000000007;

int n;
int a[N], b[N], c[N];

int u[N];
bool cc[N];
bool t[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= n; ++i)
        cin >> c[i];

    for (int i = 1; i <= n; ++i)
    {
        cc[i] = false;
        t[i] = false;
    }

    for (int i = 1; i <= n; ++i)
    {
        u[a[i]] = b[i];
        if (c[i])
            cc[a[i]] = true;
    }

    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (t[i])
            continue;
        int x = i;
        bool z = false;
        while (1)
        {
            if (t[x])
                break;
            t[x] = true;
            z |= cc[x];
            x = u[x];
        }

        if (!z && u[x] != x)
            ans = (ans * 2) % M;
    }

    cout << ans << "\n";
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
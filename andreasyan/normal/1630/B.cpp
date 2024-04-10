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

int n, k;
int a[N];

int q[N];
int p[N];

void solv()
{
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
    {
        q[i] = 0;
        p[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
        ++q[a[i]];
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + q[i];

    int ans = n;
    int l0, r0;
    for (int i = 1; i <= n; ++i)
    {
        int l = 1, r = i;
        int u = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[i] - p[m - 1] >= k + n - (p[i] - p[m - 1]))
            {
                u = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }

        if (u)
        {
            if (i - u < ans)
            {
                ans = i - u;
                l0 = u;
                r0 = i;
            }
        }
    }

    cout << l0 << ' ' << r0 << "\n";
    for (int i = 1; i <= n; ++i)
    {
        if (l0 <= a[i] && a[i] <= r0)
            a[i] = 1;
        else
            a[i] = -1;
    }

    int qq = 0;
    int y = 1;
    for (int i = 1; i <= n; ++i)
    {
        qq += a[i];
        if (qq > 0)
        {
            --k;
            if (k == 0)
            {
                cout << y << ' ' << n << "\n";
                break;
            }
            cout << y << ' ' << i << "\n";
            y = i + 1;
            qq = 0;
        }
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
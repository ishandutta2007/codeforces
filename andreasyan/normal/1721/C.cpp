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

int p[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] <= b[i - 1])
            ++p[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        assert(b[i] >= a[i]);
        int l = 1, r = i;
        int ans = b[i] - a[i];
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (b[m] >= a[i])
            {
                ans = b[m] - a[i];
                r = m - 1;
            }
            else
                l = m + 1;
        }
        cout << ans << ' ';
    }
    cout << "\n";

    for (int i = 1; i <= n; ++i)
    {
        int l = i, r = n;
        int ans = b[i] - a[i];
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (p[m] - p[i] == m - i)
            {
                ans = b[m] - a[i];
                l = m + 1;
            }
            else
                r = m - 1;
        }
        cout << ans << ' ';
    }
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
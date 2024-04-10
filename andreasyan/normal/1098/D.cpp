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
const int N = 500005, m = 30;

int n;
int a[N];

ll t[m];
multiset<int> s[m];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        char x;
        cin >> x >> a[i];
        if (x == '-')
            a[i] *= -1;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > 0)
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if ((a[i] & (1 << j)))
                {
                    s[j].insert(a[i]);
                    break;
                }
                t[j] += a[i];
            }
        }
        else
        {
            for (int j = m - 1; j >= 0; --j)
            {
                if (((-a[i]) & (1 << j)))
                {
                    s[j].erase(s[j].find(-a[i]));
                    break;
                }
                t[j] += a[i];
            }
        }

        int ans = 0;
        for (int j = 0; j < m; ++j)
        {
            ans += sz(s[j]);
            if (*s[j].begin() > 2 * t[j])
                --ans;
        }

        cout << ans << "\n";
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
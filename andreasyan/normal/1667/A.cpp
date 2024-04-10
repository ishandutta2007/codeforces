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
const int N = 5003;

int n;
int a[N];

ll b[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll ans;
    for (int i = 1; i <= n; ++i)
    {
        ll yans = 0;

        b[i] = 0;
        for (int j = i + 1; j <= n; ++j)
        {
            yans += (b[j - 1] / a[j]);
            b[j] = (b[j - 1] / a[j]) * a[j];

            if (b[j] <= b[j - 1])
            {
                ++yans;
                b[j] += a[j];
            }
        }
        for (int j = i - 1; j >= 1; --j)
        {
            yans += (b[j + 1] / a[j]);
            b[j] = (b[j + 1] / a[j]) * a[j];

            if (b[j] <= b[j + 1])
            {
                ++yans;
                b[j] += a[j];
            }
        }

        if (i == 1)
            ans = yans;
        else
            ans = min(ans, yans);
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
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
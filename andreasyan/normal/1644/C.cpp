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

int n, x;
int a[N];

int ans[N];

void solv()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ans[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int s = 0;
        for (int j = i; j <= n; ++j)
        {
            s += a[j];
            ans[0] = max(ans[0], s);

            if (i == 1)
                ans[j - i + 1] = s;
            else
                ans[j - i + 1] = max(ans[j - i + 1], s);
        }
    }

    for (int k = n - 1; k >= 1; --k)
        ans[k] = max(ans[k], ans[k + 1]);

    for (int k = 1; k <= n; ++k)
    {
        ans[k] += k * x;
        ans[k] = max(ans[k], ans[k - 1]);
    }

    for (int k = 0; k <= n; ++k)
        cout << ans[k] << ' ';
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
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
const int N = 2003;

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = -N;

    if (n >= 2)
    {
        int maxu = a[2];
        for (int i = 2; i <= n; ++i)
            maxu = max(maxu, a[i]);
        ans = max(ans, maxu - a[1]);

        int minu = a[1];
        for (int i = 1; i <= n - 1; ++i)
            minu = min(minu, a[i]);
        ans = max(ans, a[n] - minu);

        for (int i = 1; i < n; ++i)
        {
            ans = max(ans, a[i] - a[i + 1]);
        }
        ans = max(ans, a[n] - a[1]);
    }
    else
        ans = 0;

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
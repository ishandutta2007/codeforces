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
    for (int i = 1; i <= n * 2; ++i)
        cin >> a[i];

    sort(a + 1, a + n * 2 + 1);

    ll ans = (a[n] - a[1]) * 1LL * (a[n * 2] - a[n + 1]);

    for (int l = 2; l <= n; ++l)
    {
        ans = min(ans, (a[n * 2] - a[1]) * 1LL * (a[l + n - 1] - a[l]));
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
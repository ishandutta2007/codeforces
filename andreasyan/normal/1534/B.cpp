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
const int N = 400005;

int n;
int a[N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[n + 1] = 0;

    ll ans = 0;
    for (int i = 0; i <= n; ++i)
        ans += abs(a[i] - a[i + 1]);

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            ans -= (a[i] - max(a[i - 1], a[i + 1]));
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
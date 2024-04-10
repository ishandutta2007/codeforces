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

int p[N][N], s[N][N];

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            p[i][j] = s[i][j] = 0;

        for (int j = 1; j <= i; ++j)
            p[i][a[j]]++;
        for (int j = 1; j <= n; ++j)
            p[i][j] += p[i][j - 1];

        for (int j = i; j <= n; ++j)
            s[i][a[j]]++;
        for (int j = 1; j <= n; ++j)
            s[i][j] += s[i][j - 1];
    }

    ll ans = 0;
    for (int b = 2; b <= n; ++b)
    {
        for (int c = b + 1; c < n; ++c)
        {
            ans += p[b - 1][a[c]] * s[c + 1][a[b]];
        }
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
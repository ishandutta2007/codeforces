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

int m;
int a[3][N];

int p[N], s[N];

void solv()
{
    cin >> m;
    for (int i = 1; i <= 2; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    s[m + 1] = 0;
    for (int j = m; j >= 1; --j)
        s[j] = (a[1][j] + s[j + 1]);

    for (int j = 1; j <= m; ++j)
        p[j] = (a[2][j] + p[j - 1]);

    int ans = s[2];
    for (int j = 1; j <= m; ++j)
        ans = min(ans, max(p[j - 1], s[j + 1]));

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
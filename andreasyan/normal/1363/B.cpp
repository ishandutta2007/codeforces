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
const int N = 1003;

int n;
char a[N];

int p[N][2], s[N][2];

void solv()
{
    scanf(" %s", (a + 1));
    for (n = 1; a[n]; ++n){}
    --n;
    for (int i = 1; i <= n; ++i)
    {
        p[i][0] = p[i - 1][0];
        p[i][1] = p[i - 1][1];
        p[i][a[i] - '0']++;
    }
    s[n + 1][0] = s[n + 1][1] = 0;
    for (int i = n; i >= 1; --i)
    {
        s[i][0] = s[i + 1][0];
        s[i][1] = s[i + 1][1];
        s[i][a[i] - '0']++;
    }
    int ans = n;
    for (int i = 0; i < n; ++i)
    {
        ans = min(ans, p[i][0] + s[i + 1][1]);
        ans = min(ans, p[i][1] + s[i + 1][0]);
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
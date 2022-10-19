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
const int N = 100005;

int n, m;
int a[N], b[N];

void solv()
{
    int yy;
    scanf("%d%d", &n, &yy);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    scanf("%d%d", &m, &yy);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
    int ans = 0;
    for (ll d = 1; d <= 1000000000; d *= 2)
    {
        map<ll, int> mp;
        for (int i = 1; i <= n; ++i)
        {
            mp[a[i] % (d * 2)]++;
        }
        for (int i = 1; i <= m; ++i)
        {
            mp[(b[i] + d) % (d * 2)]++;
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
            ans = max(ans, it->se);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (binary_search(b + 1, b + m + 1, a[i]))
            ans = max(ans, 2);
    }
    printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
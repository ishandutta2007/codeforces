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
const ll INF = 1000000009000000009;

int n;
ll s[N];

ll u[N];

ll p[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &s[i]);
    sort(s + 1, s + n + 1);
    for (int i = 1; i < n; ++i)
    {
        u[i] = s[i + 1] - s[i];
    }
    u[n] = INF;
    sort(u + 1, u + n + 1);
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + u[i];
    int qq;
    scanf("%d", &qq);
    while (qq--)
    {
        ll l0, r0;
        scanf("%lld%lld", &l0, &r0);
        ll d = (r0 - l0 + 1);
        int l = 1, r = n;
        int ans = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (u[m] <= d)
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        printf("%lld\n", p[ans] + (n - ans) * d);
    }
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
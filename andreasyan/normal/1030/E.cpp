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

int ss[N][2];
int s0[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        ll x;
        scanf("%lld", &x);
        while (x)
        {
            if (x % 2 == 1)
                ++a[i];
            x /= 2;
        }
    }
    ll ans = 0;
    ss[n + 1][0] = 1;
    for (int i = n; i >= 1; --i)
    {
        s0[i] = s0[i + 1] + a[i];
        ss[i][0] = ss[i + 1][0];
        ss[i][1] = ss[i + 1][1];
        ++ss[i][s0[i] % 2];

        int s = 0;
        int maxu = 0;
        for (int j = i; j <= min(n, i + 70); ++j)
        {
            s += a[j];
            maxu = max(maxu, a[j]);
            if (s - maxu >= maxu && s % 2 == 0)
                ++ans;
        }

        /*for (int j = i + 71; j <= n; ++j)
        {
            if ((s0[i] - s0[j + 1]) % 2 == 0)
                ++ans;
        }*/
        ans += (ss[i + 72][s0[i] % 2]);
    }
    printf("%lld\n", ans);
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
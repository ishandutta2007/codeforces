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

int p[N];
int fi(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fi(p[x]);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n + 1; ++i)
        p[i] = i;

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] >= n)
        {
            ans += (a[i] - n);
            a[i] = n;
        }
        while (a[i] != 1)
        {
            ++ans;
            int j = i;
            while (j <= n)
            {
                int jj = n + 1;
                if (j + a[j] <= n)
                    jj = fi(j + a[j]);
                a[j] = max(1, a[j] - 1);
                if (a[j] == 1)
                    p[j] = j + 1;
                j = jj;
            }
        }
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

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
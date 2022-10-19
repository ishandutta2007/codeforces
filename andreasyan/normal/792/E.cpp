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
const int N = 503, S = 100005, INF = 1000000009;

int n;
int a[N];

ll ans;

void ubd(int x)
{
    if (x <= 0)
        return;
    ll yans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (x * (a[i] / (x + 1) + !!(a[i] % (x + 1))) <= a[i])
            yans += (a[i] / (x + 1) + !!(a[i] % (x + 1)));
        else
            return;
    }
    ans = min(ans, yans);
}

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        ans += a[i];
    }

    for (int x = 1; x < S; ++x)
    {
        ubd(x);
    }

    for (int k = 1; k < S; ++k)
    {
        ubd(a[1] / k);
        if (a[1] % k == 0)
            ubd(a[1] / k - 1);
    }

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
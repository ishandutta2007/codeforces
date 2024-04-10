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
ll k;
int a[N];

void solv()
{
    scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    {
        --k;
        int maxu = a[1];
        for (int i = 1; i <= n; ++i)
            maxu = max(maxu, a[i]);
        for (int i = 1; i <= n; ++i)
            a[i] = maxu - a[i];
    }
    if (k % 2 == 1)
    {
        int maxu = a[1];
        for (int i = 1; i <= n; ++i)
            maxu = max(maxu, a[i]);
        for (int i = 1; i <= n; ++i)
            a[i] = maxu - a[i];
    }

    for (int i = 1; i <= n; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
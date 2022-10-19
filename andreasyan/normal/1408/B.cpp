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
const int N = 102;

int n, k;
int a[N];

void solv()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    int q = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1 || a[i] != a[i - 1])
            ++q;
    }
    if (k >= q)
    {
        printf("1\n");
        return;
    }
    if (a[1] == 0)
    {
        --q;
        --k;
        if (k == 0)
        {
            printf("-1\n");
            return;
        }
        printf("%d\n", (q / k) + !!(q % k));
        return;
    }
    q -= k;
    --k;
    if (k == 0)
    {
        printf("-1\n");
        return;
    }
    printf("%d\n", 1 + (q / k) + !!(q % k));
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
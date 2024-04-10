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
const int N = 202;

int n, m;
int r[N], b[N];

int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &r[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);

    int max1 = 0;
    int p = 0;
    for (int i = 1; i <= n; ++i)
    {
        p += r[i];
        max1 = max(max1, p);
    }

    int max2 = 0;
    p = 0;
    for (int i = 1; i <= m; ++i)
    {
        p += b[i];
        max2 = max(max2, p);
    }

    printf("%d\n", max1 + max2);
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
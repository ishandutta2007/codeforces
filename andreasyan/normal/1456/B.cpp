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

int n;
int a[N];
int p[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i)
        p[i] = (p[i - 1] ^ a[i]);

    for (int i = 1; i < n; ++i)
    {
        if (i > 1 && a[i - 1] > (a[i] ^ a[i + 1]))
        {
            printf("1\n");
            return;
        }
        if (i + 2 <= n && (a[i] ^ a[i + 1]) > a[i + 2])
        {
            printf("1\n");
            return;
        }
    }

    int ans = N;
    for (int l = 1; l <= n; ++l)
    {
        for (int r = l + 1; r <= n; ++r)
        {
            for (int m = l; m < r; ++m)
            {
                if ((p[m] ^ p[l - 1]) > (p[r] ^ p[m]))
                {
                    ans = min(ans, r - l - 1);
                }
            }
        }
    }

    if (ans == N)
        printf("-1\n");
    else
        printf("%d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
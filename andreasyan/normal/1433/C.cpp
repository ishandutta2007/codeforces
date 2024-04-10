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
const int N = 300005;

int n;
int a[N];

void solv()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    bool z = false;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[1])
        {
            z = true;
            break;
        }
    }
    if (!z)
    {
        printf("-1\n");
        return;
    }

    int maxu = a[1];
    for (int i = 1; i <= n; ++i)
        maxu = max(maxu, a[i]);

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] == maxu)
        {
            if (i > 1 && a[i - 1] != a[i])
            {
                printf("%d\n", i);
                return;
            }
            if (i < n && a[i + 1] != a[i])
            {
                printf("%d\n", i);
                return;
            }
        }
    }
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
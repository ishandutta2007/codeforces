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

int n, d;
int a[N];

void solv()
{
    scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (int i = 2; i <= n; ++i)
    {
        if ((i - 1) * a[i] <= d)
        {
            a[1] += a[i];
            d -= (i - 1) * a[i];
        }
        else
        {
            a[1] += (d / (i - 1));
            break;
        }
    }
    printf("%d\n", a[1]);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
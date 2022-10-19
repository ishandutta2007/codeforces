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

int n, u, v;
int a[N];

void solv()
{
    scanf("%d%d%d", &n, &u, &v);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    bool z = true;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != a[1])
        {
            z = false;
            break;
        }
    }
    if (z)
    {
        printf("%d\n", min(u + v, v * 2));
        return;
    }

    for (int i = 1; i < n; ++i)
    {
        if (abs(a[i] - a[i + 1]) > 1)
        {
            printf("0\n");
            return;
        }
    }

    printf("%d\n", min(u, v));
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
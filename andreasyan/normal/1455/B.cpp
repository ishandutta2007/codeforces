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
const int N = 100;

bool c[N];

void solv()
{
    int x;
    scanf("%d", &x);

    int s = 0;
    for (int q = 1; ; ++q)
    {
        s += q;
        if (s >= x)
        {
            if (x == s - 1)
            {
                printf("%d\n", q + 1);
            }
            else
            {
                printf("%d\n", q);
            }
            return;
        }
    }

    for (int q = 1; q <= 5; ++q)
    {
        memset(c, false, sizeof c);
        for (int u = 0; u <= q; ++u)
        {
            for (int i = max(0, (1 + (q - u)) * (q - u) / 2 - u); i <= (q + (u + 1)) * (q - u) / 2 - u; ++i)
                c[i] = true;
            /*if ((1 + (q - u)) * (q - u) / 2 - u <= x && x <= (q + (u + 1)) * (q - u) / 2 - u)
            {
                printf("%d\n", q);
                return;
            }*/
        }
        for (int i = 0; i < N; ++i)
            printf("%d", c[i]);
        printf("\n");
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
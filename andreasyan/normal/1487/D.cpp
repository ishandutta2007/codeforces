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

void solv()
{
    scanf("%d", &n);

    int l = 1, r = N;
    int u;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (m * 1LL * m <= 2 * n)
        {
            u = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }

    if (u < 3)
        printf("0\n");
    else
        printf("%d\n", (u - 2) / 2 + (u - 2) % 2);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (int a = 1; a <= 200; ++a)
    {
        for (int b = a; b <= 200; ++b)
        {
            for (int c = b; c <= 200; ++c)
            {
                if (a * a + b * b == c * c && c == a * a - b)
                {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }*/

    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
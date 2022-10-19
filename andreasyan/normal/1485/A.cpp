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

void solv()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ca = a;

    int ans = 100;
    for (int p = 0; p <= 100; ++p)
    {
        b += p;

        int yans = p;
        while (a)
        {
            if (b == 1)
            {
                yans = 100;
                break;
            }
            ++yans;
            a /= b;
        }
        a = ca;
        b -= p;

        ans = min(ans, yans);
    }
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
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
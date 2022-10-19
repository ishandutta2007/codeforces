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
const int N = 1000006;

int n, s;

void solv()
{
    scanf("%d%d", &n, &s);
    if (n >= 2 * s)
    {
        printf("YES\n");
        for (int i = 1; i <= n - 1; ++i)
            printf("2 ");
        printf("%d\n", s - (n - 1) * 2);
        printf("1\n");
        return;
    }
    if ((n - 1) + 1 < (s - (n - 1)))
    {
        printf("YES\n");
        for (int i = 1; i <= n - 1; ++i)
            printf("1 ");
        printf("%d\n", s - (n - 1) * 1);
        printf("%d\n", n);
        return;
    }
    printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
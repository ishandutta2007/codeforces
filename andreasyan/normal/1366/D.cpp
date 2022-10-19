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
const int N = 10000007;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int u[N];

int ans1[N], ans2[N];

void solv()
{
    for (int i = 2; i < N; ++i)
    {
        if (u[i])
            continue;
        for (int j = i; j < N; j += i)
        {
            if (u[j] == 0)
            {
                u[j] = i;
            }
        }
    }
    int qq;
    scanf("%d", &qq);
    for (int i = 0; i < qq; ++i)
    {
        int x;
        scanf("%d", &x);
        ans1[i] = x;
        ans2[i] = 1;
        while (ans1[i] % u[x] == 0)
        {
            ans1[i] /= u[x];
            ans2[i] *= u[x];
        }
        if (ans1[i] == 1)
        {
            ans1[i] = ans2[i] = -1;
        }
    }
    for (int i = 0; i < qq; ++i)
        printf("%d ", ans1[i]);
    printf("\n");
    for (int i = 0; i < qq; ++i)
        printf("%d ", ans2[i]);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
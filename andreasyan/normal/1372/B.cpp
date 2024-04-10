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

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int solv0(int n)
{
    int ans = n;
    for (int i = 1; i < n; ++i)
    {
        ans = min(ans, i * (n - i) / gcd(i, n - i));
    }
    return ans;
}

void solv()
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            printf("%d %d\n", n / i, n - (n / i));
            return;
        }
    }
    printf("%d %d\n", 1, n - 1);
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
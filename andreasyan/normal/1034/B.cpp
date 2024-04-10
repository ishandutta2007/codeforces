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
    ll n, m;
    scanf("%lld%lld", &n, &m);
    if (n >= 3 && m >= 3)
    {
        if ((n * m) % 2 == 0)
            printf("%lld\n", n * m);
        else
            printf("%lld\n", n * m - 1);
        return;
    }
    if (n == 1 || m == 1)
    {
        if (m > 1)
            swap(n, m);
        ll ans = n / 6 * 6;
        n %= 6;
        if (n == 4)
            ans += 2;
        else if (n == 5)
            ans += 4;
        printf("%lld\n", ans);
        return;
    }
    if (m > 2)
        swap(n, m);
    if (n == 2)
        printf("0\n");
    else if (n == 3)
        printf("4\n");
    else if (n == 7)
        printf("12\n");
    else
        printf("%lld\n", n * m);
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
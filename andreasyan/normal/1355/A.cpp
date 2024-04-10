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

int mind(ll x)
{
    int minu = 10;
    while (x)
    {
        minu = min(minu, (int)(x % 10));
        x /= 10;
    }
    return minu;
}

int maxd(ll x)
{
    int maxu = -1;
    while (x)
    {
        maxu = max(maxu, (int)(x % 10));
        x /= 10;
    }
    return maxu;
}

void solv()
{
    ll s, k;
    scanf("%lld%lld", &s, &k);
    k--;
    while (k--)
    {
        int u = mind(s) * maxd(s);
        if (u == 0)
            break;
        s += u;
    }
    printf("%lld\n", s);
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
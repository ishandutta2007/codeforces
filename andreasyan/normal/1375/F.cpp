#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2100);

void solv()
{
    ll a[4];
    scanf("%lld%lld%lld", &a[1], &a[2], &a[3]);

    printf("First\n");
    fflush(stdout);

    ll maxu = max({a[1], a[2], a[3]});
    ll s = a[1] + a[2] + a[3] - maxu;

    printf("%lld\n", 2 * maxu - s);
    fflush(stdout);
    int x;
    scanf("%d", &x);

    if (a[x] != maxu)
    {
        printf("%lld\n", maxu - (s - a[x]));
        fflush(stdout);
        int x;
        scanf("%d", &x);
        assert(x == 0);
        return;
    }

    a[x] += (2 * maxu - s);

    maxu = max({a[1], a[2], a[3]});
    s = a[1] + a[2] + a[3] - maxu;

    printf("%lld\n", 2 * maxu - s);
    fflush(stdout);
    scanf("%d", &x);

    assert(a[x] != maxu);
    {
        printf("%lld\n", maxu - (s - a[x]));
        fflush(stdout);
        int x;
        scanf("%d", &x);
        assert(x == 0);
    }
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
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
const ll M = 10000007;

ll f, T, t0;

ll a1, t1, p1;
ll a2, t2, p2;

void solv()
{
    scanf("%lld%lld%lld", &f, &T, &t0);
    scanf("%lld%lld%lld", &a1, &t1, &p1);
    scanf("%lld%lld%lld", &a2, &t2, &p2);
    if (!(min(min(t1, t2), t0) * f <= T))
    {
        printf("-1\n");
        return;
    }
    if (t1 > t2)
    {
        swap(t1, t2);
        swap(a1, a2);
        swap(p1, p2);
    }
    ll ans = M * M;
    if (f * t1 <= T)
        ans = min(ans, (f / a1 + !!(f % a1)) * p1);
    for (ll q1 = 0; ; ++q1)
    {
        ll TT = T - q1 * a1 * t1;
        ll ff = f - q1 * a1;
        if (ff <= 0 || T < 0)
        {
            break;
        }
        if (!(min(t0, t2) * ff <= TT))
            continue;
        if (ff * t0 <= TT)
        {
            ans = min(ans, q1 * p1);
            continue;
        }
        assert(t2 < t0);
        ans = min(ans, q1 * p1 + (ff / a2 + !!(ff % a2)) * p2);
        ll q2 = (TT - (ff * t0)) / (a2 * t2 - a2 * t0);
        if (((TT - (ff * t0)) % (a2 * t2 - a2 * t0)))
            ++q2;
        assert(q2 >= 1);
        /*q2 = max(0LL, q2);
        if (!(q2 <= M))
            continue;
        ll q0 = ff - q2 * a2;
        if (q2 >= 0 && q0 >= 0 && a2 * t2 <= (long double)(TT - q0 * t0) / q2)
        {*/
            ans = min(ans, q1 * p1 + q2 * p2);
        /*}
        ll sq2 = q2;
        for (; q2 >= sq2 - 10; --q2)
        {
        q0 = ff - q2 * a2;
        if (q2 >= 0 && q0 >= 0 && q0 * t0 + q2 * a2 * t2 <= TT)
        {
            ans = min(ans, q1 * p1 + q2 * p2);
        }
        }*/
    }
    assert(ans != M * M);
    printf("%lld\n", ans);
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
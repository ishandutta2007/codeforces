#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
typedef long long ll;

void solv()
{
    ll p, a, b, c;
    scanf("%lld%lld%lld%lld", &p, &a, &b, &c);

    ll ans = ((a - (p % a)) % a);
    ans = min(ans, ((b - (p % b)) % b));
    ans = min(ans, ((c - (p % c)) % c));

    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif
    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
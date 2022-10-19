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
const int N = -1;

ll x;

set<ll> s;
void pre()
{
    for (ll i = 1; i * i * i <= 1000000000012; ++i)
        s.insert(i * i * i);
}

void solv()
{
    scanf("%lld", &x);

    for (ll i = 1; i * i * i <= x; ++i)
    {
        ll j = x - i * i * i;
        if (s.find(j) != s.end())
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);

    pre();
    int tt = 1;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}
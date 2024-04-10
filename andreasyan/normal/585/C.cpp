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
const int N = 100005;

vector<pair<ll, char> > ans;

ll gcd(ll x, ll y)
{
    if (x == y)
        return x;
    if (x > y)
    {
        if (x % y == 0)
        {
            ans.push_back(m_p(x / y - 1, 'A'));
            return gcd(y, y);
        }
        ans.push_back(m_p(x / y, 'A'));
        return gcd(x % y, y);
    }
    else
    {
        if (y % x == 0)
        {
            ans.push_back(m_p(y / x - 1, 'B'));
            return gcd(x, x);
        }
        ans.push_back(m_p(y / x, 'B'));
        return gcd(x, y % x);
    }
}

void solv()
{
    ll x, y;
    scanf("%lld%lld", &x, &y);
    ll g = gcd(x, y);
    if (g > 1)
    {
        printf("Impossible\n");
        return;
    }
    for (int i = 0; i < ans.size(); ++i)
        printf("%lld%c", ans[i].fi, ans[i].se);
    printf("\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}
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
 
int n, k;
int a[N];
 
ll p[N];
 
void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
 
    for (int i = 1; i <= n; ++i)
        p[i] = p[i - 1] + a[i];
 
    ll ans = 0;
 
    ll u = 1;
    for (int ii = 0; ; ++ii)
    {
        map<ll, int> mp;
        mp[p[0] + u]++;
        for (int i = 1; i <= n; ++i)
        {
            ans += mp[p[i]];
            mp[p[i] + u]++;
        }
 
        u *= k;
        if (k == 1 && ii == 0)
            break;
        if (k == -1 && ii == 1)
            break;
 
        if (abs(u) > N * 1000000000LL)
            break;
    }
 
    cout << ans << "\n";
}
 
int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);
 
    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}
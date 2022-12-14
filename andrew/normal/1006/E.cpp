#include <bits/stdc++.h>

#define rust(a, b, c, d) sqrt(sqr(a - c) + sqr(b - d))
#define sqr(a) (a)*(a)
#define m_p make_pair
#define fi first
#define se second
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pll pair <ll,ll>
#define vl vector <ll>
#define p_b push_back

typedef long long ll;
const int MAXINT=2147483640;
const ll MAXLL=9223372036854775800LL;
const ll MAXN=290000;
const double eps = 1e-9;
const ll mod = 1e9 + 7;
using namespace std;

ll binpow(ll a, ll n) {
    ll ans = 1;
    while (n) {
        if (n&1) ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

set<ll> p[MAXN];
ll tin[MAXN], tout[MAXN];
ll stn;
vector<ll> a;
void dfs(ll x){
                         stn++;
                         tin[x]=stn;
                         a.p_b(x);
                         for(auto i : p[x])dfs(i);
                         tout[x]=stn;
}
int main() {
    srand(time(0));
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    fast_io;
    a.p_b(0);
    ll n, m;
    cin>>n>>m;
    ll i;
    
    for(i=2;i<=n;i++){
                             ll x;
                             cin>>x;
                             p[x].insert(i);
    }
    dfs(1);
    while(m--){
                             ll x, k;
                             cin>>x>>k;
                             ll tt = tin[x] + k - 1;
                             ll ans = -1;
                             if(tt<=tout[x])ans=a[tt];
                             
                             cout << ans << "\n";
    }
    return 0;
}
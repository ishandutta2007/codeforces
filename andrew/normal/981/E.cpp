#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
const ll MAXN = 123456;

template <typename T>
T sqr(T x){
    return x * x;
}

template <typename T>
void vout(T s){
    cout << s << endl;
    exit(0);
}

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}


const ll mod = 1e9 + 7;
vector <pll> v[MAXN],v1[MAXN];
string s1,s2,s3;
map <ll, ll> mp;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,sc,x;
ll dp[MAXN], ans[MAXN];

void add(ll x, ll number){
    for(int i = n; i >= x; i--)if(dp[i - x]){
            dp[i] += dp[i - x];
            dp[i] %= mod;
            ans[i] = max(ans[i], dp[i]);
    }
}

void del(ll x, ll number){
    for(int i = x; i <= n; i++)dp[i] = (dp[i] - dp[i - x] + mod) % mod;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(i = 1; i <= m; i++){
        ll l, r;
        cin >> l >> r >> x;
        v[l].p_b({x, i});
        v1[r + 1].p_b({x, i});
    }
    dp[0] = 1;
    for(i = 1; i <= n; i++){
        for(int j = 0; j < v1[i].size(); ++j)del(v1[i][j].fi, v1[i][j].se);
        for(int j = 0; j < v[i].size(); ++j)add(v[i][j].fi, v[i][j].se);
    }
    for(int i = 1; i <= n; i++)if(ans[i])s.insert(i);
    cout << s.size() << endl;
    set <ll> :: iterator it = s.begin();
    for(; it != s.end(); ++it)cout << *it << " ";
    return 0;
}
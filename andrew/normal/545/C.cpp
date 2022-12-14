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
const ll MAXN = 1123456;

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

vector <ll> v[MAXN],va;
string s1,s2,s3;
set <ll> s;
char cc;
ll b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
bool f[MAXN][3];
ll dp[MAXN][3];
pll a[MAXN];
ll dv[MAXN][3];
ll ke[3];
void check1(ll x){
    ll h = a[x].se;
    ll pz = a[x].fi;
    ll dd = a[x - 1].fi;
    if(pz - dd > h){
        ll i = x;
        if(f[i - 1][0]){dp[i][0] = max(dp[i - 1][0] + 1, dp[i][0]);f[i][0] = 1;}
        if(f[i - 1][1]){dp[i][0] = max(dp[i - 1][1] + 1, dp[i][0]);f[i][0] = 1;}
        if(f[i - 1][2] && pz - dd > a[x - 1].se + h){dp[i][0] = max(dp[i - 1][2] + 1, dp[i][0]);f[i][0] = 1;}
    }
}
void check2(ll x){
    ll i = x;
    if(f[i - 1][0])dp[i][1] = max(dp[i - 1][0], dp[i][1]);
    if(f[i - 1][1])dp[i][1] = max(dp[i - 1][1], dp[i][1]);
    if(f[i - 1][2])dp[i][1] = max(dp[i - 1][2], dp[i][1]);
    f[i][1] = 1;
}
void check3(ll x){
    ll h = a[x].se;
    ll pz = a[x].fi;
    ll dd = a[x + 1].fi;
    if(pz + h < dd){
        ll i = x;
        if(f[i - 1][0]){dp[i][2] = max(dp[i][2], dp[i - 1][0] + 1);f[i][2] = 1;}
        if(f[i - 1][1]){dp[i][2] = max(dp[i][2], dp[i - 1][1] + 1);f[i][2] = 1;}
        if(f[i - 1][2]){dp[i][2] = max(dp[i][2], dp[i - 1][2] + 1);f[i][2] = 1;}
    }
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 1; i <= n; i++){
        dv[i][0] = i - 1;
        dv[i][2] = i + 1;
    }
    for(j = 0; j < 3; j++)ke[j] = 1;
    ke[1] = 0;
    for(i = 1; i <= n; i++)cin >> a[i].fi >> a[i].se;
    a[0].fi = -1e18;
    a[i].fi = 1e18;
    sort(a + 1, a + n + 1);
    dp[1][1] = 0;
    f[1][1] = 1;
    dp[1][0] = 1;
    f[1][0] = 1;
    if(a[2].fi - a[1].fi > a[1].se){
        dp[1][2] = 1;
        f[1][2] = 1;
    }
    for(i = 2; i <= n; i++){
        check1(i);
        check2(i);
        check3(i);
    }
    for(i = 0; i < 3; i++)ans = max(ans, dp[n][i]);
    vout(ans);
    return 0;
}
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
ll a[1001][1001];
ll dp[1001][1001];
ll kk[1001][1001];
ll pref[1001][1001];
ll get(ll l, ll r, ll j){
    if(l > r)return 0;
    return pref[j][r] - pref[j][l - 1];
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i = 1; i <= 1000; i++)
        for(j = 0; j <= 1000; j++)dp[i][j] = 1e9, kk[i][j] = 1e9;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++){
        cin >> cc;
        x = cc - '0';
        pref[i][j] = pref[i][j - 1];
        pref[i][j] += x;
        a[i][j] = x;
    }
    for(i = 1; i <= n; i++){
        for(ll l = 1; l <= m; l++)
        for(ll r = l; r <= m; r++){
            ll tm = r - l + 1;
            ll sm = get(1, l - 1, i) + get(r + 1, m, i);
            kk[i][sm] = min(kk[i][sm], tm);
        }
        kk[i][pref[i][m]] = 0ll;
    }
    for(i = 1; i <= n; i++){
        for(j = 0; j <= k; j++){
            for(ll i1 = 0; i1 <= k; i1++)dp[i][j + i1] = min(dp[i][j + i1], dp[i - 1][j] + kk[i][i1]);
        }
    }
    ll ans = 1e18;
    for(j = 0; j <= k; j++)ans = min(ans, dp[n][j]);
    vout(ans);
    return 0;
}
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
map <ll, ll> mp;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;

ll dp[1000][1000];
bool f[1000][1000];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for(i = 1; i <= n; i++)cin >> a[i];
    m = 55;
    f[0][0] = 1;
    for(ll kek = 55; kek >= 0; --kek){
        ll mask = ans | (1ll << kek);
        for(i = 1; i <= n; i++)for(j = 0; j <= k; j++)f[i][j] = 0;
        for(i = 1; i <= n; i++){
            for(j = 1; j <= min(k, i); j++){
                sc = 0;
                for(ll i1 = i; i1 > 0; --i1){
                        sc += a[i1];
                        if(f[i1 - 1][j - 1] && (mask & sc) == mask)f[i][j] = 1;
                }
            }
        }

        if(f[n][k])ans |= 1ll << kek;
    }
    cout << ans << endl;
    return 0;
}
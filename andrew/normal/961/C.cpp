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
string s1[MAXN],s2,s3;
set <ll> s;
char cc;
ll a[MAXN][4],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 0; i < 4; i++){
        for(j = 1; j <= n; j++)cin >> s1[j];
        ll k = 0;
        sc = 0;
        for(j = 1; j <= n; j++){
            ll k1 = k;
            for(ll i1 = 0; i1 < n; i1++){
                    if(s1[j][i1] - '0' != k1)sc++;
                    k1 = (k1 + 1) % 2;
            }

            k = (k + 1) % 2;
        }
        a[i][0] = sc;
        k = 1;
        sc = 0;
        for(j = 1; j <= n; j++){
            ll k1 = k;
            for(ll i1 = 0; i1 < n; i1++){
                    if(s1[j][i1] - '0' != k1)sc++;
                    k1 = (k1 + 1) % 2;
            }

            k = (k + 1) % 2;
        }
        a[i][1] = sc;
    }
    ll m = 1ll << 4;
    ll ans = 1e18;
    for(i = 0; i < m; i++){
            j = 0;
        ll k = 0, x = i;
        while(x){
            b[j] = x % 2;
            k += x % 2;
            x /= 2;
            j++;
        }
        if(k != 2)continue;
        sc = 0;
        for(j = 0; j < 4; j++)sc += a[j][b[j]];
        ans = min(ans, sc);
    }
    vout(ans);
    return 0;
}
#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
//#define endl "\n"
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

struct{
    ll p[2], kl, sm;
}b[MAXN];
vector <ll> v[MAXN],va;
string s1,s2,s3;
set <ll> s;
char cc;
ll c,a1,b1,c1,i,j,n,m,k,sc,x,a[MAXN];
ll f[MAXN];
ll q1 = 1;
void addB(ll x,ll sc){
    ll q = 0, i;
    for(i = 19; i >= 0; i--){
        ll xe = x & (1ll << i);
        xe = min(xe, 1ll);
        if(!b[q].p[xe])b[q].p[xe] = q1++;
        q = b[q].p[xe];
        b[q].kl += sc;
        b[q].sm++;
    }
}
ll ans(ll x){
    ll q = 0, i;
    ll res = 0;
    for(i = 19; i >= 0; i--){
        ll xe = x & (1ll << i);
        xe = min(xe,1ll);
        ll qq = b[q].p[xe];
        ll qe = 0;
        if(!xe)qe = 1;
        if(b[qq].kl != b[qq].sm )q = b[q].p[xe];
            else{
                q = b[q].p[qe];
                res |= (1ll << i);
        }
    }
    return res;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> x;
        f[x] = 1;
    }
    k = 1ll << 19;
    for(i = 0; i <= k; i++)addB(i, f[i]);
    while(m--){
            cin >> x;
            c ^= x;
            cout << ans(c) << "\n";
    }
    return 0;
}
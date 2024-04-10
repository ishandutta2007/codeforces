#include <bits/stdc++.h>

#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

ll binpow(ll a,ll n)
{
    ll res = 1;
    while(n)
    {
        if(n % 2)res *= a;
        a *= a;
        n /= 2;
    }
    return res;
}

template <typename T>
T sqr(T x)
{
    return x * x;
}

template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}

ll log(ll a,ll b){
    ll res = 0;
    while(a){
        a /= b;
        res++;
    }
    return res;
}

const ll MAXN = 1123456;
vector <ll> v[MAXN];
set <pll> st;
stringstream ss;
set <ll> s;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll pref[MAXN][10];
ll f(ll x){
    ll res = 1;
    while(x){
        c = x%10;
        if(c) res*=c;
        x/=10;
    }
    return res;
}
ll g(ll x){
    if(x<10)return x;
    return g(f(x));
}
ll get(ll l,ll r,ll c){
    return pref[r][c] - pref[l-1][c];
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=1;i<=1e6;i++){
        a[i]=g(i);
    }

    for(i=1;i<=1e6;i++){
        for(j=0;j<10;j++)pref[i][j] = pref[i-1][j];
        pref[i][a[i]]++;
    }
    while(n--){
            ll l,r;
        cin >> l >> r >> c;
        cout << get(l,r,c) << endl;
    }
    return 0;
}
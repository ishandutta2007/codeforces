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
const ll shl = 1;
const ll MAXN = 1123456;
vector <ll> v[MAXN];
set <pll> st;
stringstream ss;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll p[2000000];
void build(ll v,ll tl,ll tr){
    if(tl==tr)p[v]=b[tl];else{
        ll tm=(tl+tr)/2;
        build(v*2,tl,tm);
        build(v*2+1,tm+1,tr);
        p[v]=p[v*2]+p[v*2+1];
    }
}
void modify(ll v,ll tl,ll tr,ll pos,ll val){
    if(tl==tr)p[v]=val;else{
        ll tm=(tl+tr)/2;
        if(pos<=tm)modify(v*2,tl,tm,pos,val);else modify(v*2+1,tm+1,tr,pos,val);
        p[v]=p[v*2]+p[v*2+1];
    }
}
ll get(ll v,ll tl,ll tr,ll l,ll r){
    if(l>r)return 0ll;
    if(tl==l && tr==r)return p[v];
    ll tm=(tl+tr)/2;
    return get(v*2,tl,tm,l,min(r,tm))+get(v*2+1,tm+1,tr,max(l,tm+1),r);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll nn=1e6;
    for(i=1;i<=nn;i++)a[i]=1;
    for(i=2;i<=nn;i++){
        j=i;
        while(j<=nn){
           a[j]++;
           j+=i;
        }
    }
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> b[i];
    build(1,1,n);
    for(i=1;i<=n;i++)if(b[i]>2){
        s.insert(i);
    }
    set <ll> :: iterator it;
    while(m--){
        cin >> x;
        ll l,r;
        cin >> l >> r;
        if(x==2){
            cout << get(1,1,n,l,r) << endl;
        }else{
            it=s.lower_bound(l);
            while(it!=s.end() && (*it)<=r){
                x=*it;
                b[x]=a[b[x]];
                if(b[x]<3)s.erase(it);
                modify(1,1,n,x,b[x]);
                it=s.upper_bound(x);
            }
        }
    }
    return 0;
}
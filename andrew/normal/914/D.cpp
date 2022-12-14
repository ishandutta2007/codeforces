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
    ll res=1;
    while(n)
    {
        if(n%2)res*=a;
        a*=a;
        n/=2;
    }
    return res;
}
template <typename T>
T sqr(T x)
{
    return x*x;
}
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
ll log(ll a,ll b){
    ll res=0;
    while(a){
        a/=b;
        res++;
    }
    return res;
}
const ll shl=1;
const ll MAXN=1123456;
vector <ll> v[MAXN];
set <pll> st;
stringstream ss;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll p[MAXN];
ll pz;
void dfs(ll v,ll tl,ll tr){
    if(pz>1)return;
    if(tl==tr){
        if(p[v]%x)pz++;
        return;
    }
    ll tm=(tl+tr)/2;
    if(p[v*2]%x)dfs(v*2,tl,tm);
    if(p[v*2+1]%x)dfs(v*2+1,tm+1,tr);
    return;
}
void modify(ll v,ll tl,ll tr,ll pos,ll val){
    if(tl==tr)p[v]=val;else{
        ll tm=(tl+tr)/2;
        if(pos<=tm)modify(v*2,tl,tm,pos,val);else modify(v*2+1,tm+1,tr,pos,val);
        p[v]=__gcd(p[v*2],p[v*2+1]);
    }
    return;
}
ll get(ll v,ll tl,ll tr,ll l,ll r){
    if(l>r)return 0;
    if(tl==l && tr==r)return p[v];
    ll tm=(tl+tr)/2;
    return __gcd(get(v*2,tl,tm,l,min(r,tm)),get(v*2+1,tm+1,tr,max(l,tm+1),r));
}
void get1(ll v,ll tl,ll tr,ll l,ll r){
     if(l>r)return;
     if(tl==l && tr==r){
        if(p[v]==x)return;
        //cout << l << " " << r << endl;
        dfs(v,tl,tr);
        return;
     }
     ll tm=(tl+tr)/2;
     get1(v*2,tl,tm,l,min(r,tm));
     get1(v*2+1,tm+1,tr,max(l,tm+1),r);
     return;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> x;
        modify(1,1,n,i,x);
    }
    cin >> m;
    while(m--){
            ll ke;
        cin >> ke;
        ll l,r;
        if(ke==2){
            cin >> l >> x;
            modify(1,1,n,l,x);
        }else{
            cin >> l >> r >> x;
            if(get(1,1,n,l,r)==x){
                cout << "YES" << endl;
                continue;
            }
            pz=0;
            get1(1,1,n,l,r);
            ll xe=get(1,1,n,pz,pz);
            if(pz<2)cout << "YES";else cout << "NO";
            cout << endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
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
multiset <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
bool check(ll x){
    s.clear();
    ll sc=0;
    for(i=0;i<n;i++)if(a[i]>=x){
        s.insert(b[i]);
        if(s.size()>x)s.erase(--s.end());
    }
    if(s.size()<x)return 0;
    multiset <ll> :: iterator it=s.begin();
    for(;it!=s.end();++it)sc+=*it;
    if(sc<=m)return 1;
    return 0;
}
void way(ll x){
    cout << x << endl;
    cout << x << endl;
    for(i=0;i<n;i++)if(a[i]>=x){
        st.insert(m_p(b[i],i+1));
        if(st.size()>x)st.erase(--st.end());
    }
    set <pll> :: iterator it=st.begin();
    for(;it!=st.end();++it)cout << it->se << " ";
    cout << endl;
    exit(0);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    ll l=0,r=n;
    while(l<r){
        ll c=(l+r)/2;
        if(check(c))l=c+1;else r=c;
    }

    if(!check(l))l--;
    way(l);
    return 0;
}
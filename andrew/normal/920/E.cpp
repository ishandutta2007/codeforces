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
set <ll> :: iterator it;
ll r;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
void dfs(ll x){
    b[x]=1;
    a[r]++;
    s.erase(x);
    ll i,nn=v[x].size();
    for(i=0;i<nn-1;i++){
        ll l=v[x][i]+1,r=v[x][i+1]-1;
        //cout << l << " " << r << " " << x << endl;
        if(l<=r){
            it=s.lower_bound(l);
            while(it!=s.end() && (*it)<=r){
                dfs(*it);
                it=s.lower_bound(l);
            }
        }
    }
    return;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=1;i<=n;i++)v[i].p_b(0);
    while(m--){
        cin >> a1 >> b1;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
    }
    for(i=1;i<=n;i++)sort(all(v[i]));
    for(i=1;i<=n;i++)v[i].p_b(n+1);
    for(i = 1;i <=n;i++)s.insert(i);
    for(i=1;i<=n;i++)if(!b[i]){
        r++;
        dfs(i);
    }
    cout << r << endl;
    sort(a+1,a+1+r);
    for(i=1;i<=r;i++)cout << a[i] << " ";
    cout << endl;
    return 0;
}
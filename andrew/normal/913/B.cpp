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
const ll shl=1;
const ll MAXN=1123456;
vector <ll> v[MAXN];
set <pll> st;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
ll c,sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
ll dfs(ll x){
    b[x]=1;
    ll i,nn=v[x].size(),sc=0;
    bool fl=0;
    for(i=0;i<nn;i++){
            sc+=dfs(v[x][i]);
    fl=1;
    }

    if(fl && sc<3)vout("No");
    return !(sc);
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n;
    m=n-1;
    i=1;
    while(m--){
        i++;
        cin >> a1;
        v[a1].p_b(i);
    }
    dfs(1ll);
    vout("Yes");
    return 0;
}
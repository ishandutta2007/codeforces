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
struct be{
    int p[26];
};
vector <ll> v[MAXN];
set <pll> st;
stringstream ss;
set <ll> s;
map < string , ll > mp;
string s2,s1,s3;
char cc;
int c[MAXN],n,m,i,j,b[MAXN],a1,b1,c1,ans,x,k;
be a[300001];
be kk;
void dfs(ll x){
    if(c[x]==1)vout(-1);
    if(c[x]==2)return;
    c[x]=1;
    int i,nn=v[x].size();
    for(i=0;i<nn;i++)dfs(v[x][i]);
    c[x]=2;
    return;
}
be dfs1(ll x){
    if(c[x])return a[x];
    c[x]=1;
    int i,nn=v[x].size();
    for(i=0;i<nn;i++){
        kk=dfs1(v[x][i]);
        for(j=0;j<26;j++)a[x].p[j]=max(a[x].p[j],kk.p[j]);
    }
    a[x].p[s1[x-1]-'a']++;
    return a[x];
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    cin >> s1;
    while(m--){
        cin >> a1 >> b1;
        v[a1].p_b(b1);
    }
    for(i=1;i<=n;i++)if(!c[i])dfs(i);
    for(i=1;i<=n;i++)c[i]=0;
    for(i=1;i<=n;i++){
            if(!c[i])a[i]=dfs1(i);
    }
    for(i=1;i<=n;i++){
        for(j=0;j<26;j++)ans=max(ans,a[i].p[j]);
    }
    cout << ans << endl;
    return 0;
}
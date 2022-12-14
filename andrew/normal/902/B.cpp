#include <bits/stdc++.h>
#define p_b push_back
//#define endl "\n"
#define m_p make_pair
#define fi first
#define se second
#define pll pair <ll,ll>
using namespace std;
typedef long long ll;
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
map < string , ll > mp;
string s2,s1,s3;
multiset <ll> s;
char cc;
ll c[MAXN],sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
void dfs(ll x,ll cv)
{
    if(b[x])return;
    b[x]=1;
   if(c[x]!=cv)
   {
       cv=c[x];
        ans++;
   }
    ll i1,nn=v[x].size();
    for(i1=0;i1<nn;i1++)dfs(v[x][i1],cv);
    return;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);

    cin >> n;
    for(i=2;i<=n;i++)
    {
        cin >> a1;
        v[a1].p_b(i);
        v[i].p_b(a1);
    }
    for(i=1;i<=n;i++)cin >> c[i];
    dfs(1ll,0ll);
    cout << ans << endl;
    return 0;
}
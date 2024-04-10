#include <bits/stdc++.h>
#define p_b push_back
#define endl "\n"
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
const ll shl=1;
const ll MAXN=1123456;
vector <ll> v[100001];
set <ll> s;
map < string , ll > mp;
string s1;
char cc;
ll r,c[MAXN],sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
void dfs(ll x)
{
    if(b[x])return;
    c[r]=min(c[r],a[x]);
    b[x]=r;
    ll i,nn=v[x].size();
    for(i=0;i<nn;i++)dfs(v[x][i]);
    return;
}
int main() {

    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=1;i<=n;i++)cin >> a[i];
    for(i=1;i<=n;i++)c[i]=1e18;
    while(m--)
    {
        cin >> a1 >> b1;
        v[a1].p_b(b1);
        v[b1].p_b(a1);
    }
    for(i=1;i<=n;i++)if(!b[i])
    {
        r++;
        dfs(i);
    }
    for(i=1;i<=r;i++)ans+=c[i];
    cout << ans << endl;
    return 0;
}
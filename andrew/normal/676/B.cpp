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
char cc;
ll c,sc,n,m,i,j,b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
double a[1000][1000];
double t=1.0;
void dfs(ll ur,ll x,double le)
{
    if(x>ur or x<1 or ur>n or ur<1)return;
    if(le+a[ur][x]>t)
    {
        dfs(ur+1,x+1,(le+a[ur][x]-t)/2);
        dfs(ur+1,x,(le+a[ur][x]-t)/2);
        a[ur][x]=1.0;
    }else
    a[ur][x]+=le;
}
int main() {


    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
    for(i=1;i<=m;i++)
    {
        dfs(1ll,1ll,double(1));
    }
    for(i=1;i<=n;i++)for(j=1;j<=i;j++)if(abs(a[i][j]-1)<=1e-9)ans++;
    cout << ans << endl;
    return 0;
}
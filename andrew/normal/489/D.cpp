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
ll dp[MAXN][3],sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
ll p[MAXN];
ll get(ll x)
{
    if(p[x]!=x)p[x]=get(p[x]);
    return p[x];
}
int main() {


    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin >> n >> m;
   while(m--)
   {
       cin >> a1 >> b1;
       a[i]=a1;b[i]=b1;
       i++;
   }
   m=i;
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
       {
           dp[j][0]=0;
           dp[j][1]=0;
           dp[j][2]=0;
       }
        for(j=0;j<m;j++)if(a[j]==i)dp[b[j]][1]++;
        for(j=0;j<m;j++)if(b[j]!=i)dp[b[j]][2]+=dp[a[j]][1];
        for(j=1;j<=n;j++)ans+=max(0ll,((dp[j][2]-1)*dp[j][2])/2);
   }
   cout << ans << endl;
    return 0;
}
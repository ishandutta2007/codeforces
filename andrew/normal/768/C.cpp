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
const ll shl=1;
const ll MAXN=1123456;
template <typename T>
void vout(T s)
{
    cout << s << endl;
    exit(0);
}
char cc;
set <ll> s,s1;
ll c[MAXN],sc,n,m,i,j,a[MAXN],b[MAXN],a1,b1,c1,ans,x,k;
int main() {


    // set < ll > :: iterator kek=s.begin;
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
   cin >> n >> m >> k;
   for(i=1;i<=n;i++)cin >> a[i];
   for(i=1;i<=n;i++)c[a[i]]++;
   for(i=1;i<=n;i++)
   {
       if(a[i]>1000)while(1);
   }
   for(i=0;i<m;i++)
   {
        for(ll j=0;j<=1100;j++)b[j]=c[j],c[j]=0;
        j=1;
        for(x=0;x<1101;x++)if(b[x])
        {
            ll kl;
            if(j%2)kl=(b[x]+1)/2;
            else kl=b[x]/2;
            j+=b[x];
            ll ke=x^k;
            c[ke]+=kl;
            c[x]+=b[x]-kl;
        }
   }
  ll mx=-1e18,mn=1e18;
  for(i=0;i<1101;i++)if(c[i])mx=max(mx,i),mn=min(mn,i);
  cout << mx << " " << mn << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define fi first
#define se second
#define p_b push_back
#define m_p make_pair
#define endl "\n"
#define pll pair<ll,ll>
const ll maxn=1000000;
ll a[maxn],b[maxn],c,a1,b1,c1,n,m,x,i,j,sc,ans,k;
template <typename T>
T sqr(T a)
{
    return a*a;
}
void vout(string s)
{
    cout << s << endl;
    exit(0);
}
string s,s1[100];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
   n=s.size();
   for(i=0;i<n;i++)
   {
       if(s[i]=='a')a1++;else b1++;
       a[i+1]=a1;
       b[i+1]=b1;
   }
   //if(b[n]==0)vout("0");
   for(i=0;i<=n;i++)
    for(j=i+1;j<=n+1;j++)
   {
        k=b[i];
        k+=(b[n]-b[j-1]);
        k+=(a[j-1]-a[i]);
        ans=max(ans,n-k);
   }
 /*  for(i=1;i<n+2;i++)
   {
       ans=max(ans,n-b[i-1]-(a[n]-a[i-1]));
   }
   for(i=1;i<n+2;i++)
   {
       ans=max(ans,n-a[i-1]-(b[n]-b[i-1]));
   }*/
   cout << ans << endl;
return 0;
}
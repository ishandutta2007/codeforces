#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=2e3+5;

int n, g=0, ct=0;
int a[N];

int32_t main()
{
   IOS;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
      cin>>a[i];
      g=gcd(g, a[i]);
      if(a[i]==1)
         ct++;
   }
   if(g>1)
   {
      cout<<"-1";
      return 0;
   }
   if(ct>=1)
   {
      cout<<n-ct;
      return 0;
   }
   int minlen=n;
   for(int i=1;i<=n;i++)
   {
      int curg=0;
      int j;
      for(j=i;j<=n;j++)
      {
         curg=gcd(curg, a[j]);
         if(curg==1)
            break;
      }
      if(curg==1)
        minlen=min(minlen, j-i);
   }
   int ans=minlen + n-1;
   cout<<ans;
}
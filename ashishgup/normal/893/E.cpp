#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e6+100;
const int MOD=1e9+7;

int sieve[N+1], prime[N+1], fact[N], invfact[N];

int modinv(int k)
{
   return pow(k, MOD-2, MOD);
}

void process()
{
   fact[0]=1;
   fact[1]=1;
   invfact[0]=1;
   invfact[1]=1;
   for(int i=2;i<=N;i++)
   {
      sieve[i]=1;
      fact[i]=fact[i-1]*i;
      fact[i]%=MOD;
      invfact[i]=modinv(fact[i]);
   }
   for(int i=2;i<=N;i++)
   {
      if(sieve[i])
      {
         for(int j=1;i*j<=N;j++)
         {
            prime[i*j]=i;
            sieve[i*j]=0;
         }
      }
   }
}

int nCr(int n, int r)
{
   int num=fact[n];
   num*=invfact[n-r];
   num%=MOD;
   num*=invfact[r];
   num%=MOD;
   return num;
}

int32_t main()
{
   IOS;
   process();
   int t;
   cin>>t;
   while(t--)
   {
      map<int, int> m;
      int x, y;
      cin>>x>>y;
      int cur=x;
      int ans=1;
      while(cur>1)
      {
         m[prime[cur]]++;
         cur/=prime[cur];
      }
      for(auto it:m)
      {
         ans*=nCr(it.second+y-1, y-1);
         ans%=MOD;
      }
      ans*=pow(2LL, y-1, MOD);
      ans%=MOD;
      cout<<ans<<endl;
   }
}
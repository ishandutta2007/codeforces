#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

int n;
set<int> s;

void preprocess()
{
   for(int i=1;i<=30;i++)
   {
      int store=pow(2LL, i-1, (long long)1e18);
      int curnum=store*((store*2) - 1);
      s.insert(curnum);
   }
}

bool check(int k)
{
   if(s.find(k)!=s.end())
      return true;
   return false;
}

int32_t main()
{
   IOS;
   preprocess();
   int ans=1;
   cin>>n;
   for(int i=1;i<=1e5;i++)
   {
      if(n%i!=0)
         continue;
      if(check(i))
      {
         ans=max(ans, i);
      }
   }
   cout<<ans;
}
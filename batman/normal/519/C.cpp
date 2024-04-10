//////////////////////////////////////////////////////////////////
////////////////// Sa1378 Platform Vesion 1.1.2 /////////////////
////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
#define what_is(x) cerr << #x << " is " << x << endl;
#define INF (1000*1000*1000)
#define N (1100)
#define ll long long
#define ld long double
#define ST setprecision
#define MP make_pair
#define PB push_back
#define MOD (ll)1e9+7
#define IB ios_base::sync_with_stdio;
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ll gcd(ll a, ll b){return (a < b) ? gcd(b, a) : ((a % b == 0) ? b : gcd(b, a % b));}
//bool sortt(int x,int y){ return a[x] > a[y]; }

int n,m,ans;
int main()
{
  cin>>n>>m;
  for(int i=0;i<=n;i++)
    {
      int a=n-i,b=m-2*i;
      int ex=min(a/2,b);
      ans=max(ans,ex+i);
    }
  cout<<ans<<endl;
  return 0;
}
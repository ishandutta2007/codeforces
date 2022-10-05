#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;


ll n,i,j, k, a, b;
vector <ll> ans;
bool viv=false;

long long GCD(long long a, long long b)
{
if (a==0&&b==0)
  return 1;
while (a!=0&&b!=0)
  {
  if (a>=b)
    a%=b;
  else
    b%=a;
  }
return a+b;
}



void solve(ll a, ll b)
{
ll l=a+b;
while (l>k)
  l-=k;
for (ll i=l; i<=n*k; i+=k)
  {
//  cout<<i<<endl;
  ll lans=n*k/GCD(n*k, i);
  ans.push_back(lans);
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
cin>>a>>b;
solve(a, b);
solve(a, k-b);
solve(k-a, b);
solve(k-a, k-b);
sort(ans.begin(), ans.end());
cout<<ans[0]<<' '<<ans.back()<<endl;
//for (auto i:ans)
//  cout<<i<<' ';





    return 0;
}
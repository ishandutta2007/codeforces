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


ll n,i,j, k, m, t;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k>>m>>t;
k--;
for (ll i=0; i<t; i++)
  {
  ll ty;
  cin>>ty;
  if (ty==1)
    {
    ll num;
    cin>>num;
    num--;
    n++;
    if (num<=k)
      k++;
    }
  else
    {
    ll num;
    cin>>num;
    ll a=num;
    ll b=n-num;
    if (k<num)
      n=a;
    else
      n=b, k-=a;
    }
  cout<<n<<' '<<k+1<<endl;
  }








    return 0;
}
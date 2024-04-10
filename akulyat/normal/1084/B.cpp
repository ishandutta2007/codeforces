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


ll n,i,j;
vector <ll> m;
bool viv=false;
ll s;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>s;
ll sum=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  sum+=a;
  }
if (sum<s)
  {
  cout<<-1<<endl;
  return 0;
  }
ll mi=*min_element(m.begin(), m.end());
for (auto &i:m)
  {
  s-=(i-mi);
  i=mi;
  }
if (s<=0)
  {
  cout<<mi<<endl;
  return 0;
  }
cout<<mi-(s+n-1)/n<<endl;











    return 0;
}
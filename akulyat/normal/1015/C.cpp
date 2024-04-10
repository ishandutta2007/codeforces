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


ll n,i,j,k,sum;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {
  ll a,b;
  cin>>a>>b;
  sum+=b;
  m.push_back(a-b);
  }
if (sum>k)
  {
  cout<<-1;
  return 0;
  }
sort(m.begin(), m.end());
j=0;
while (j<n&&sum+m[j]<=k)
  {
  sum+=m[j];
  j++;
  }
cout<<n-j<<endl;



    return 0;
}
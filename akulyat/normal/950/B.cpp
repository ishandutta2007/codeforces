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


ll n,i,j,k;
vector <ll> m,m1;
bool viv=false;


int main()
{
cin>>n>>k;
ll s=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  s+=a;
  m.push_back(s);
  }
s=0;
for (i=0; i<k; i++)
  {
  ll a;
  cin>>a;
  s+=a;
  m1.push_back(s);
  }


m.push_back(inf);
m1.push_back(inf/2);
ll ans=0;
i=0; j=0;
while (i!=n||j!=k)
  {
//  cout<<i<<' '<<j<<endl;
  if (i==n||m[i]>m1[j])
    j++;
  else
    if (j==k||m[i]<m1[j])
      i++;

  if (i!=n&&j!=k)
    if (m[i]==m1[j])
      ans++, i++, j++;
  }

cout<<ans;



    return 0;
}
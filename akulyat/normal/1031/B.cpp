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
vector <ll> m,a,b;
bool viv=false;

void write()
{
cout<<"YES"<<endl;
for (auto i:m)
  cout<<i<<' ';
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n-1; i++)
  {
  ll v;
  cin>>v;
  a.push_back(v);
  }
for (i=0; i<n-1; i++)
  {
  ll v;
  cin>>v;
  b.push_back(v);
  }
for (j=0; j<4; j++)
  {
  m.clear();
  m.push_back(j);
  for (i=1; i<n; i++)
    for(ll u=0; u<4; u++)
      if ((m.back()|u)==a[i-1]&&(m.back()&u)==b[i-1])
        m.push_back(u), u=4;
  if (m.size()==n)
    write();
  }
cout<<"NO";


    return 0;
}
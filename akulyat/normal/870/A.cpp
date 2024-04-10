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


ll n1,n2,i,j;
vector <ll> m1,m2;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n1>>n2;
for (i=0; i<n1; i++)
  {
  ll a;
  cin>>a;
  m1.push_back(a);
  }
for (i=0; i<n2; i++)
  {
  ll a;
  cin>>a;
  m2.push_back(a);
  }
set <ll> s;
for (i=0; i<n1; i++)
  for (j=0; j<n2; j++)
  {
  ll z=m1[i];
    if (m2[j]!=m1[i])
      z*=10, z+=m2[j];
  s.insert(z);
  }
for (i=0; i<n1; i++)
  for (j=0; j<n2; j++)
  {
  ll z=m2[j];
    if (m2[j]!=m1[i])
      z*=10, z+=m1[i];
  s.insert(z);
  }

cout<<*s.begin()<<endl;



    return 0;
}
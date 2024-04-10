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
vector <ll> m,m1;
bool viv=false;


int main()
{
cin>>n;
ll k=ll(sqrt(n));
if (k*k>n)
  k--;

ll a=k;
while (a<n+k)
  {
  a=min(a, n);
  while ((a-1)%k)
    m.push_back(a), a--;
  m.push_back(a);
  a--;
  a+=2*k;
  }

k++;
a=k;
while (a<n+k)
  {
  a=min(a, n);
  while ((a-1)%k)
    m1.push_back(a), a--;
  m1.push_back(a);
  a--;
  a+=2*k;
  }
k--;

//cout<<k+((n-1)/k)*k+1<<':';
for (auto i:m)
  cout<<i<<' ';
cout<<endl;

/*
k++;
cout<<k+((n-1)/k)*k+1<<':';
for (auto i:m1)
  cout<<i<<' ';
cout<<endl;
*/



    return 0;
}
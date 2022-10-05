#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,l;
vector <ll> m;
bool viv=false;


int main()
{
cin>>l>>n;
for (i=0; i<n; i++)
  {
  cout<<l<<endl;
  ll ty;
  cin>>ty;
  if (ty==-1)
    m.push_back(true);
  else
    m.push_back(false);
  }

ll a=0;
ll b=l+1;
for (i=0; i<30; i++)
  {
  ll mi=a+b>>1;
  if (mi>l)
    mi=l;
  if (mi<1)
    mi=1;
  cout<<mi<<endl;
  ll ty;
  cin>>ty;
  if ((ty==-1)^(!m[i%n]))
    b=mi;
  else
    a=mi;
  }
cout<<a;


    return 0;
}
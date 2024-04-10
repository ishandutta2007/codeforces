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



ll n,i,j;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n;
if (n<=5)
  cout<<-1<<endl;
else
  {
  cout<<"1 2"<<endl;
  for (i=2; i<n; i++)
    if (i&1)
      cout<<1<<' '<<i+1<<endl;
    else
      cout<<2<<' '<<i+1<<endl;
  }
for (i=0; i<n-1; i++)
  cout<<i+1<<' '<<i+2<<endl;


    return 0;
}
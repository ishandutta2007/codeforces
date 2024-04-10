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


ll n,i,j,x,x1,d;
vector <ll> ans,st;
bool viv=false;


int main()
{
cin>>x>>d;
x1=x;
if (x&1)
  {
  ans.push_back(inf-8);
  x--;
  }
for (i=0; i<30; i++)
  st.push_back(x1&1), x1/=2;


ll z=1;
for (i=1; i<30; i++)
  if (st[i])
    {
    for (j=0; j<i; j++)
      ans.push_back(z);
    ans.push_back(z+d+1);
    z+=2*d+2;
    }

cout<<ans.size()<<endl;
for (auto i:ans)
  cout<<i<<' ';



    return 0;
}
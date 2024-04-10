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



ll n,i,j,res,pl,mi;
vector <string> m;
bool viv=false;
set <string> nn;
string s;

int main()
{
nn.insert("?");
nn.insert("-");
nn.insert("+");
nn.insert("=");
m.push_back("+");
s="+";
pl++;
while (nn.find(s)!=nn.end())
  {
  cin>>s;
  if (s=="+")
    pl++;
  if (s=="-")
    mi++;
  m.push_back(s);
  }
/*
for (auto i:m)
  cout<<i<<' ';
cout<<endl;
*/
n=m.size()-2;
ll r=0;
ll u=1;
while (m.back().size()>0)
  {
  r+=(m.back().back()-'0')*u;
  m.back().pop_back();
  u*=10;
  }

ll mar=pl*r-mi;
ll mir=pl-mi*r;
//cout<<r<<' '<<mir<<' '<<mar<<endl;

if (r<mir||mar<r)
  {
  cout<<"Impossible"<<endl;
  return 0;
  }

cout<<"Possible"<<endl;
ll raz=mar-r;
for (i=0; i<n; i++)
  {
  if (m[i]=="?")
    {
    ll z=-1;
    if (m[i-1]=="+")
      z=r;
    ll ub=min(raz, r-1);
      z-=ub;
    raz-=ub;
    cout<<abs(z)<<' ';
    }
  else
    if (i!=0)
      cout<<m[i]<<' ';
  }
cout<<"= "<<r<<endl;
    return 0;
}
/*
? + ? - ? + ? + ? = 42


*/
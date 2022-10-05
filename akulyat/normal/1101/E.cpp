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


ll n,i,j,a,b;
vector <ll> m;
bool viv=false;

void add()
{
ll x,y;
cin>>x>>y;
if (x<y)
  swap(x, y);
a=max(x, a);
b=max(y, b);
}

void ans()
{
ll x,y;
cin>>x>>y;
if (x<y)
  swap(x, y);
if (a<=x&&b<=y)
  cout<<"YES\n";
else
  cout<<"NO\n";
}




int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
a=0;
b=0;
while (n)
  {
  string ty;
  cin>>ty;
  if (ty[0]=='+')
    add();
  else
    ans();
  n--;
  }







    return 0;
}
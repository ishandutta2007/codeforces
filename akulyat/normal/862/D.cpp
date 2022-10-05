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



ll n,i,j,kol;
vector <ll> m;
bool viv=false;
string s,ems;

void solve2(ll p)
{
s=ems;
s[p]='1';
cout<<'?'<<' '<<s<<endl;
ll lkol;
cin>>lkol;
ll va=p, vb=p+1;
if (lkol<kol)
  {
  va=p+1;
  vb=p;
  }

cout<<'!'<<' '<<va+1<<' '<<vb+1<<endl;
exit(0);
}

int main()
{
cin>>n;
for (i=0; i<n; i++)
  ems+='0';
ll a=0;
ll b=n-1;
s=ems;
cout<<'?'<<' '<<s<<endl;
cin>>kol;

while (a+1<b)
  {
  s=ems;
  ll mi=a+b>>1;
  for (i=a; i<=mi; i++)
    s[i]='1';
  cout<<'?'<<' '<<s<<endl;
  ll lkol;
  cin>>lkol;
  if (abs(kol-lkol)!=abs(mi-a+1))
    b=mi;
  else
    a=mi;
  }
solve2(a);

    return 0;
}
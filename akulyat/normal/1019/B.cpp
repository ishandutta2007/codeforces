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


ll n,i,j,a,b,va,vb;
vector <ll> m;
bool viv=false;

void write(ll ans)
{
cout<<'!'<<' '<<ans+1<<endl;
exit(0);
}

ll ask(ll v)
{
cout<<'?'<<' '<<v+1<<endl;
ll newv=0;
cin>>newv;
return newv;
}


int main()
{
cin>>n;
if (n%4)
  write(-2);


va=ask(0);
vb=ask(n/2);
a=0;
b=n/2;
if (va==vb)
  write(0);
bool res=(va<vb);


while (va!=vb)
  {
  ll mi=a+b>>1;
  va=ask(mi);
  vb=ask(mi+n/2);
  if (va==vb)
    write(mi);
  if ((va<vb)==(res))
    a=mi;
  else
    b=mi;
  }




    return 0;
}
/*
   1 0
  2   1
  3   2
   2 3

   1 2
  2   3
  1   4
   2 3
*/
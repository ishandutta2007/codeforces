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
vector <ll> m;
bool viv=false;

long long GCD(long long a, long long b)
{
if (a==0&&b==0)
  return 1;
while (a!=0&&b!=0)
  {
  if (a>=b)
    a%=b;
  else
    b%=a;
  }
return a+b;
}

solve()
{
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll al,ar,bl,br,ta,tb;
cin>>al>>ar>>ta;
cin>>bl>>br>>tb;
ll d=GCD(ta,tb);
if (ar-al<br-bl)
  swap(al, bl),
  swap(ar, br);
ar-=al;
br-=al;
bl-=al;
al-=al;
bl+=(ml*ml/tb)*tb;
br+=(ml*ml/tb)*tb;
ll z=bl-bl%d;
bl-=z;
br-=z;
ll ans=0;
ans=max(ans, min(br, ar)-max(bl, al)+1);
bl-=d;
br-=d;
ans=max(ans, min(br, ar)-max(bl, al)+1);

cout<<ans;


    return 0;
}
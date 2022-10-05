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


ll n,i,j,a,b,c,x,y,z;
vector <ll> m;
bool viv=false;

void bad()
{
cout<<"NO";
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>x>>y>>z;
cin>>a>>b>>c;
ll d=min(x, a);
a-=d;
x-=d;
d=min(z, c);
c-=d;
z-=d;
if (x>0)
  bad();
if (z+y>a+b)
  bad();
cout<<"YES";





    return 0;
}
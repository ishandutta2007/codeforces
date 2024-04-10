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


ll n,i,j, a, x, b, y;
vector <ll> m;
bool viv=false;

void da()
{
cout<<"YES";
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>a>>x>>b>>y;
a--, x--, b--, y--;
while (a!=x&&b!=y)
  {
  if (a==b)
    da();
  a++;
  b+=n-1;
  a%=n;
  b%=n;
  }
if (a==b)
  da();
cout<<"NO"<<endl;


    return 0;
}
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


int main()
{
ll a,b,c;
cin>>a>>b>>c;

if (a>b)
  swap(a, b);

ll d=min(b-a, c);
c-=d;
a+=d;
c/=2;
a+=c;
b+=c;
cout<<min(a, b)*2;




    return 0;
}
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

void bad()
{
cout<<"NO";
exit(0);
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll x0,x1,x2,y0,y1,y2;
cin>>n;
cin>>x1>>y1;
cin>>x0>>y0;
cin>>x2>>y2;
if (abs(x2-x0)==abs(x2-x1)+abs(x1-x0))
  bad();
if (abs(y2-y0)==abs(y2-y1)+abs(y1-y0))
  bad();

cout<<"YES";


    return 0;
}
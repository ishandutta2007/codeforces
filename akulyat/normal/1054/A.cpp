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
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll x,y,z,t1,t2,t3;
cin>>x>>y>>z>>t1>>t2>>t3;
ll a=abs(x-y)*t1;
ll b=abs(x-y)*t2+abs(x-z)*t2+3*t3;
if (b<=a)
  cout<<"YES";
else
  cout<<"NO";

    return 0;
}
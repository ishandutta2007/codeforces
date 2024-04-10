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
ll a, b, p;
cin>>a>>b>>p;
cout<<(a+b)/p<<' ';
if ((a+b)/p==a/p+b/p)
  {
  cout<<0<<' ';
  exit(0);
  }
ll n1=a%p;
n1=p-n1;
if (n1==p)
  n1=0;

ll n2=b%p;
n2=p-n2;
if (n2==p)
  n2=0;

cout<<min(n1, n2);





    return 0;
}
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


ll n,i,j,k;
vector <ll> m;
bool viv=false;


int main()
{
cin>>n>>k;
if (k>=2*n)
  {
  cout<<0;
  return 0;
  }
if (k>n+1)
  k=2*(n+1)-k;
cout<<(k-1)/2<<endl;






    return 0;
}
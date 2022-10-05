#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j;
vector <ll> m;

int main()
{
cin>>n;
long kol=0;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  if (a==1)
    kol++;
  m.push_back(a);
  }
m.push_back(1);

cout<<kol<<endl;
for (i=0; i<n; i++)
  if (m[i+1]==1)
    cout<<m[i]<<' ';


    return 0;
}
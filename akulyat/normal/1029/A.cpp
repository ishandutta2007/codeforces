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


ll k,n,i,j;
vector <ll> m;
bool viv=false;
string s;

int main()
{
cin>>n>>k>>s;

ll best=0;
for (ll l=1; l<n; l++)
  {
  bool g=true;
  for (i=0; i<n-(n-l); i++)
    if (s[i]!=s[i+(n-l)])
      g=false;
  if (g)
    best=l;
  }

cout<<s;
for (i=1; i<k; i++)
  for (j=best; j<n; j++)
    cout<<s[j];


    return 0;
}
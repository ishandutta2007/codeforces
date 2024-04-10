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
string s;


int main()
{
cin>>s;
n=s.size();
s+=s;
for (auto i:s)
  m.push_back(1);

for (i=1; i<2*n; i++)
  if (s[i]!=s[i-1])
    m[i]=m[i-1]+1;

for (i=1; i<2*n; i++)
  m[i]=max(m[i], m[i-1]);

m[2*n-1]=min(m[2*n-1], n);
cout<<m[2*n-1]<<endl;





    return 0;
}
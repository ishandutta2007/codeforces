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


ll n,i,j,w;
bool viv=false;
string s,ans;


int main()
{
cin>>n>>w;
w/=2;
cin>>s;
vector <ll> m(n);

ll k=0;
for (i=0; i<n; i++)
  {
  if (s[i]=='(')
    m[i]=k, k++;
  }

k=0;
for (i=n-1; i>=0; i--)
  {
  if (s[i]==')')
    m[i]=k, k++;
  }

for (i=0; i<n; i++)
  if (m[i]<w)
    ans.push_back(s[i]);

cout<<ans;








    return 0;
}
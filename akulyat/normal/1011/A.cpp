#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;



ll n,i,j,k;
vector <ll> m;
long long kol[100];
bool viv=false;


int main()
{
cin>>n>>k;
string s;
cin>>s;
for (i=0; i<n; i++)
  kol[s[i]-'a']++;

ll z=0;
ll ans=0;
while (z<26)
  {
  if (k>0&&kol[z])
    {
    z++;
    ans+=z;
    k--;
    }
  z++;
  }
if (k)
  cout<<-1;
else
  cout<<ans;
    return 0;
}
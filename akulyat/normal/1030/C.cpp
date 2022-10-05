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
cin>>n;
string s;
cin>>s;
n=s.size();
ll sum=0;
for (i=0; i<n; i++)
  sum+=(s[i]-'0');
if (sum==0)
  {
  cout<<"YES"<<endl;
  return 0;
  }

for (i=1; i<sum; i++)
  if (sum%i==0)
    {
    ll k=0;
    ll need=sum/i;
    for (j=0; j<n; j++)
      {
      k+=(s[j]-'0');
      if (k%i==0&&s[j]!='0')
        need--;
      }
    if (!need)
      {
      cout<<"YES";
      return 0;
      }
    }
cout<<"NO";

    return 0;
}
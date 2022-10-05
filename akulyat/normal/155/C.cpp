#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;
const long long inf=ml*ml*ml+7;
ifstream in;
ofstream out;

ll n,i,j,k;
vector <ll> ans,z;
string s;

int main()
{
cin>>s;
n=s.size();
cin>>k;
for (i=0; i<26; i++)
  z.push_back(-1);
for (i=0; i<k; i++)
  {
  string ss;
  cin>>ss;
  ll a=ss[0]-'a';
  ll b=ss[1]-'a';
  z[a]=b;
  z[b]=a;
  }
s='#'+s;
n++;
ans.push_back(1);
ans.push_back(2);
vector <ll> last;
for (i=0; i<26; i++)
  last.push_back(-1);
last[s[1]-'a']=1;
ll best=2;
for (i=2; i<n; i++)
  {
  ll a=s[i]-'a';
//  wo.push_back(ans.back());
  ans.push_back(2);
  for (ll j=0; j<26; j++)
    if (last[j]!=-1&&z[a]!=j)
      ans.back()=max(ans.back(), ans[last[j]]+1);
  best=max(best, ans.back());
  last[a]=i;
  }
cout<<n-best;




    return 0;
}
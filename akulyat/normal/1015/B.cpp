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
string s,t,sos,sot;

int main()
{
cin>>n;
cin>>s>>t;
sos=s;
sot=t;
sort(sos.begin(), sos.end());
sort(sot.begin(), sot.end());
if (sos!=sot)
  {
  cout<<-1;
  return 0;
  }

vector <ll> ans;
for (ll p=0; p<n; p++)
  {
  j=p;
  while (t[p]!=s[j])
    j++;
  ll j1=j;
  for (i=j1-1; i>=p; i--)
    {
    swap(s[i], s[i+1]);
    ans.push_back(i);
    }
  }

cout<<ans.size()<<endl;
for (auto i:ans)
  cout<<i+1<<' ';



    return 0;
}
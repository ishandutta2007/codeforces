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


ll n,i,j,t;
vector <ll> s,x;
vector <ll> reb[300*kk];
vector <ll> ans;
vector <ll> col;
bool viv=false;
bool circ=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>t;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  s.push_back(a);
  }
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  a--;
  x.push_back(a);
  }
for (i=0; i<n-1; i++)
  if (x[i]>x[i+1]||x[i]<i)
    {
    cout<<"No";
    return 0;
    }
if (x[n-1]!=n-1)
  {
  cout<<"No";
  return 0;
  }
for (i=1; i<n-1; i++)
  if (x[i]!=x[i+1]&&x[i]==x[i-1])
    if (s[i]+1==s[i+1])
      {
      cout<<"No";
      return 0;
      }
for (i=0; i<n-1; i++)
  if (x[i]!=x[i+1])
    if (x[i]!=i)
      {
      cout<<"No";
      return 0;
      }

x.push_back(-1);
cout<<"Yes"<<endl;

vector <ll> ans;
ll last=0;
for (i=0; i<n; i++)
  {
  if (i==0||x[i]!=x[i-1])
    {
    ans.push_back(s[x[i]]+t-x[i]+i+1);
    if (x[i]==i)
      ans.back()--;
    }
  else
    ans.push_back(last+1);
  last=ans.back();
  }
for (auto i:ans)
  cout<<i<<' ';






    return 0;
}
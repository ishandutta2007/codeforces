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
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
ll p=-1;
for (i=0; i<n; i++)
  if (m[i]!=0)
    p=i;
if (p==-1)
  {
  cout<<"YES"<<endl;
  for (auto i:m)
    cout<<239<<' ';
  return 0;
  }

ll pm=0;
for (i=0; i<n; i++)
  if (m[i]>m[pm])
    pm=i;
ll kol=0;
for (i=0; i<n; i++)
  if (m[i]==m[pm]&&m[(i-1+n)%n]!=m[pm])
    kol++, p=i;
if (kol==0)
  {
  cout<<"NO"<<endl;
  return 0;
  }


vector <ll> ans;
for (i=0; i<n; i++)
  ans.push_back(m[(i+p+1)%n]);
for (i=n-2; i>=0; i--)
  {
  ans[i]=ans[i+1]+ans[i];
  if (i==n-2)
    ans[i]+=ans[i+1];
  }

vector <ll> dans;
for (i=0; i<n; i++)
  dans.push_back(ans[(i-p-1+n)%n]);
for (i=0; i<n; i++)
  ans[i]=dans[i];

cout<<"YES"<<endl;
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;


    return 0;
}
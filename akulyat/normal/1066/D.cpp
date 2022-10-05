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


ll n,k,s,i,j,l,r;
vector <ll> m;
bool viv=false;

bool work(ll x)
{
x=n-x;
vector <ll> v=m;
reverse(v.begin(), v.end());
while (v.size()>x)
  v.pop_back();

vector <ll> box;
for (i=0; i<k; i++)
  box.push_back(s);
while (!v.empty())
  {
  if (v.back()>s||box.empty()||(box.size()==1&&box.back()<v.back()))
    return false;
  if (box.back()<v.back())
    box.pop_back();
  box.back()-=v.back();
  v.pop_back();
  }
return true;
}



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k>>s;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
if (m.back()>s)
  {cout<<0; return 0;}

l=-1;
r=n-1;
while (l+1<r)
  if (work(l+r>>1))
    r=l+r>>1;
  else
    l=l+r>>1;

cout<<n-r<<endl;

    return 0;
}
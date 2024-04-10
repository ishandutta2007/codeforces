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


ll n,i,j, l;
vector <ll> m, ones, ans;
bool viv=false;
string s;

void cut()
{
m.push_back(0);
for (ll i=1; i<n; i++)
  if (s[i-1]=='0'&&s[i]=='1')
    m.push_back(i);
m.push_back(n);
l=m.size()-1;
}

void calc()
{
ones.push_back(0);
for (ll i=n-1; i>=0; i--)
  ones.push_back(ones.back()+(s[i]=='1'));
reverse(ones.begin(), ones.end());

ans.push_back(0);
for (ll i=n-1; i>=0; i--)
  {
  ans.push_back(ans.back());
  if (s[i]=='0')
    ans.back()++;
  ans.back()=max(ans.back(), ones[i]);
  }
reverse(ans.begin(), ans.end());
}

void make()
{
for (ll i=l-1; i>=0; i--)
  {
  ll dif=0;
  ll zero=0;
  for (ll j=m[i]; j<m[i+1]; j++)
    if (s[j]=='1')
      dif++;
    else
      dif--, zero++;
  dif=max(dif, 0ll);

  ll bst=-ans[m[i+1]]+ans[m[i]];
  bst-=zero;

  if (viv)
    cout<<"block "<<i<<' '<<dif<<' '<<bst<<endl;
  dif=min(dif, bst);
  for (ll j=m[i]; j<m[i]+dif; j++)
    s[j]='0';

  }
if (viv)
  {
  for (auto i:ans)
    cout<<i<<' ';
  cout<<endl;
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//viv=true;
cin>>s;
n=s.size();
cut();
calc();
make();
cout<<s<<endl;






    return 0;
}
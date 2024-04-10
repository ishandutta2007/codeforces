#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long ml=kk*kk;
const long long mod=ml*kk+7;

#define F first
#define S second
typedef long long   ll;
typedef long double ld;
typedef pair <ll, ll> pll;

ifstream in;
ofstream out;


ll n,i,j,c;
vector <ll> m;
bool viv=false;

int main()
{
//viv=true;
cin>>n>>c;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  }
m.push_back(-100000);

vector <ll> nex;
vector <ll> st;
st.push_back(n);
{
for (i=n-1; i>=0; i--)
  {
  ll v=m[i];
  while (v<m[st.back()])
    st.pop_back();
  nex.push_back(st.back());
  st.push_back(i);
  }
}
reverse(nex.begin(), nex.end());
if (viv)
  {
  cout<<"Nearest not bigger"<<endl;
  for (auto i:nex)
    cout<<i<<' ';
  cout<<endl;
  }
vector <ll> sum;
sum.push_back(0);
for (i=0; i<c; i++)
  sum.push_back(sum.back()+m[i]);
for (i=c; i<n; i++)
  sum.push_back(sum.back()-m[i-c]+m[i]);
if (viv)
  {
  cout<<"Summi po "<<c<<endl;
  for (i=0; i<=n; i++)
    cout<<sum[i]<<' ';
  cout<<endl;
  }

vector <ll> to;
ll p=0;
to.push_back(0);
for (i=1; i<c; i++)
  to.push_back(sum[i]);
for (i=c; i<=n; i++)
  {
  while (nex[p]<i)
    p=nex[p];
  if (p<i-c)
    p=i-c;
  while (nex[p]<i)
    p=nex[p];
  to.push_back(sum[i]-m[p]);
  }
if (viv)
  {
  cout<<"Summi po "<<c<<" s vichetom"<<endl;
  for (i=0; i<=n; i++)
    cout<<to[i]<<' ';
  cout<<endl;
  }


vector <ll> ans;
ans.push_back(0);
for (i=1; i<c; i++)
  ans.push_back(ans.back()+m[i-1]);
for (i=c; i<=n; i++)
  ans.push_back(min(ans.back()+m[i-1], ans[i-c]+to[i]));

if (viv)
  {
  cout<<"local answers"<<endl;
  for (i=0; i<=n; i++)
    cout<<ans[i]<<' ';
  cout<<endl;
  }

cout<<ans[n];




    return 0;
}
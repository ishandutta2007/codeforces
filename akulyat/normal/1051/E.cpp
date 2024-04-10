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
const long long mod=998244353;
const long long inf=ml*ml*ml+7;


ll n,i,j;
vector <ll> m;
bool viv=false;
string s,l,r;

vector <ll> z_function(const string & s)
{
ll n=s.size();
vector <ll> z(n);
ll l=0, r=0;
for (i=1; i<n; i++)
  {
  if (i<=r)
    z[i]=min(z[i-l], r-i+1);
  while (i+z[i]<n&&s[z[i]]==s[i+z[i]])
    z[i]++;
  if (i+z[i]-1>r)
    l=i, r=i+z[i]-1;
  }
return z;
}


int main()
{
// viv=true;
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>s>>l>>r;
n=s.size();
s+='#';
vector <ll> mo(max((ll)s.size()-l.size(), 0ll), false);
vector <ll> le(max((ll)s.size()-r.size(), 0ll), false);
{
vector <ll> ml=z_function(l+'#'+s);
vector <ll> mr=z_function(r+'#'+s);
if (viv)
  {
  cout<<l+'#'+s<<endl;
  for (auto i:ml)
    cout<<i<<' ';
  cout<<endl;
  cout<<r+'#'+s<<endl;
  for (auto i:mr)
    cout<<i<<' ';
  cout<<endl;
  }
j=l.size()+1;
for (auto &i:mo)
  {
  if (ml[j]>=l.size())
    i=true;
  else
    {
    ll p=ml[j];
    if (l[p]<s[j-(l.size()+1)+p])
      i=true;
    }
  j++;
  }
j=r.size()+1;
for (auto &i:le)
  {
  if (mr[j]>=r.size())
    i=true;
  else
    {
    ll p=mr[j];
    if (r[p]>s[j-(r.size()+1)+p])
      i=true;
    }
  j++;
  }
}
if (viv)
  {
  cout<<"More ans less"<<endl;
  for (auto i:mo)
    cout<<i;
  cout<<endl;
  for (auto i:le)
    cout<<i;
  cout<<endl;
  }

vector <ll> ans(n+2, 0);
vector <ll> pr(n+2, 0);
ans[0]=1;
pr[0]=1;
for (i=0; i<n; i++)
  {
  if (r.size()>l.size()+1)
    {
    if (i+1-l.size()-1>=0)
      ans[i+1]+=pr[i+1-l.size()-1];
    if (i+1-r.size()>=0)
      ans[i+1]-=pr[i+1-r.size()];
    if (viv)
      cout<<i+1<<' '<<"add between "<<i+1-r.size()+1<<" and "<<i+1-l.size()-1<<endl;
    }
  if(l.size()!=r.size())
    {
    if (i+1-l.size()>=0)
      if (mo[i+1-l.size()])
        {
        ans[i+1]+=ans[i+1-l.size()];
        if (viv)
          cout<<i+1<<' '<<"add "<<ans[i+1-l.size()]<<endl;
        }
    if (i+1-r.size()>=0)
      if (le[i+1-r.size()])
        {
        ans[i+1]+=ans[i+1-r.size()];
        if (viv)
          cout<<i+1<<' '<<"add "<<ans[i+1-r.size()]<<endl;
        }
    }
  else
    {
    if (i+1-r.size()>=0)
      if (le[i+1-r.size()]&&mo[i+1-l.size()])
        {
        ans[i+1]+=ans[i+1-r.size()];
        if (viv)
          cout<<i+1<<' '<<"add "<<ans[i+1-r.size()]<<endl;
        }
    }
  pr[i+1]=pr[i];
  if (s[i+1]=='0')
    {
    if (l.size()==1&&l[0]=='0')
      ans[i+2]+=ans[i+1];
    ans[i+1]=0;
    }
  pr[i+1]+=ans[i+1];


/*
  if (s[i]!='0')
    pr[i+1]+=ans[i+1];
  else
    {
    if (l.size()>1||(s[i+1]>=l[0]&&(r.size()>1||s[i+1]<=r[0])))
      if (l.size()==1&&l[0]=='0')
        {
        ans[i+2]+=ans[i];
        if (viv)
          cout<<i+2<<" add "<<ans[i]<<"by the zero reason\n";
        }
    }
*/

  pr[i+1]%=mod;
  ans[i+1]%=mod;
  pr[i+1]+=mod;
  ans[i+1]+=mod;
  pr[i+1]%=mod;
  ans[i+1]%=mod;
  }
if (viv)
  {
  for (i=0; i<=n; i++)
    cout<<ans[i]<<' ';
  cout<<endl;
  }
cout<<ans[n]<<endl;




    return 0;
}
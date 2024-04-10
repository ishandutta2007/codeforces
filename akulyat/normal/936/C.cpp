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
vector <ll> m,ans;
bool viv=false;
string s,t;


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


void upd()
{
if (viv)
  cout<<"Update "<<s<<" and "<<t<<endl,
  cout<<"From "<<j<<" to ";
while (j<n&&s[j]==t[j])
  j++;
if (viv)
  cout<<j<<endl;
}

void shift(ll k)
{
ans.push_back(k);
string r;
while (k)
  r.push_back(s.back()),
  s.pop_back(),
  k--;
r+=s;
s=r;
}


void doit()
{
string tuz=t.substr(j, n-j)+'#'+s;
vector <ll> v=z_function(tuz);
if (viv)
  {
  cout<<tuz<<endl;
  for (auto i:v)
    cout<<i<<' ';
  cout<<endl;
  }
ll k=0;
ll ma=-1;
for (ll i=j; i<n; i++)
  if (v[i+n-j+1]>ma)
    ma=v[i+n-j+1], k=i;
k=n-k;
if (viv)
  cout<<k<<endl;
shift(n);
shift(n-k);
shift(n);
shift(j);
}



int main()
{
srand(time(0));
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
cin>>s>>t;
vector <ll> alf(26, 0);
for (auto i:s)
  alf[i-'a']++;
for (auto i:t)
  alf[i-'a']--;
for (auto i:alf)
  if (i)
    {
    cout<<-1;
    return 0;
    }

ll kol=00;
for (i=0; i<kol; i++)
  shift(rand()%n+1);

j=0;
upd();
while (j!=n)
  {
  doit();
  upd();
  }
if (viv)
  cout<<s<<endl,
  cout<<t<<endl;
cout<<ans.size()<<endl;
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;
    return 0;
}
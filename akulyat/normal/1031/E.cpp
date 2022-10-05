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
vector <ll> m,m2;
vector <vector <ll> > ans;
set <ll> black;
bool viv=false;

void work2(vector <ll> v)
{
for (auto i:v)
  m2[i]^=1;
ans.push_back(v);
}

void easy()
{
vector <vector <ll> > var;
for (ll i=0; i<n; i++)
  for (ll j=i+1; j<n; j++)
    for (ll u=j+1; u<n; u++)
      if (u+i==2*j)
        var.push_back({i, j, u});
ll l=var.size();
m2.resize(n);
for (ll q=0; q<(1ll<<l); q++)
  {
  ll q1=q;
  ans.clear();
  for (auto &i:m2)
    i=0;
  vector <bool> will;
  for (i=0; i<l; i++)
    {
    if (q1&1)
      work2(var[i]);
    q1>>=1;
    }
  if (m2==m)
    {
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    for (auto i:ans)
      {
      for (auto j:i)
        cout<<j+1<<' ';
      cout<<endl;
      }
    exit(0);
    }
  }
cout<<"NO";
exit(0);
}

void work(ll a, ll b, ll c)
{
if (viv)
  {
  for (auto i:m)
    cout<<i<<' ';
  cout<<endl;
  }
m[a]^=1;
m[b]^=1;
m[c]^=1;
if (viv)
  {
  for (auto i:m)
    cout<<i<<' ';
  cout<<endl;
  cout<<endl;
  }
ans.push_back({a, b, c});
for (auto i:ans.back())
  if (black.find(i)!=black.end())
    black.erase(i);
  else
    black.insert(i);
}

void remove(ll x)
{
work(x, x+3, x+6);
work(x+3, x+4, x+5);
work(x+4, x+5, x+6);
}

void run()
{
bool cont=true;
ll kol=0;
while (cont&&kol<7000)
  {
  cont=false;
  for (ll j=0; j<7000; j++)
    if (black.size())
 /*
      {
      ll pa=rand()%black.size();
      ll pb=rand()%black.size();
      ll a=*(black.begin()+pa);
      ll b=*(black.begin()+pb);
      ll c=(2*b-a);
      if (a!=b&&black.find(c)!=black.end())
        cont=true, work(a, b, c);
      }
// */
      {
      ll a=rand()%n;
      ll b=rand()%n;
      ll c=2*b-a;
      if (a!=b&&c<n&&c>=0&&m[a]&&m[b]&&m[c])
        cont=true, work(a, b, c);
      }
  kol++;
  }
}

void haters()
{
/*
while (!black.empty()&&(*black.rbegin()>n-7))
  {
  p=*black.rbegin();
  work(p-2, p-1, p);
  }
// */
for (i=n-1; i>=0; i--)
  for (j=1; j<=4002; j++)
    if (i-2*j>=0)
      if (m[i]&&m[i-j]&&m[i-2*j])
        work(i, i-j, i-2*j);
run();
ll j=n-1;
while (j>=6)
  {
  if (m[j])
    {
    vector <ll> last;
    for (ll u=j-5; u<=j; u++)
      last.push_back(m[u]);
    if (last[3]&&last[4])
      work(j-2, j-1, j);
    else
      {
      if (last[3])
        work(j-4, j-2, j);
      else
        {
        if (last[4])
          {
          work(j-2, j-1, j);
          }
        else
          {
          ll near=0;
          if (black.size()>1)
            ll near=*(black.rbegin()--);
          ll l=min(j/2, j-near);
          work(j-2*l, j-l, j);
          }
        }
      }
    }
  j--;
  }
while (j>=2)
  {
  if (m[j])
    work(j-2, j-1, j);
  j--;
  }
}

int main()
{
srand(time(0));
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (i=0; i<n; i++)
  {
  ll a;
  cin>>a;
  m.push_back(a);
  if (m[i])
    black.insert(i);
  }
if (n<8)
  easy();
haters();
for (i=0; i<2; i++)
  if (m[i])
    remove(i);
cout<<"YES"<<endl;
cout<<ans.size()<<endl;
for (auto i:ans)
  {
  for (auto j:i)
    cout<<j+1<<' ';
  cout<<'\n';
  }

    return 0;
}
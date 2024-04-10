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


ll n,i,j, m;
vector <vector <ll> > p;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
p.resize(n);
ll good=-1;
ll res=0;
for (i=0; i<n; i++)
  {
  set <ll> s;
  for (ll j=0; j<m; j++)
    {
    ll a;
    cin>>a;
    p[i].push_back(a);
    s.insert(a);
    }
  res^=p[i][0];
  if (s.size()>1)
    good=i;
  }
if (res!=0)
  {
  cout<<"TAK"<<endl;
  for (ll i=0; i<n; i++)
    cout<<1<<' ';
  exit(0);
  }

if (res==0&&good==-1)
  {
  cout<<"NIE";
  exit(0);
  }
ll j=1;
while (p[good][j]==p[good][j-1])
  j++;
vector <ll> ans(n);
for (auto &i:ans)
  i=1;
ans[good]=j+1;

cout<<"TAK"<<endl;
for (auto i:ans)
  cout<<i<<' ';






    return 0;




}
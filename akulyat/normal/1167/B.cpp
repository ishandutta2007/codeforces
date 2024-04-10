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
vector <ll> m, ans;
bool viv=false;


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

for (ll i=0; i<4; i++)
  {
  cout<<"? "<<i+1<<' '<<i+2<<endl;
  ll val;
  cin>>val;
  m.push_back(val);
  }
m.push_back((4*8*15*16*23*42)/(m[0]*m[2]));
ans.resize(6, -1);
bool n42=true;
bool n15=true;
bool n23=true;
for (ll i=0; i<4; i++)
  {
  if (m[i]%7==0&&m[i+1]%7==0)
    ans[i+1]=42, n42=false;
  if (m[i]%5==0&&m[i+1]%5==0)
    ans[i+1]=15, n15=false;
  if (m[i]%23==0&&m[i+1]%23==0)
    ans[i+1]=23, n23=false;
  }
if (n42==true)
  if (m[0]%42==0)
    ans[0]==42;
  else
    ans.back()==42;
if (n15==true)
  if (m[0]%15==0)
    ans[0]==15;
  else
    ans.back()==15;
if (n23==true)
  if (m[0]%23==0)
    ans[0]==23;
  else
    ans.back()==23;

/**
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;
**/

srand(time(0));
for (ll i=0; i<ml/100; i++)
  {
  ll a=rand()%5;
  ll b=a+1;
  if (rand()&1)
    swap(a, b);
  if (ans[a]!=-1)
    ans[b]=m[min(a, b)]/ans[a];
  }

cout<<"! ";
for (auto i:ans)
  cout<<i<<' ';
cout<<endl;

    return 0;
}
/**
32
120
240
368





**/
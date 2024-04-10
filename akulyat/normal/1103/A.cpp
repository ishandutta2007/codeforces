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
ll kol[2];
bool viv=false;

void work(ll t)
{
kol[t]++;
kol[t]%=4;
if (t==0)
  {
  if (kol[0]%2==1)
    cout<<1<<' '<<1<<endl;
  if (kol[0]%2==0)
    cout<<3<<' '<<1<<endl;
  }
if (t==1)
  {
  if (kol[1]==1)
    cout<<1<<' '<<3<<endl;
  if (kol[1]==2)
    cout<<2<<' '<<3<<endl;
  if (kol[1]==3)
    cout<<3<<' '<<3<<endl;
  if (kol[1]==0)
    cout<<4<<' '<<3<<endl;
  }
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
cin>>s;
n=s.size();
for (auto i:s)
  work(i-'0');



    return 0;
}
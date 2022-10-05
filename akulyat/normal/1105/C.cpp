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


ll n,i,j,l,r;
vector <ll> m;
bool viv=false;
ll v[3];
ll kol[3];

void work()
{
vector <ll> add(3, 0);
for (ll i=0; i<3; i++)
  for (ll j=0; j<3; j++)
    {
    ll ost=(i+j)%3;
    ll val=kol[i]*v[j];
    val%=mod;
    add[ost]+=val;
    add[ost]%=mod;
    }
for (ll i=0; i<3; i++)
  {
  v[i]=add[i];
 // cout<<kol[i]<<' ';
 // cout<<v[i]<<' ';
  }
//cout<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>l>>r;
v[0]=1;
kol[0]=kol[1]=kol[2]=(r-l+1)/3;
while ((r+1)%3!=l%3)
  kol[r%3]++, r--;
//kol[r%3]++, r--;


for (ll i=0; i<n; i++)
  work();
cout<<v[0]<<endl;






    return 0;
}
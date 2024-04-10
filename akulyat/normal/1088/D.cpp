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
const ll B=30;

ll n,i,j,dif=0, type;
vector <ll> m,bin;
bool viv=false;

void build()
{
bin.push_back(1);
for (ll i=1; i<=60; i++)
  bin.push_back(bin.back()*2);
}

ll ask(ll c, ll d)
{
cout<<"? "<<c<<' '<<d<<endl;
ll r;
cin>>r;
return r;
}

void easy()
{

}

void work()
{
ll sh=ask(0, 0);
//if (!sh)
//  easy();
ll add=0;
vector <ll> bit(B, -1);
for (ll i=B-1; i>=0; i--)
  {
  ll c=bin[i];
  ll d=bin[i];
  d+=add;
  if (sh==ask(c, d))
    {}
  else
    {
    add+=bin[i];
//    sh=ask(0, add);
    if (sh==1)
      bit[i]=1;
    else
      bit[i]=0;
    sh=ask(0, add);
  //  cout<<"Bit "<<i<<" is "<<bit[i]<<endl;
    }
  }
//cout<<"Their Xor is "<<add<<endl;
ll a=0,b=0;
for (ll i=B-1; i>=0; i--)
  if (bit[i]==-1)
    {
    ll c=add;
    ll d=bin[i];
    if (ask(c, d)==1)
      bit[i]=1;
    else
      bit[i]=0;
//    cout<<"Bit "<<i<<" is "<<bit[i]<<endl;
    }
for (i=0; i<B; i++)
  b+=bit[i]*bin[i];
a=b^add;
cout<<"! "<<b<<' '<<a<<endl;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
build();
work();




    return 0;
}
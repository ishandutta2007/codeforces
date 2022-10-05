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
//const long long inf=ml*ml*ml+7;


ll n,i,j, m;
bool viv=false;

long long obr(long long v, ll st, long long mod)
{
long long i=0;
vector <long long> bin;
long long l=0;
while(st>0)
  {
  bin.push_back(st&1);
  st/=2;
  l++;
  }

vector <long long> sq;
sq.push_back(v);
for (i=1; i<l; i++)
  {
  long long s=sq.back();
  s*=s;
  s%=mod;
  sq.push_back(s);
  }

long long ans=1;
for (i=0; i<l; i++)
  if (bin[i])
    {
    ans*=sq[i];
    ans%=mod;
    }
return ans;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
cout<<obr(2, n+m, mod);



    return 0;
}
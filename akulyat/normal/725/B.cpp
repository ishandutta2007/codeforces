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
bool viv=false;

ll str_to_ll(string s)
{
ll r=0;
for (auto i:s)
  {r*=10ll; r+=(i-'0'); }
return r;
}


int main()
{
string s;
cin>>s;

ll b=s.back()-'a';
s.pop_back();
ll a=str_to_ll(s);
a--;
//cout<<a<<endl;
ll ans=0;
ans+=(a/4)*16;
a%=4;
a%=2;
ans+=a*7;
a=0;

if (b==4)
  ans++;
if (b==3)
  ans+=2;
if (b==0)
  ans+=3;
if (b==1)
  ans+=4;
if (b==2)
  ans+=5;

ans++;
cout<<ans;




    return 0;
}
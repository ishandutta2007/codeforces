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


string ll_to_str(long long v)
{
string s="";
if (v==0)
  return "0";
bool obr=false;
if (v<0)
  obr=true;
v=abs(v);
while (v>0)
  {
  short e=v%10;
  s+=char('0'+e);
  v/=10;
  }
reverse(s.begin(), s.end());
if (obr)
  s='-'+s;
return s;
}


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
if (n<=9)
  {
  cout<<n<<endl;
  return 0;
  }
ll ten=10;
while (ten*10-1<=n)
  ten*=10;
ten--;
string a=ll_to_str(ten);
string b=ll_to_str(n-ten);
ll ans=0;
for (auto i:a)
  ans+=(i-'0');
for (auto i:b)
  ans+=(i-'0');
cout<<ans<<endl;






    return 0;
}
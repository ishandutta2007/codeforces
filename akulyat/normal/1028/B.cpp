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


ll n,m,i,j;
string a,b,s;
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

string raz(string s, string a)
{
reverse(a.begin(), a.end());
reverse(s.begin(), s.end());
//cout<<"Raz "<<s<<' '<<a<<endl;
while (a.size()<s.size())
  a+='0';
vector <ll> r;
for (i=0; i<max(a.size(), s.size()); i++)
  r.push_back(0);
for (i=0; i<s.size(); i++)
  r[i]=s[i]-a[i];
for (i=0; i<r.size()-1; i++)
  if (r[i]<0)
    {
    r[i]+=10;
    r[i+1]--;
    }

while (r.back()==0)
  r.pop_back();

string ans;
for (auto i:r)
  ans+=ll_to_str(i);
reverse(ans.begin(), ans.end());
return ans;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>m;
string s;
s+='1';
for (i=0; i<2000; i++)
  s+='0';

for (i=0; i<(n/9)+3; i++)
  a+='9';

b=raz(s, a);

cout<<a<<endl;
cout<<b<<endl;




    return 0;
}
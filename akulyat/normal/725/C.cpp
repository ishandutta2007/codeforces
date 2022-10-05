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


ll n,i,j,a,b;
vector <ll> m;
string s,s1;
string ans[2];
bool viv=false;

ll write(ll p, ll buk)
{
p%=26;
buk%=26;
//cout<<"Work "<<p<<' '<<buk<<' ';
//cout<<"add "<<s1[buk]<<endl;
if (p<13)
  ans[0][p]=s1[buk];
else
  ans[1][25-p]=s1[buk];

if (((buk+1)%26)!=a)
  write(p+1, buk+1);
}





int main()
{
cin>>s;
n=s.size();
for (i=0; i<n; i++)
  for (j=i+1; j<n; j++)
    if (s[i]==s[j])
      a=i, b=j;

if (abs(a-b)==1)
  {
  cout<<"Impossible";
  return 0;
  }

for (i=0; i<n; i++)
  if (i!=b)
    s1+=s[i];
//cout<<s1<<endl;

ll r=abs(b-a);
r--;
r/=2;

r=12-r;

for (i=0; i<13; i++)
  ans[0]+='a', ans[1]+='a';
write(r, a);

for (auto i:ans[0])
  cout<<i;
cout<<endl;
for (auto i:ans[1])
  cout<<i;
cout<<endl;











    return 0;
}
/*
ABCDEFGHIJKLMNOPQRSTGUVWXYZ



*/
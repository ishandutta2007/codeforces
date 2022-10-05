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
map <char, ll> t;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n;
for (char i='a'; i<='z'; i++)
  t[i]=0;
for (char i='A'; i<='Z'; i++)
  t[i]=1;
for (char i='0'; i<='9'; i++)
  t[i]=2;

for (i=0; i<n; i++)
  {
  string s;
  cin>>s;
  ll m[3]={0, 0, 0};
  ll kol=0;
  for (auto j:s)
    m[t[j]]++;
//  cout<<m[0]<<' '<<m[1]<<' '<<m[2]<<endl;
  if (m[0]==0)
    kol++;
  if (m[1]==0)
    kol++;
  if (m[2]==0)
    kol++;
  if (kol==0)
    {
    cout<<s<<endl;
    }
  else
    {
    if (kol==1)
      {
      if (m[0]==0)
        {
        if (m[t[s[0]]]>1)
          s[0]='a';
        else
          s[1]='a';
        }
      if (m[1]==0)
        {
        if (m[t[s[0]]]>1)
          s[0]='A';
        else
          s[1]='A';
        }
      if (m[2]==0)
        {
        if (m[t[s[0]]]>1)
          s[0]='0';
        else
          s[1]='0';
        }
      }
    else
      {
      if (m[0]!=0)
        s[0]='A', s[1]='0';
      if (m[1]!=0)
        s[0]='a', s[1]='0';
      if (m[2]!=0)
        s[0]='A', s[1]='a';
      }
    cout<<s<<endl;
    }
  }








    return 0;
}
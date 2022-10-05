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
vector <ll> m[10];
vector <char> p[10];
bool viv=false;
map <char, ll> ch;
map <ll, char> buk;

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ch['.']=0;
ch['x']=1;
ch['o']=2;
buk[0]='.';
buk[1]='x';
buk[2]='o';
n=9;
ll a=0,b=0;
for (i=0; i<n; i++)
  {
  for (j=0; j<3; j++)
    {
    string s;
    cin>>s;
    for (ll u=0; u<3; u++)
      {
      m[i].push_back(ch[s[u]]);
      }
    }
  }
cin>>a>>b;
a--; b--;
a%=3;
b%=3;
ll kol=0;
for (i=0; i<n; i++)
  for (j=0; j<n; j++)
    {
    p[i].push_back(buk[m[i][j]]);
    if (p[i].back()=='.')
      if (i/3==a&&j/3==b)
        p[i].back()='!', kol++;
    }
if (!kol)
  {
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      if (p[i][j]=='.')
        p[i][j]='!';
  }



for (i=0; i<n; i++)
  {
  if (i%3==0&&i)
    cout<<endl;
  for (j=0; j<n; j++)
    {
    if (j%3==0&&j)
      cout<<' ';
    cout<<p[i][j];
    }
  cout<<endl;
  }




    return 0;
}
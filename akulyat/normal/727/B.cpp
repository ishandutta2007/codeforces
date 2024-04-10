#include <bits/stdc++.h>

using namespace std;

string s;
long long n,i,j,k;
vector <string> m;
long p[3000];


int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

cin>>s;
s+='r';
n=s.size();


for (i=0; i<n; i++)
  {
  if (s[i]>='0'&&s[i]<='9')
    {
    long j=i;
    while ((s[j]>='0'&&s[j]<='9')||(s[j]=='.'))
      j++;
    m.push_back("");
    for (long u=i; u<j; u++)
      m.back()+=s[u];
    k++;
    if (m[k-1].size()<3||m[k-1][m[k-1].size()-3]!='.')
      m[k-1]+=".00";
    i=j-1;
    }
  }
/*
for (i=0; i<k; i++)
  cout<<m[i]<<endl;
*/
for (i=0; i<k; i++)
  reverse(m[i].begin(), m[i].end());
for (i=0; i<k; i++)
  m[i]+='.';

for (long u=0; u<k; u++)
  {
  long l=m[u].size();
  long z=0;
  long ch=0;
  long st=1;
  for (i=0; i<l; i++)
    {
    if (m[u][i]!='.')
      {
      ch+=(m[u][i]-'0')*st;
      st*=10;
      }
    else
      {
      p[z]+=ch;
      z++;
      ch=0;
      st=1;
      }
    }
  }

p[1]+=p[0]/100;
p[0]%=100;
for (i=1; i<2000; i++)
  {
  p[i+1]+=p[i]/1000;
  p[i]%=1000;
  }

long long last;
for (i=0; i<2000; i++)
  if (p[i]!=0)
    last=i;

if (last==0)
  {
  cout<<"0.";
  if (p[0]<10)
    cout<<"0";
  cout<<p[0];
  return 0;
  }

cout<<p[last];
if (last>1||p[0]!=0)
  cout<<'.';
last--;
for (i=last; i>0; i--)
  {
  if (p[i]<100)
    {
    cout<<"0";
    if (p[i]<10)
      cout<<"0";
    }
  cout<<p[i];

  if (i>1||p[0]!=0)
    cout<<'.';
  }
if (p[0]!=0)
  {
  if (p[0]<10)
    cout<<"0";
  cout<<p[0];
  }
    return 0;
}
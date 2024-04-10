#include <bits/stdc++.h>

using namespace std;

struct mine
{
  long long num, kol, from;
};

const long long kk=1000;
const long long inf=kk*kk*kk;
long n,m,i,j;
mine e[kk];
string s;

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
cin>>n>>m;
for (long i=0; i<m; i++)
  {
  long a,b,c;
  cin>>a>>b>>c;
  e[b]={i+1, c, a};
  }

for (i=1; i<=n; i++)
  {
  if (e[i].from!=0)
    {
    s+=ll_to_str(m+1);
    s+=' ';
    }
  else
    {
    for (j=i+1; j<=n; j++)
      {
      if (e[j].from<=i&&e[j].kol>0)
        {
        e[j].kol--;
        s+=ll_to_str(e[j].num);
        s+=' ';
        j=inf-1;
        }
      }
    if (j==n+1)
      s+="0 ";
    }
  }

for (i=1; i<=n; i++)
  if (e[i].kol>0)
    s="-1";

cout<<s;
    return 0;
}
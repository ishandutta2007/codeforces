#include <bits/stdc++.h>

using namespace std;

long long a[10][2], b[10][2];
long long i,j;

bool pra(long long x, long long y)
{
long long i,j;
long od=0;
for (i=0; i<4; i++)
  for (j=i+1; j<4; j++)
    if (a[i][0]==a[j][0])
      od++;

if (od==2)
  {
  long long s=0;
  long long c=0;
  long long d=0;
  for (i=0; i<4; i++)
    for (j=0; j<4; j++)
      s=max(s, abs(a[i][0]-a[j][0]));
  for (i=0; i<4; i++)
    c+=abs(x-a[i][0]);
  for (i=0; i<4; i++)
    d+=abs(y-a[i][1]);
  if (c>2*s)
    return false;
  if (d>2*s)
    return false;
  return true;
  }

long long xma=-10000;
long long xmi= 10000;
long long yma=-10000;
long long ymi= 10000;

for (i=0; i<4; i++)
  {
  xma=max(xma, a[i][0]);
  xmi=min(xmi, a[i][0]);
  yma=max(yma, a[i][1]);
  ymi=min(ymi, a[i][1]);
  }

long long s=xma-xmi;
s/=2;
long long cx=(xma+xmi)/2;
long long cy=(yma+ymi)/2;

long long r=abs(cx-x)+abs(cy-y);
if (r<=s)
  return true;

return false;


}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////



bool prb(long long x, long long y)
{
long long i,j;
long od=0;
for (i=0; i<4; i++)
  for (j=i+1; j<4; j++)
    if (b[i][0]==b[j][0])
      od++;

if (od==2)
  {
  long long s=0;
  long long c=0;
  long long d=0;
  for (i=0; i<4; i++)
    for (j=0; j<4; j++)
      s=max(s, abs(b[i][0]-b[j][0]));
  for (i=0; i<4; i++)
    c+=abs(x-b[i][0]);
  for (i=0; i<4; i++)
    d+=abs(y-b[i][1]);
  if (c>2*s)
    return false;
  if (d>2*s)
    return false;
  return true;
  }

long long xma=-10000;
long long xmi= 10000;
long long yma=-10000;
long long ymi= 10000;

for (i=0; i<4; i++)
  {
  xma=max(xma, b[i][0]);
  xmi=min(xmi, b[i][0]);
  yma=max(yma, b[i][1]);
  ymi=min(ymi, b[i][1]);
  }

long long s=xma-xmi;
s/=2;
long long cx=(xma+xmi)/2;
long long cy=(yma+ymi)/2;

long long r=abs(cx-x)+abs(cy-y);
if (r<=s)
  return true;

return false;


}

int main()
{
for (i=0; i<4; i++)
  {
  cin>>a[i][0]>>a[i][1];
  }
for (i=0; i<4; i++)
  {
  cin>>b[i][0]>>b[i][1];
  }

for (i=0; i<4; i++)
  {
  a[i][0]*=2;
  b[i][0]*=2;
  a[i][1]*=2;
  b[i][1]*=2;
  }

long kol=0;
for (i=-300; i<301; i++)
  for (j=-300; j<301; j++)
//    if (!(i&1)&&!(j&1))
    if (pra(i, j)&&prb(i,j))
      {
      cout<<"YES"<<endl;
      return 0;
    //  cout<<i/2<<' '<<j/2<<endl;
    //  kol++;
      }
//cout<<kol<<endl;
cout<<"NO"<<endl;

    return 0;
}
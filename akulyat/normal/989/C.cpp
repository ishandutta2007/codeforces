#include <bits/stdc++.h>

using namespace std;

long long a,b,c,d,i,j;
long long p[1000][1000];

int main()
{
cin>>a>>b>>c>>d;
a--;
d--;
cout<<50<<' '<<50<<endl;

i=0;
j=0;
while (a>0)
  {
  p[i][j]=1;
  p[i+1][j]=4;
  p[i+1][j+1]=4;
  p[i][j+1]=4;
  j+=2;
  a--;
  if (j>=50)
    {
    j=0;
    i+=2;
    }
  }
while (b>0)
  {
  p[i][j]=2;
  p[i+1][j]=4;
  p[i+1][j+1]=4;
  p[i][j+1]=4;
  j+=2;
  b--;
  if (j>=50)
    {
    j=0;
    i+=2;
    }
  }

while (c>0)
  {
  p[i][j]=3;
  p[i+1][j]=4;
  p[i+1][j+1]=4;
  p[i][j+1]=4;
  j+=2;
  c--;
  if (j>=50)
    {
    j=0;
    i+=2;
    }
  }


for (i=49; i>0; i-=2)
  for (j=0; j<50; j+=2)
    {
    if (d>0)
      {
      p[i][j]=4;
      d--;
      }
    }



for (i=0; i<50; i++)
  for (j=0; j<50; j++)
    if (p[i][j]==0)
      p[i][j]=1;

for (i=0; i<50; i++)
  {
  for (j=0; j<50; j++)
    cout<<char(p[i][j]-1+'A');
  cout<<endl;
  }



    return 0;
}
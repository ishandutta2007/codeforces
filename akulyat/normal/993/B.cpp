#include <bits/stdc++.h>

using namespace std;

struct mine
{
  long long a,b;
};

vector <mine> m1, m2;
long long n1,n2,i,j;
long long isee[10];
long long can[2][20][2];

int main()
{
cin>>n1>>n2;
for (i=0; i<n1; i++)
  {
  long long a,b;
  cin>>a>>b;
  m1.push_back({a,b});
  }
for (i=0; i<n2; i++)
  {
  long long a,b;
  cin>>a>>b;
  m2.push_back({a,b});
  }

for (i=0; i<n1; i++)
  for (j=0; j<n2; j++)
    {
    if (m1[i].a==m2[j].a&&m1[i].b!=m2[j].b)
      {
      long long ch=m1[i].a;
      isee[ch]=1;
      can[0][i][0]=1;
      can[1][j][0]=1;
      }
    if (m1[i].a==m2[j].b&&m1[i].b!=m2[j].a)
      {
      long long ch=m1[i].a;
      isee[ch]=1;
      can[0][i][0]=1;
      can[1][j][1]=1;
      }
    if (m1[i].b==m2[j].b&&m1[i].a!=m2[j].a)
      {
      long long ch=m1[i].b;
      isee[ch]=1;
      can[0][i][1]=1;
      can[1][j][1]=1;
      }
    if (m1[i].b==m2[j].a&&m1[i].a!=m2[j].b)
      {
      long long ch=m1[i].b;
      isee[ch]=1;
      can[0][i][1]=1;
      can[1][j][0]=1;
      }
    }

long long kol=0;
for (i=1; i<10; i++)
  kol+=isee[i];
if (kol==1)
  {
  for (i=1; i<10; i++)
    if (isee[i]==1)
      {
      cout<<i<<endl;
      return 0;
      }
  }

for (i=0; i<n1; i++)
  if (can[0][i][0]+can[0][i][1]==2)
    {
    cout<<-1;
    return 0;
    }
for (i=0; i<n2; i++)
  if (can[1][i][0]+can[1][i][1]==2)
    {
    cout<<-1;
    return 0;
    }

cout<<0<<endl;






    return 0;
}
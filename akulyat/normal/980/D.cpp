#include <bits/stdc++.h>

using namespace std;

long n,i,j;
vector <long> m,ch;
long gr[5003][5003], kol[5003][5003];
long all[5003];

long sm(long v)
{
for (long i=2; i<=1000; i++)
  while (v%(i*i)==0)
    v/=(i*i);
return v;
}

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back(a); }
/*
for (i=0; i<n; i++)
  cout<<m[i]<<' ';
cout<<endl;
*/
for (i=0; i<n; i++)
  if (m[i]!=0)
    m[i]=sm(m[i]);
/*
for (i=0; i<n; i++)
  cout<<m[i]<<' ';
cout<<endl;
*/

for (i=0; i<n; i++)
  {
  bool f=true;
  for (j=0; j<i; j++)
    if (m[i]==m[j])
      f=false;
  if (f&&m[i]!=0)
    ch.push_back(m[i]);
  }

for (i=0; i<n; i++)
  for (j=0; j<ch.size(); j++)
    if (m[i]==ch[j])
      {
      m[i]=j+1;
      j=ch.size();
      }

/*
for (i=0; i<n; i++)
  cout<<m[i]<<' ';
cout<<endl;
*/

kol[m[0]][0]=1;
for (i=1; i<n; i++)
  {
  for (j=0; j<=n; j++)
    {
    kol[j][i]=kol[j][i-1];
    if (m[i]==j)
      kol[j][i]++;
    }
  }
for (i=0; i<n; i++)
  gr[i][i]=1;
for (long l=1; l<n; l++)
  {
  for (i=0; i<n-l; i++)
    {
    gr[i][i+l]=gr[i][i+l-1];
    long z=kol[m[i+l]][i+l-1];
    if (i!=0)
      z-=kol[m[i+l]][i-1];
    if (m[i+l]!=0&&z==0)
      gr[i][i+l]++;
    long z0=kol[0][i+l-1];
    if (i!=0)
      z0-=kol[0][i-1];
    if (m[i+l]!=0&&z==0)
      if (z0==l)
        gr[i][i+l]--;

    }
  }
for (i=0; i<n; i++)
  for (j=i; j<n; j++)
    all[gr[i][j]]++;

for (i=0; i<n; i++)
  cout<<all[i+1]<<' ';
cout<<endl;


    return 0;
}
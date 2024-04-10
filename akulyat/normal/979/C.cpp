#include <bits/stdc++.h>

using namespace std;

const long kk=100000;
long long n,x,y;
vector <long long> reb[6*kk];
long long colx[6*kk];
long long coly[6*kk];
long long wasx=-1;
long long badx=-1;
long long wasy=-1;
long long bady=-1;
long long kolx=0, koly=0;
long long fkolx=0, fkoly=0;
long long ans=0;
long long howx[6*kk];
long long howy[6*kk];

void DFSx(long long v, long long p)
{
colx[v]=1;
if (v==y)
  {
  wasx=1;
  badx=p;
  }
if (wasx==1&&badx==p)
  kolx++;

long long l=reb[v].size();
for (long long i=0; i<l; i++)
  {
  long long s=reb[v][i];
  if (colx[s]==0)
    {
    if (v==x)
      p++;
    DFSx(s, p);
    }
  }
if (v==y)
  fkolx=kolx;

}

  void DFSy(long long v, long long p)
{
coly[v]=1;
if (v==x)
  {
  wasy=1;
  bady=p;
  }
if (wasy==1&&bady==p)
  koly++;

long long l=reb[v].size();
for (long long i=0; i<l; i++)
  {
  long long s=reb[v][i];
  if (coly[s]==0)
    {
    if (v==y)
      p++;
    DFSy(s, p);
    }
  }
if (v==x)
  fkoly=koly;

}


int main()
{
cin>>n>>x>>y;
  x--;
  y--;

for (long long i=0; i<n-1; i++)
  {
  long long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }

for (long long i=0; i<n; i++)
  colx[i]=0;
DFSx(x, 0);
for (long long i=0; i<n; i++)
  coly[i]=0;
DFSy(y, 0);

/*
long long ly=0;
for (long i=0; i<n; i++)
  if (how[i]==bad)
    ly++;
if (how[x]==bad)
  ly--;
ly=n-ly;
*/
//for (long i=0; i<n; i++)
//  cout<<how[i]<<' ';
//cout<<bad<<endl;
//cout<<endl;

//cout<<kol<<endl;
//cout<<ly<<endl;
ans=n*(n-1);
//cout<<fkolx<<' '<<fkoly<<endl;

ans-=((long long)fkolx*fkoly);
cout<<ans;

    return 0;
}
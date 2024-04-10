#include <bits/stdc++.h>

using namespace std;

const long long kk=1000;
const long long mod=kk*kk*kk+7;
const long long gs=500*kk;


long n,i,j,k;
vector <long> reb[gs+10];
vector <long> m, uch;
long long col[gs+10];
long long fcol[gs+10];
long long path[gs+10];
bool iam[gs];
long good;
long dif=0;
bool viv=false;

void DFS(long v, long c)
{
col[v]=c;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (col[s]==-1)
    {
    DFS(s, c+1);
    }
  }
}

void fDFS(long v, long c, long d)
{
fcol[v]=c;
path[v]=d;
long l=reb[v].size();
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (fcol[s]==-1)
    {
    if (v==good)
      {
      dif++;
      fDFS(s, c+1, dif);
      }
    else
      fDFS(s, c+1, d);

    }
  }
}

long cou(long v)
{
long l=reb[v].size();
long r=0;
for (long i=0; i<l; i++)
  {
  long s=reb[v][i];
  if (uch[s]!=-1)
    r+=uch[s];
  if (viv)
    cout<<"I add "<<uch[s]<<" k "<<v<<" from "<<s<<endl;
  }
if (iam[v])
  r++;
return r;
}


int main()
{
viv=false;

cin>>n>>k;
k*=2;

for (i=0; i<n-1; i++)
  {
  long a,b;
  cin>>a>>b;
  a--; b--;
  reb[a].push_back(b);
  reb[b].push_back(a);
  }
for (i=0; i<n; i++)
  col[i]=-1;
for (i=0; i<k; i++)
  {long a; cin>>a; a--; m.push_back(a); iam[a]=true;}

if (viv)
  {
  for (i=0; i<n; i++)
    cout<<iam[i];
  cout<<endl;
  }

DFS(0, 0);
if (viv)
  {
  for (i=0; i<n; i++)
    cout<<col[i]<<' ';
  cout<<endl;
  }


vector <pair<long, long> > s;
for (i=0; i<n; i++)
  s.push_back({col[i], i});
sort(s.rbegin(), s.rend());


good=-1;

for (i=0; i<n; i++)
  uch.push_back(-1);

for (i=0; i<n; i++)
  {
  long v=s[i].second;
  long z=cou(v);
  if (viv) cout<<v<<' '<<z<<endl;
  uch[v]=z;
  if (z>=k/2)
    {
    good=v;
    i=n;
    }
  }

if (viv)
  cout<<"Use "<<good<<endl;

for (i=0; i<n; i++)
  fcol[i]=-1;
fDFS(good, 0, 0);

vector <pair <long, long> > ost;
for (i=0; i<n; i++)
  if (iam[i])
    {
    ost.push_back({path[i], i});
    }
sort(ost.begin(), ost.end());

if (viv)
  {
  for (i=0; i<ost.size(); i++)
    cout<<'{'<<ost[i].first<<' '<<ost[i].second<<'}'<<' ';
  cout<<endl;
  }


cout<<1<<endl;
cout<<good+1<<endl;
for (i=0; i<k/2; i++)
  {
  cout<<ost[i].second+1<<' '<<ost[i+k/2].second+1<<' '<<good+1<<endl;
  }




    return 0;
}
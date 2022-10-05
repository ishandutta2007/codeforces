#include <bits/stdc++.h>

using namespace std;

struct mine
{
  long long p,d,i;
};


bool cmp(mine a, mine b)
{
if (a.p<b.p)
  return true;
if (a.p>b.p)
  return false;
if (a.d<b.d)
  return true;
if (a.d>b.d)
  return false;
if (a.i<b.i)
  return true;
if (a.i>b.i)
  return false;

return true;
}


vector <mine> m;
long long n,i,k;
vector <long long> who;
long long ans[200000];



int main()
{
cin>>n>>k;
for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back({a, 0, i}); }
for (i=0; i<n; i++)
  {long long a; cin>>a; m[i].d=a; }

sort (m.begin(), m.end(), cmp);
/*
for (i=0; i<n; i++)
  cout<<'{'<<m[i].p<<' '<<m[i].d<<' '<<m[i].i<<'}'<<' ';
cout<<endl;
*/
vector <long long> who;
long long sum=0;
for (i=0; i<k; i++)
  {
  sum+=m[i].d;
  who.push_back(m[i].d);
  ans[m[i].i]=sum;
  }

for (i=k; i<n; i++)
  {
  if (k>0)
    sort (who.begin(), who.end());
  long long sum=0;
  for (long long j=0; j<k; j++)
    sum+=who[j];
  long long v=m[i].d;
  sum+=v;
  ans[m[i].i]=sum;
  if (k>0)
    if (who[0]<v)
      who[0]=v;
  }

for (i=0; i<n; i++)
  cout<<ans[i]<<' ';




    return 0;
}
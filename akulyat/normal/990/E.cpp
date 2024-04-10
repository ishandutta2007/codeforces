#include <bits/stdc++.h>

using namespace std;

long long n,l,k,i,j;
vector <long long> m,b,g;
bool bit[3*1000*1000];



int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>l>>k;
for (i=0; i<l; i++)
  {long long a; cin>>a; b.push_back(a); }
for (i=0; i<k; i++)
  {long long a; cin>>a; m.push_back(a); }
if (l>0&&b[0]==0)
  {
  cout<<-1;
  return 0;
  }



long long mini=1;
if (l>0)
  mini=2;
long long z=0;
for (i=1; i<l; i++)
  if (b[i]==b[i-1]+1)
    {
    z++;
    mini=max(z+2, mini);
    }
  else
    z=0;

if (mini>k)
  {
  cout<<-1;
  return 0;
  }

for (i=0; i<n; i++)
  bit[i]=false;
for (i=0; i<l; i++)
  {
  bit[b[i]]=true;
  }

g.push_back(0);
for (i=1; i<n; i++)
  {
  if (!bit[i])
    g.push_back(i);
  else
    g.push_back(g.back());
  }
/*
for (i=0; i<n; i++)
  cout<<g[i]<<' ';
cout<<endl;
*/
long long ans=1000000000000000;
for (long long u=mini; u<=k; u++)
  {
  long long place=0;
  long long price=m[u-1];
  long long hod=0;
  while (place<n)
    {
    place+=u;
    if (place<n)
      place=g[place];
    hod++;
    }
  ans=min(ans, hod*price);
//  cout<<"try "<<u<<' ';
//  cout<<hod*price<<endl;
  }
cout<<ans;
    return 0;
}
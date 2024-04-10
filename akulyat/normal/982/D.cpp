#include <bits/stdc++.h>

using namespace std;

const long kk=100*1000;
long n,i,j;
long ans,best,maxs;

long kol[2*kk];
long bef[2*kk];
vector <pair<long, long> > m2;
set <long> s;

void sea()
{
while (kol[maxs]==0&&maxs>1)
  maxs--;
}

int main()
{
cin>>n;

for (i=0; i<n; i++)
  {long a; cin>>a;m2.push_back({a, i});}
sort(m2.rbegin(), m2.rend());
if (n==1)
  {
  cout<<m2[0].first+1;
  return 0;
  }
s.insert(-1); s.insert(n);
bef[n]=-1;
kol[n]=1;
maxs=n;

long best=0;

for (i=0; i<n; i++)
  {
  long pl=m2[i].second;
  long e=m2[i].first;
  //long next1=*lower_bound(s.begin(), s.end(), pl);
  long next=*s.lower_bound(pl);
  long last=bef[next];
  bef[pl]=last;
  bef[next]=pl;
  s.insert(pl);
  long fd=pl-last-1;
  long sd=next-pl-1;
  kol[fd+sd+1]--;
  kol[fd]++;
  kol[sd]++;
  sea();
  if (kol[maxs]+kol[0]==i+2)
    if (kol[maxs]>=best)
      {
      best=kol[maxs];
      ans=m2[i+1].first+1;
      }
//  cout<<i<<' '<<maxs<<' '<<ans<<' '<<best<<endl;
  }
cout<<ans;


    return 0;
}
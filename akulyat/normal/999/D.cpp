#include <bits/stdc++.h>

using namespace std;

const long long ss=900000;
long long n,k,i,j,ans;
vector <long long> m,ost;
vector <long long> num[ss];
bool alr;

void add()
{
if (!alr)
  for (long long i=0; i<k; i++)
    ost.push_back(ost[i]);
alr=true;
}

int main()
{
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cin>>n>>k;
for (i=0; i<k; i++)
  ost.push_back(0);
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  ost[a%k]++;
  num[a%k].push_back(i);
  }
long long sh=n/k;


j=0;
for (i=0; i<k; i++)
  {
  j=max(j, i);
  while (ost[i]>sh)
    {
    long long p=num[i].back();
    num[i].pop_back();
    ost[i]--;
    while (j<k&&ost[j]>=sh)
      j++;
    if (j>=k)
      add();
    if (j>=k)
      while (j<2*k&&ost[j]>=sh)
        j++;
    ans+=j-i;
    m[p]+=j-i;
    ost[j]++;
    num[j].push_back(p);
    }
  }

cout<<ans<<endl;
for (auto i:m)
  cout<<i<<' ';


    return 0;
}
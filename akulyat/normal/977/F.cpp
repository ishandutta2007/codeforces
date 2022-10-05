#include <bits/stdc++.h>

using namespace std;

long n,i,j;
vector <long long> m,m1,m2,ans;
long from[300000],last[300000];

int main()
{
cin>>n;
for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back(a); m1.push_back(a);}

for (i=0; i<n; i++)
  ans.push_back(0);

sort(m1.begin(), m1.end());
m2.push_back(m1[0]);

for (i=1; i<n; i++)
  if (m1[i]!=m1[i-1])
    m2.push_back(m1[i]);

for (i=0; i<n; i++)
  from[i]=-1;
for (i=0; i<n; i++)
  last[i]=-2;

for (i=0; i<n; i++)
  {
  ans[i]=0;
  long a,b;
  long el=m[i];
  a=-1; b=m2.size()-1;
  while (a+1!=b)
    {
    long mi=(a+b)/2;
    if (m2[mi]>=el)
      b=mi;
    else
      a=mi;
    }
  last[b]=i;
  if (b>0&&m2[b-1]+1==m2[b]&&last[b-1]!=-2)
    {
    ans[i]=ans[last[b-1]]+1;
    from[i]=last[b-1];
    }
  }

long max=-1;

long ff=-1;
for (i=0; i<n; i++)
  {
  if (ans[i]>max)
    {
    max=ans[i];
    ff=i;
    }
  }

vector <long> kak;

while (from[ff]!=-1)
  {
  kak.push_back(ff);
  ff=from[ff];
  }
kak.push_back(ff);

cout<<kak.size()<<endl;

reverse(kak.begin(), kak.end());
for (i=0; i<kak.size(); i++)
  cout<<kak[i]+1<<' ';
cout<<endl;
//for (i=0; i<n; i++)
//  cout<<from[i]<<' ';


    return 0;
}
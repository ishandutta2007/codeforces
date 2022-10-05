#include <bits/stdc++.h>

using namespace std;

long long n,i,j;
vector <long long> m;
long long use(long long v)
{
vector <long long> k=m;
long long fal=k[v]/n;
long long ost=k[v]%n;
k[v]=0;
for (long long i=0; i<n; i++)
  k[i]+=fal;
for (long long i=1; i<=ost; i++)
  k[(v+i)%n]++;
long long la=0;
for (long long i=0; i<n; i++)
  if (!(k[i]&1))
    la+=k[i];
return la;
}

int main()
{
n=14;
for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back(a); }

long long ans=0;
for (long long v=0; v<n; v++)
  ans=max(use(v), ans);

cout<<ans;




    return 0;
}
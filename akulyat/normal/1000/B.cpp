#include <bits/stdc++.h>

using namespace std;

long long i,n,l;
vector <long long> m;
vector <long long> a[2];

int main()
{
cin>>n>>l;
m.push_back(0);
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  }
m.push_back(l);
n+=2;




a[0].push_back(0);
a[1].push_back(0);
long long p=0;
for (i=1; i<n; i++)
  {
  long long z=m[i]-m[i-1];
  a[p].push_back(a[p].back()+z);
  a[p^1].push_back(a[p^1].back());
  p^=1;
  }

/*
for (i=0; i<n; i++)
  cout<<a[0][i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<a[1][i]<<' ';
cout<<endl;
*/

long long ans=a[0][n-1];
for (i=0; i<n-1; i++)
  if (m[i+1]-m[i]>=2)
    {
    long long ll=m[i+1]-m[i];
    long long p=i&1;
    long long lans=0;
    lans+=a[0][i];
    lans+=a[1][n-1]-a[1][i+1];
    lans+=(ll-1);
    ans=max(ans, lans);
    }

cout<<ans;



    return 0;
}
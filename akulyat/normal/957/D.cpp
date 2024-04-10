#include <bits/stdc++.h>

using namespace std;

long n,i;
vector <long long> m;
long long ans;
long long maxi[200000], hot[200000];
int main()
{
cin>>n;
for (i=0; i<n; i++)
{long a; cin>>a; m.push_back(a);}


maxi[0]=m[0];
for (i=1; i<n; i++)
  maxi[i]=max(maxi[i-1], m[i]);
hot[n-1]=m[n-1];
for (i=n-2; i>=0; i--)
  hot[i]=max(m[i], hot[i+1]-1);

/*
for (i=0; i<n; i++)
  cout<<maxi[i]<<' ';
cout<<endl;
for (i=0; i<n; i++)
  cout<<hot[i]<<' ';
cout<<endl;
*/

for (i=0; i<n; i++)
  maxi[i]=max(maxi[i], hot[i]);
for (i=0; i<n; i++)
  ans+=(max((long long)0, maxi[i]-m[i]));

cout<<ans;

/*
long mu=-1;
long best=0;
for (i=0; i<n; i++)
  if (m[i]>mu)
  {
  mu=m[i];
  best=i;
  }
hot[n-1]=m[n-1];
for (i=n-2; i>=0; i--)
  hot[i]=max(m[i], hot[i+1]-1);
for (i=0; i<n-1; i++)
  hot[i]=hot[i+1];
for (i=0; i<n; i++)
  cout<<hot[i]<<' ';
*/

   return 0;
}
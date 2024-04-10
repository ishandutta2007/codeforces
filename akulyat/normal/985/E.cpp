#include <bits/stdc++.h>

using namespace std;

const long kk=1000;
long n,k,d,i,j;
vector <long long> m;
long kol[kk*kk];

int main()
{
cin>>n>>k>>d;
for (i=0; i<n; i++)
  {long a; cin>>a; m.push_back(a);}
sort (m.begin(), m.end());

long j=0;
kol[0]=1;
for (i=k-1; i<n; i++)
  {
  kol[i+1]=kol[i];
  while (m[i]-m[j]>d)
    {
    if (kol[j]>0)
      kol[i+1]--;
    j++;
    }
  if (kol[i+1-k]>0&&i-k+1>=j)
    kol[i+1]++;
  if (j>i-k+1)
    kol[i+1]=0;
  }
  /*
for (i=0; i<=n; i++)
  cout<<kol[i]<<' ';
cout<<endl;
//   */
if (kol[n]>0)
  cout<<"YES";
else
  cout<<"NO";

    return 0;
}
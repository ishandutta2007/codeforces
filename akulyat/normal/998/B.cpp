#include <bits/stdc++.h>

using namespace std;

long long n,i,kol,b;
vector <long long> m,all,odd;

int main()
{
cin>>n>>b;
long long kol=0;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  kol+=(a&1);
  odd.push_back(kol);
  }

for (i=0; i<n-1; i++)
  if (odd[i]*2==i+1)
    all.push_back(abs(m[i+1]-m[i]));

sort(all.begin(), all.end());
long long k=all.size();
long long j=0;
while (j<k&&(b-all[j]>=0))
  {
  b-=all[j];
  j++;
  }
/*
for (i=0; i<k; i++)
  cout<<all[i]<<' ';
cout<<endl;
*/
cout<<j<<endl;



    return 0;
}
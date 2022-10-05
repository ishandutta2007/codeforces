#include <bits/stdc++.h>

using namespace std;

const long dk=200000;
long long v[dk],t[dk],ans[dk],ost[dk];
vector <long long> sum;
long long i,n;

int main()
{
cin>>n;
for (i=0; i<n; i++)
  cin>>v[i];
for (i=0; i<n; i++)
  cin>>t[i];

sum.push_back(0);
for (i=0; i<n; i++)
    sum.push_back(sum[i]+t[i]);
/*
for (i=0; i<=n; i++)
  cout<<sum[i]<<' ';
cout<<endl;
*/
for (i=0; i<n; i++)
  {
  long long a=lower_bound(sum.begin(), sum.end(), sum[i]+v[i])-sum.begin();
  ost[a]--;
  ans[a]+=sum[i]+v[i]-sum[a-1];
//  cout<<i<<' '<<a<<' '<<sum[i]+v[i]-sum[a-1]<<' '<<endl;
  }
/*
for (i=1; i<=n; i++)
  cout<<ost[i]<<' ';
cout<<endl;
for (i=1; i<=n; i++)
  cout<<ans[i]<<' ';
cout<<endl;
*/
long long kol=ost[0];
for (i=1; i<=n; i++)
  {
  kol++;
  kol+=ost[i];
  cout<<ans[i]+kol*t[i-1]<<' ';
  }
    return 0;
}
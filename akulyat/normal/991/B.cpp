#include <bits/stdc++.h>

using namespace std;

long long sum;
long long n,i;
long long m[10];
int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m[a]++;
  sum+=a;
  }

long long p=n/2;
long long need=9*p;
if (n&1)
  need+=5;

long long ans=0;
for (i=2; i<5; i++)
  {
  while (m[i]>0&&sum<need)
    {
    m[i]--;
    sum+=(5-i);
    ans++;
    }
  }

cout<<ans;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

long n;
long ans1, ans2;
vector <long> m;
int main()
{
cin>>n;
for (long i=0; i<n/2; i++)
{
long a;
cin>>a;
m.push_back(a);
}
sort(m.begin(), m.end());
for (long i=0; i<n/2; i++)
  {
  long a=m[i];
  a--;
  ans1+=abs(2*i-a);
  }
for (long i=0; i<n/2; i++)
  {
  long a=m[i];
  a--;
  ans2+=abs(2*i+1-a);
  }
cout<<min(ans1, ans2);

    return 0;
}
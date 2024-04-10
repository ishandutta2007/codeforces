#include <bits/stdc++.h>

using namespace std;

long long n,q,i,j;
vector <long long> m;
vector <long long> sum;
int main()
{
cin>>n>>q;
for (i=0; i<n; i++)
  {long long a; cin>>a; m.push_back(a); }
sum.push_back(0);
for (i=0; i<n; i++)
  sum.push_back(sum.back()+m[i]);

long long f=0;
long long power=m[f];
long long cur=sum[n];
for (long u=0; u<q; u++)
  {
  long long s;
  cin>>s;
  if (cur<=s)
    {
    cout<<n<<endl;
    cur=sum[n];
    f=0;
    power=m[f];
    }
  else
    {
    long long a=f-1;
    long long b=n;
    while (a+1!=b)
      {
      long long mi=(a+b)/2;
      if (s>=power+sum[mi+1]-sum[f+1])
        a=mi;
      else
        b=mi;
      }
    power=(power+sum[b+1]-sum[f+1])-s;
    f=b;
    cur-=s;
    cout<<n-f<<endl;
    }

  }

    return 0;
}
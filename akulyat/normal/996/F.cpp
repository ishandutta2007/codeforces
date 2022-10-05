#include <bits/stdc++.h>

using namespace std;

long long n,r,i,sum;
vector <long long> m;


int main()
{
cin>>n>>r;
double k=1<<n;
for (i=0; i<k; i++)
  {long long a; cin>>a; m.push_back(a); sum+=a; }

cout.precision(10);
cout<<fixed<<(double)sum/k<<'\n';
for (i=0; i<r; i++)
  {
  long long p;
  cin>>p;
  long long v;
  cin>>v;
  sum+=v;
  sum-=m[p];
  m[p]=v;
  cout<<fixed<<(double)sum/k<<'\n';
  }



    return 0;
}
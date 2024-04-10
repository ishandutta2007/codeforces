#include <bits/stdc++.h>

using namespace std;

long long n,i,j,k;
vector <pair <long long, long long> > m;


int main()
{
cin>>k>>n;
for (i=0; i<n; i++)
  {
  long long a,b;
  cin>>a>>b;
  m.push_back({a, b});
  }


for (i=0; i<k; i++)
  cout<<(i&1);



    return 0;
}
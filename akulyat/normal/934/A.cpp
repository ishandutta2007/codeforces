#include <bits/stdc++.h>

using namespace std;

int main()
{
//    cout << "Hello world!" << endl;
long n,m;
vector <long > m1,m2;
cin>>n>>m;
for (long i=0; i<n; i++)
  {
  long a;
  cin>>a;
  m1.push_back(a);
  }
for (long i=0; i<m; i++)
  {
  long a;
  cin>>a;
  m2.push_back(a);
  }
sort(m1.begin(), m1.end());
sort(m2.begin(), m2.end());
vector <long long> ans;
for (long j=0; j<n; j++)
  {
  long long maxi=-1000000000000000001;
  for (long i=0; i<n; i++)
    for (long u=0; u<m; u++)
    if (i!=j)
      {
      if ((long long )m1[i]*m2[u]>maxi)
        maxi=(long long)m1[i]*m2[u];
      }
  ans.push_back(maxi);
//  cout<<maxi<<endl;
  }
sort(ans.begin(), ans.end());
cout<<ans[0];

    return 0;
}
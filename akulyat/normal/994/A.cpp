#include <bits/stdc++.h>

using namespace std;


long long n1,n2,i,j,u;
vector <long long> m1,m2;
int main()
{
cin>>n1>>n2;
for (i=0; i<n1; i++)
  {long a; cin>>a; m1.push_back(a);}
for (i=0; i<n2; i++)
  {long a; cin>>a; m2.push_back(a);}

for (i=0; i<n1; i++)
  {
  for (j=0; j<n2; j++)
    {
    if (m1[i]==m2[j])
      {
      cout<<m1[i]<<' ';
      j=n2;
      }
    }
  }




    return 0;
}
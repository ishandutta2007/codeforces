#include <bits/stdc++.h>

using namespace std;

long long n,i,sum;
vector <long long> m;
int main()
{
cin>>n;
for (i=0; i<n; i++)
  {
  long long a;
  cin>>a;
  m.push_back(a);
  sum+=a;
  }
if (n==1)
  {
  cout<<-1;
  return 0;
  }
if (n==2&&(m[0]==m[1]))
  {
  cout<<-1;
  return 0;
  }

if (2*m[0]==sum)
  {
  cout<<2<<endl;
  cout<<"1 2"<<endl;
  return 0;
  }

cout<<1<<endl;
cout<<1<<endl;

    return 0;
}
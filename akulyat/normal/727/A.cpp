#include <bits/stdc++.h>

using namespace std;

long long a,b,i;
vector <long long> m;
int main()
{
cin>>a>>b;
m.push_back(b);
while (m.back()>a)
  {
  if (!(m.back()&1))
    {
    long long l=m.back()/2;
    m.push_back(l);
    }
  else
    {
    if (m.back()%10==1)
      {
      long long l=m.back()/10;
      m.push_back(l);
      }
    else
      {
      cout<<"NO"<<endl;
      return 0;
      }
    }
  }

if (m.back()!=a)
  {
  cout<<"NO"<<endl;
  return 0;
  }


cout<<"YES"<<endl;
reverse(m.begin(), m.end());

cout<<m.size()<<endl;
for (long i=0; i<m.size(); i++)
  cout<<m[i]<<' ';


    return 0;
}
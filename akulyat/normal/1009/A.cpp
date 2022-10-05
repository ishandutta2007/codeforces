#include <bits/stdc++.h>

using namespace std;

vector <long long> m,k;
int main()
{
long long n,l,i,j;
cin>>n>>l;
for (i=0; i<n; i++)
  {
  long long a;
    cin>>a;
    m.push_back(a);
  }
for (i=0; i<l; i++)
  {
  long long a;
    cin>>a;
    k.push_back(a);
  }
reverse(m.begin(), m.end());
reverse(k.begin(), k.end());

long long ans=0;
while(!m.empty()&&!k.empty())
  {
  if (k.back()>=m.back())
    {
    k.pop_back();
    ans++;
    }
  m.pop_back();
  }

cout<<ans;
    return 0;
}
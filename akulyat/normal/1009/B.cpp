#include <bits/stdc++.h>

using namespace std;

long long n,i;
vector <long long> m[3];

int main()
{
string s,ans;
cin>>s;
n=s.size();

for (i=0; i<n; i++)
  {
  m[s[i]-'0'].push_back(i);
  }
reverse(m[0].begin(), m[0].end());
reverse(m[1].begin(), m[1].end());
reverse(m[2].begin(), m[2].end());

for (i=0; i<n; i++)
  {
//  cout<<i<<' '<<m[0].size()<<' '<<m[1].size()<<' '<<m[2].size()<<endl;
  if ((!m[0].empty())&&(m[2].empty()||m[2].back()>m[0].back()))
      {
      ans+='0';
      m[0].pop_back();
      }
  else
    {
    if (!m[1].empty())
      {
      ans+='1';
      m[1].pop_back();
      }
    else
      {
      ans+='2';
      m[2].pop_back();
      }
    }

  }

cout<<ans;

    return 0;
}
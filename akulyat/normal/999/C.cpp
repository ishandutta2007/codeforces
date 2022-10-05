#include <bits/stdc++.h>

using namespace std;


string s,ans;
long long n,k,i,j;
vector <long long> m;

int main()
{
cin>>n>>k>>s;
for (i=0; i<26; i++)
  m.push_back(0);

for (i=0; i<n; i++)
  m[s[i]-'a']++;


for (i=0; i<26; i++)
  {
  long long z=min(m[i], k);
  k-=z;
  m[i]-=z;
  }

for (i=n-1; i>=0; i--)
  {
  if (m[s[i]-'a']>0)
    {
    m[s[i]-'a']--;
    ans+=s[i];
    }
  }

reverse(ans.begin(), ans.end());
cout<<ans;


    return 0;
}
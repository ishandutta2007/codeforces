#include <bits/stdc++.h>

using namespace std;

string s,t;
long long i,j;
vector <long long> m[26];
vector <bool> need;

int main()
{
cin>>s>>t;
long n=s.size();

for (i=0; i<n; i++)
  {
  char a=s[i], b=t[i];
  m[a-'a'].push_back(b-'a');
  m[b-'a'].push_back(a-'a');
  }

for (i=0; i<26; i++)
  while (m[i].size()>1&&m[i][m[i].size()-1]==m[i][m[i].size()-2])
    m[i].pop_back();

long long kol=0;
for (i=0; i<26; i++)
  {
  if (m[i].size()>1)
    {
    cout<<-1;
    return 0;
    }
  if (m[i].size()==1&&i!=m[i].back())
    { need.push_back(true); kol++; }
  else
    need.push_back(false);

  }
cout<<kol/2<<endl;
for (i=0; i<26; i++)
  if (need[i])
    {
    cout<<(char)('a'+i)<<' '<<(char)('a'+m[i][0])<<endl;
    need[m[i][0]]=false;
    }

    return 0;
}
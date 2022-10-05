#include <iostream>

using namespace std;

string s;
long n,i;
long kol[100];
long l;

int main()
{
cin>>s;
n=s.size();
for (i=0; i<n; i++)
  kol[s[i]-'a']++;

for (i=0; i<26; i++)
  if (kol[i])
    l++;

if (l==1||l>4)
  {
  cout<<"No"<<endl;
  return 0;
  }

if (l==4)
  {
  cout<<"Yes"<<endl;
  return 0;
  }
if (l==3&&n>3)
  {
  cout<<"Yes"<<endl;
  return 0;
  }

for (i=0; i<26; i++)
  if (kol[i]==1)
    {
    cout<<"No"<<endl;
    return 0;
    }

cout<<"Yes"<<endl;

    return 0;
}
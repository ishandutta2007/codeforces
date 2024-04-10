#include <bits/stdc++.h>

using namespace std;

long n,i;
string s;

void ch(long i)
{
long j=i+3;
while (j+1<s.size()&&s[j]=='g'&&s[j+1]=='o')
  j+=2;
string ss;
for (long u=0; u<i; u++)
  ss+=s[u];

ss+="***";
for (long u=j; u<s.size(); u++)
  ss+=s[u];

s=ss;

}

int main()
{
cin>>n>>s;
for (i=0; i<s.size(); i++)
  {
  if (s[i]=='o'&&s[i+1]=='g'&&s[i+2]=='o')
    {
    ch(i);
    i=-1;
    }
  }

cout<<s;

    return 0;
}
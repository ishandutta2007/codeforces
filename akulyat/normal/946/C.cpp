#include <bits/stdc++.h>

using namespace std;

string s;
long long i,u;
int main()
{
cin>>s;
long n=s.size();

long long last=-1;
for (u=0; u<26; u++)
  {
  long long p=-1;
  for (i=n-1; i>last; i--)
    if (s[i]<=char('a'+u))
      p=i;
  if (p==-1)
    {
    cout<<-1;
    return 0;
    }
  s[p]=char('a'+u);
  last=p;
  }

cout<<s;

    return 0;
}
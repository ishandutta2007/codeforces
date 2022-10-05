#include <bits/stdc++.h>

using namespace std;

string s;
long n,i;
long k[10][10];
int main()
{
cin>>s;
n=s.size();
s='.'+s+'.';

for (i=1; i<n+1; i++)
  {
  if (s[i-1]+s[i]+s[i+1]-'A'-'A'-'A'==3)
    {
    if ((s[i-1]-'A')*(s[i]-'A')*(s[i+1]-'A')==0)
      {
      cout<<"Yes"<<endl;
      return 0;
      }
    }
  }

cout<<"No"<<endl;

    return 0;
}
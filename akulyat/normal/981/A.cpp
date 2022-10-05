#include <iostream>

using namespace std;

string s;
bool p;
long i,n;

int main()
{
getline(cin, s);
long n=s.size();
p=true;
for (i=0; i<n; i++)
  if (s[i]!=s[n-1-i])
    p=false;
if (!p)
  {
  cout<<s.size();
  return 0;
  }

for (i=0; i<n-1; i++)
  if (s[i]!=s[i+1])
    p=false;
if (!p)
  {
  cout<<s.size()-1;
  return 0;
  }

cout<<0;


    return 0;
}
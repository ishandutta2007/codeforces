#include <iostream>

using namespace std;

string s;
long long i,r,u,n;

int main()
{
cin>>n;
getline(cin, s);
getline(cin, s);
for (i=0; i<s.size()-1; i++)
  {
  if (s[i]!=s[i+1])
    {r++; i++;}
  }
cout<<n-r;

    return 0;
}
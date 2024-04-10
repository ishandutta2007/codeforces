#include <iostream>

using namespace std;

long n,i;
string s;
long kol;
int main()
{
cin>>n;
getline(cin, s);
getline(cin, s);

for (i=2; i<n; i++)
  {
  if (s[i]=='x')
  if (s[i-1]=='x')
  if (s[i-2]=='x')
    kol++;
  }
cout<<kol;

    return 0;
}
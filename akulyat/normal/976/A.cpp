#include <iostream>

using namespace std;

long n,i,kol;
string s;

int main()
{
cin>>n;
cin>>s;
if (s=="0")
  {
  cout<<"0";
  return 0;
  }
for (i=0; i<n; i++)
  if (s[i]=='0')
    kol++;
cout<<'1';
for (i=0; i<kol; i++)
  cout<<'0';



    return 0;
}
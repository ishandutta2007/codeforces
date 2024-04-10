#include <iostream>

using namespace std;

string s;
long n,i,j;

int main()
{
cin>>n;
getline(cin, s);
getline(cin, s);

long ans=n;
for (i=1; i<n; i++)
  if (2*i<=n)
    {
    string p,t;
    for (j=0; j<i; j++)
      t+=s[j];
    for (j=i; j<2*i; j++)
      p+=s[j];
    if (p==t)
      ans=n-i+1;
    }
cout<<ans;

    return 0;
}
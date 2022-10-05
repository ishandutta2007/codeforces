#include <iostream>

using namespace std;

long m[100000];

int main()
{
long n,i;
string s;

cin>>n;
getline(cin, s);
getline(cin, s);
for (i=0; i<n-1; i++)
  {
  long k=26*(s[i]-'A')+(s[i+1]-'A');
  m[k]++;
  }
long max=0;
long ans=0;

for (i=0; i<26*26; i++)
  {
  if (m[i]>=max)
    {
    ans=i;
    max=m[i];
    }
  }
cout<<char(ans/26+'A')<<char(ans%26+'A');

    return 0;
}
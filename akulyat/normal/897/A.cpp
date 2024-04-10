#include <iostream>

using namespace std;

long long n,q,i,j;
string s;
int main()
{
cin>>n>>q;
cin>>s;
for (long long j=0; j<q; j++)
  {
  long long l,r;
  char c1,c2;
  cin>>l>>r>>c1>>c2;
  l--; r--;
  for (i=l; i<=r; i++)
    if (s[i]==c1)
      s[i]=c2;
  }
cout<<s;


    return 0;
}
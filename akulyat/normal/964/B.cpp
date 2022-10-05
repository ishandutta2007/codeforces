#include <iostream>

using namespace std;


long long n,a,b,c,t,i,j;
int main()
{
cin>>n>>a>>b>>c>>t;
long long otv=0;
for (i=0; i<n; i++)
  {
  long long ans=-10000000;
  long long v;
  cin>>v;
  for (j=v; j<=t; j++)
    ans=max(ans, a-(b-c)*(j-v));
  otv+=ans;
  }

cout<<otv;

    return 0;
}
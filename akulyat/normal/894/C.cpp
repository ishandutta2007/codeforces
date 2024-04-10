#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

long int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


int main()
{
long int n;
cin>>n;
long int i;
long int m[1000];
long int it;
cin>>it;
m[0]=it;
for (i=1; i<n; ++i)
{
cin>>m[i];
it=gcd(m[i], it);
}
//cout<<it<<endl;
if (it!=m[0])
  cout<<"-1\n";
else
{
cout<<2*n<<endl;
for (i=0; i<n; ++i)
{
  cout<<m[i]<<" "<<m[0]<<" ";
}
}
return 0;
}
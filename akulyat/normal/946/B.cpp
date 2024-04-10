#include <iostream>

using namespace std;

long long a,b;

void work()
{
if (a>=2*b)
  a%=2*b;
else
  if (b>=2*a)
    b%=2*a;
}

int main()
{
cin>>a>>b;
for (long long i=0; i<1000; i++)
  if (a!=0&&b!=0)
    work();

cout<<a<<' '<<b<<endl;


    return 0;
}
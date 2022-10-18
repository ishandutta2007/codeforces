#include <iostream>
#include <cmath>
#define w(x) while(x<=n)
main()
{
 int n,a,b,c,s=a=0;
 std::cin>>n;
 w((b=++a))
 w(b)
 c=sqrt(a*a+b*b),c*c==a*a+b*b++ && c<=n?s++:0;
 std::cout<<s;  
}
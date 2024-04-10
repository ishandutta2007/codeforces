#include <iostream>

using namespace std;

int main()
{

long long y, b;
cin>>y>>b;
long long Y, G, B;
cin>>Y>>G>>B;
long long lack = 0;
if (y<2*Y+G) lack+=(2*Y+G-y);
if (b<3*B+G) lack+=(3*B+G-b);
cout<<lack;


}
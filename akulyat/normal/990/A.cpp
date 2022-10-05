#include <iostream>

using namespace std;


long long n,m,a,b,l,r;


int main()
{
cin>>n>>m>>a>>b;

r=(n%m);
l=(m-r);
l*=a;
r*=b;

cout<<min(l, r)<<endl;




    return 0;
}
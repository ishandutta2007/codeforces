#include <bits/stdc++.h>
using namespace std;
long long x,y,z,a,b;
int main()
{
	cin>>a>>b>>x>>y>>z;
	cout<<max(0ll,x*2+y-a)+max(0ll,y+z*3-b);
    return 0;
}
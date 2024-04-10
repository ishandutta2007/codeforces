#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main()
{
	cin>>a>>b>>c>>d>>e;
	cout<<min(min(a,b),min(c/2,min(d/7,e/4)));
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long n,m,a,s;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a,cout<<(s+a)/m-s/m<<" ",s+=a;
    return 0;
}
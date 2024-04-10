#include<bits/stdc++.h>
using namespace std;
bool isp(int x)
{ 
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
int n,m; 
int main()
{
	cin>>n>>m;
	int pd=isp(n)&&isp(m);
	for(int i=n+1;i<m;i++)
		if(isp(i))
			pd=0;
	cout<<(pd?"YES":"NO");
	return 0;
}
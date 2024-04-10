#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n,m,k,v0,v1,a,l,u;
int main()
{
	int i,j;
	cin>>n>>v0>>v1>>a>>l;
	m=1;
	u=n;
	int vh=0;
	while(1)
	{
		n-=(v0-(min(vh,l)));
		vh=(u-n);
		v0=min(v1,a+v0);
		if(n<=0)
			break;
		++m;
	}
	cout<<m<<endl;
//	system("pause");
	return 0;
}
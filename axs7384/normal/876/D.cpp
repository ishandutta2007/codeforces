#include<bits/stdc++.h>
using namespace std;
int n,x,a[300005],r;
int main()
{
	scanf("%d",&n);
	cout<<"1 ";
	r=n;
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		a[x]=1;
		while (a[r])
			--r;
		cout<<i-(n-r)+1<<' ';
	}
	return 0;
}
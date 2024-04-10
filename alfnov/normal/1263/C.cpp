#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,tot=0;
		cin>>n;
		a[++tot]=0;
		for(int l=1;l<=n;)
		{
			int r=n/(n/l);
			a[++tot]=n/l;
			l=r+1;
		}
		sort(a+1,a+tot+1);
		cout<<tot<<endl;
		for(int i=1;i<tot;i++)printf("%d ",a[i]);
		printf("%d\n",a[tot]);
	}
	return 0;
}
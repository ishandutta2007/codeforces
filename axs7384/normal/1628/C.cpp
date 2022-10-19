#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int t,n;
int f[100];
int a[N][N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int x;
		int ans=0;
		if (n==2)
		{
			for (int i=1;i<=4;++i)
			{
				scanf("%d",&x);
				if (i<=2)
					ans^=x;
			}
			cout<<ans<<endl;
			continue;
		}
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				scanf("%d",&a[i][j]);
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
			{
				if (i%2==1&&j%2==1&&i+j<=n&&(i+j)%4==n%4)
					ans^=a[i][j];
				if (i%2==0&&j%2==0&&i+j>n+1&&(i+j)%4==n%4)
					ans^=a[i][j];
			}
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n/2;++j)
				swap(a[i][j],a[i][n+1-j]);
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
			{
				if (i%2==1&&j%2==1&&i+j<=n&&(i+j)%4==n%4)
					ans^=a[i][j];
				if (i%2==0&&j%2==0&&i+j>n+1&&(i+j)%4==n%4)
					ans^=a[i][j];
			}
		cout<<ans<<endl;
		// for (int i=1;i<=n;++i)
		// 	for (int j=1;j<=n;++j)
		// 	{
		// 		scanf("%d",&x);
		// 		if ((i&3)==2||(i&3)==3)
		// 			ans^=x;
		// 		/*for (int k=0;k<30;++k)
		// 			if (x&(1<<k))
		// 				++f[k];*/
		// 	}
		// /*int ans=0;
		// int p=4;
		// if (n!=2)
		// 	p=8;
		// for (int i=0;i<=5;++i)
		// 	cout<<f[i]<<' ';cout<<endl;
		// for (int i=0;i<30;++i)
		// 	if (f[i]%p)
		// 		ans|=(1<<i);*/
		// cout<<ans<<endl;
	}
	return 0;
}
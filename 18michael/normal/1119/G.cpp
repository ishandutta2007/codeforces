#include<bits/stdc++.h>
using namespace std;
int n,m,t=0,p=1;
int a[1000002],vec[1000002];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&a[i]),t+=a[i];
		if(i<m)vec[i]=t%n;
		else vec[i]=n;
	}
	printf("%d\n",t=(t+n-1)/n),sort(vec+1,vec+m+1);
	for(int i=m;i>1;--i)vec[i]-=vec[i-1];
	for(int i=1;i<=m;++i)printf("%d%c",vec[i],i==m? '\n':' ');
	for(int i=1;i<=t;++i)
		for(int j=1;j<=m;++j)
		{
			for(;p<m && !a[p];++p);
			printf("%d%c",p,j==m? '\n':' '),a[p]-=vec[j];
		}
	return 0;
}
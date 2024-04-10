#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,s,sum,a[300005],f[300005],m,p[300005];
int main()
{
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;++i)
		s+=n/i-1;
	puts(s>=k?"Yes":"No");
	if(s>=k)
	{
		s=0;
		for(i=2;i<=n;++i)
			for(j=i*2;j<=n;j+=i)
				p[j]=1;
		for(i=1;i<=n;++i)
		{
			if(i*i>n&&p[i]==0)
				continue;
			s=0;
			for(j=1;j*j<i;++j)
				if(i%j==0)
					s+=f[j]+f[i/j];
			if(j*j==i)
				s+=f[j];
			if(sum+s<=k)
			{
				sum+=s;
				f[i]=1;
				a[++m]=i;
			}
		}
		for(i=1;i<=n;++i)
		{
			if(i*i<=n||p[i]==1)
				continue;
			s=1;
			for(j=i;j<=n;j+=i)
				s+=f[j];
			if(sum+s<=k)
			{
				sum+=s;
				f[i]=1;
				a[++m]=i;
			}
		}
		printf("%d\n",m);
		for(i=1;i<=m;++i)
			printf("%d ",a[i]);
	}
}
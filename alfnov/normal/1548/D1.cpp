#include<bits/stdc++.h>
using namespace std;
int f[15][15];
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int g(int a,int b,int c,int d)
{
	return gcd(abs(a-c),abs(b-d));
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		f[x%4][y%4]++;
	}
	long long a1=0,a2=0,a3=0;
	for(int i=0;i<4;i+=2)for(int j=0;j<4;j+=2)
		for(int k=0;k<4;k+=2)for(int l=0;l<4;l+=2)
			for(int o=0;o<4;o+=2)for(int p=0;p<4;p+=2)
			{
				if((g(i,j,k,l)+g(k,l,o,p)+g(o,p,i,j))%4)continue;
				if(i==k&&j==l&&k==o&&l==p)
				{
					a1+=1ll*f[i][j]*(f[k][l]-1)*(f[o][p]-2)/6;
					continue;
				}
				if(i==k&&j==l)
				{
					a2+=1ll*f[o][p]*f[i][j]*(f[k][l]-1)/2;
					continue;
				}
				if(k==o&&l==p)
				{
					a2+=1ll*f[i][j]*f[k][l]*(f[o][p]-1)/2;
					continue;
				}
				if(o==i&&p==j)
				{
					a2+=1ll*f[k][l]*f[o][p]*(f[i][j]-1)/2;
					continue;
				}
				a3+=1ll*f[i][j]*f[k][l]*f[o][p];
			}
	long long ans=a1+a2/3+a3/6;
	cout<<ans<<endl;
	return 0;
}
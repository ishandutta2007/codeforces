#include<bits/stdc++.h>
using namespace std;
int a[305],b[305],c[305][305],f[305][305],e[305],d[305];
int main()
{
	int n;
	cin>>n;
	d[0]=1;
	for(int i=1;i<=n;i++)d[i]=1ll*i*d[i-1]%1000000007;
	for(int i=0;i<=n;i++)c[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%1000000007;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=40000;j>=1;j--)if(a[i]%(j*j)==0)a[i]/=j*j;
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int NN=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)e[lower_bound(b+1,b+NN+1,a[i])-b]++;
	int s=e[1],t=e[1]-1;
	f[1][e[1]-1]=d[e[1]];
	for(int i=2;i<=NN;i++)
	{
		for(int j=0;j<=t;j++)for(int k=1;k<=e[i];k++)for(int l=0;l<=min(j,k);l++)
			f[i][e[i]+j-k-l]=(f[i][e[i]+j-k-l]+1ll*f[i-1][j]*d[e[i]]%1000000007*c[e[i]-1][k-1]%1000000007*c[j][l]%1000000007*c[s+1-j][k-l])%1000000007;
		s+=e[i],t+=max(0,e[i]-1);
	}
	cout<<f[NN][0]<<endl;
	return 0;
}
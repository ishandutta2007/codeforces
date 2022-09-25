#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 85
double f[N][N],as[N][N];
int n,s2[N][4],v[N*2],ct,q[N*2],ct2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&s2[i][1],&s2[i][2]),v[++ct]=s2[i][1],v[++ct]=s2[i][2];
	sort(v+1,v+ct+1);v[0]=-1;
	for(int i=1;i<=ct;i++)if(v[i]!=v[i-1])q[++ct2]=v[i];
	for(int p=1;p<=n;p++)
	for(int i=2;i<=ct2;i++)
	{
		int l1=q[i-1],r=q[i],c1=0;
		if(l1>=s2[p][2]||r<=s2[p][1])continue;
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int j=1;j<=n;j++)
		if(j!=p)
		if(l1>=s2[j][2]){c1++;continue;}
		else if(r<=s2[j][1])continue;
		else
		for(int k=j;k>=0;k--)
		for(int s=j;s>=0;s--)
		if(f[k][s]>1e-8)
		f[k+1][s]+=f[k][s]*(l1-s2[j][1])/(s2[j][2]-s2[j][1]),
		f[k][s+1]+=f[k][s]*(r-l1)/(s2[j][2]-s2[j][1]),
		f[k][s]=f[k][s]*(s2[j][2]-r)/(s2[j][2]-s2[j][1]);
		for(int j=0;j<=n;j++)
		for(int k=0;k<=n;k++)if(f[j][k]>1e-8)
		for(int l=0;l<=k;l++)if(j+l+c1<=80)
		as[p][j+l+c1]+=f[j][k]/(k+1)*(r-l1);
	}
	for(int i=1;i<=n;i++,printf("\n"))
	for(int j=1;j<=n;j++)
	printf("%.10lf ",as[i][j-1]/(s2[i][2]-s2[i][1]));
}//
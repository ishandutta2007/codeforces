#include<cstdio>
#include<cstring>
const int N=2e5+5,M=55;
int n,m,a[N];
double inv[N],sum[N],pre[N],f[N][M];
void solve(int x,int L,int R,int l,int r)
{
	if(L>R)return;
	int pos=0,mid=(L+R)>>1;
	for(int i=l;i<=r&&i<mid;i++)
	{
		double tmp=f[i][x-1]+pre[mid]-pre[i]-sum[i]*(inv[mid]-inv[i]);
		if(tmp<f[mid][x])f[mid][x]=tmp,pos=i;
	}
	solve(x,L,mid-1,l,pos);solve(x,mid+1,R,pos,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),inv[i]=inv[i-1]+(double)1/a[i],sum[i]=sum[i-1]+a[i],pre[i]=pre[i-1]+(double)sum[i]/a[i];
	memset(f,127,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=m;i++)solve(i,1,n,0,n);
	printf("%.10lf\n",f[n][m]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=100005;
#define vi vector<int>
#define pb push_back
int n,tp,a[N],st[N],s1[N],s2[N],ans[N],h[160][520][520];bool f[160][520][520],g[160][520][520];
inline vi fac(int n){vi V;for(int i=2;i*i<=n;i++)if(n%i==0){V.pb(i);while(n%i==0)n/=i;}if(n>1)V.pb(n);return V;}
void prt(int i,int j,int k)
{
	if(!i)return;ans[st[i]]=(int)g[i][j][k]+1;
	if(!g[i][j][k])prt(i-1,h[i][j][k],k);else prt(i-1,j,h[i][j][k]);
}
void sol()
{
	memset(s1,0,sizeof(s1));memset(s2,0,sizeof(s2));
	int x=rand()%(n-1)+1,y=rand()%(n-1)+1;if(y==x)y=n;
	vi A=fac(a[x]),B=fac(a[y]);tp=0;int c1=0,c2=0;
	for(auto p:A)
	{
		for(int i=1,c=0;i<=n&&c<10;i++)if(i!=x&&i!=y&&a[i]%p){st[++tp]=i;s1[i]|=1<<c1;c++;}
		c1++;
	}
	for(auto p:B)
	{
		for(int i=1,c=0;i<=n&&c<10;i++)if(i!=x&&i!=y&&a[i]%p){st[++tp]=i;s2[i]|=1<<c2;c++;}
		c2++;
	}
	sort(st+1,st+tp+1);tp=unique(st+1,st+tp+1)-st-1;
	memset(f,0,sizeof(f));f[0][0][0]=1;
	for(int i=0;i<tp;i++)for(int j=0;j<(1<<c1);j++)for(int k=0;k<(1<<c2);k++)if(f[i][j][k])
	{
		int p=st[i+1];
		f[i+1][j|s1[p]][k]=1;g[i+1][j|s1[p]][k]=0;h[i+1][j|s1[p]][k]=j;
		f[i+1][j][k|s2[p]]=1;g[i+1][j][k|s2[p]]=1;h[i+1][j][k|s2[p]]=k;
	}
	if(f[tp][(1<<c1)-1][(1<<c2)-1])
	{
		puts("YES");for(int i=1;i<=n;i++)ans[i]=(i==y)+1;
		prt(tp,(1<<c1)-1,(1<<c2)-1);
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);exit(0);
	}
}
int main()
{
	scanf("%d",&n);srand(time(0));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int T=1;T<=5;T++)sol();puts("NO");
	return 0;
}
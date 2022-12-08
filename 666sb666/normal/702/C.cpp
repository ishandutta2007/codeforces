#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
int a[maxn],b[maxn],n,m;int read()
{
	char ch=getchar();int sum=0;int f=1;
	while ((ch<'0'||ch>'9')&&(ch!='-'))ch=getchar();
	if (ch=='-'){f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return f*sum;
}
int abs(int x){return (x>0)?x:-x;}
int max(int x,int y){return (x>y)?x:y;}
int min(int x,int y){return (x<y)?x:y;}
int main()
{
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++)a[i]=read();sort(a+1,a+n+1);
	for (int i=1;i<=m;i++)b[i]=read();sort(b+1,b+m+1);
//	for (int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
//	for (int i=1;i<=m;i++)printf("%d ",b[i]);putchar('\n');
	int ans=0;
	for (int i=1,now=1;i<=n;i++)
	{
		while (now<m&&b[now]<a[i])now++;
		if (now==1)ans=max(ans,abs(a[i]-b[now]));
		else ans=max(ans,min(a[i]-b[now-1],abs(a[i]-b[now])));
		//printf("%d %d\n",a[i],b[now],now,ans);
	}
	printf("%d\n",ans);
}
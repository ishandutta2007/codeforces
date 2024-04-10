#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=200005;
int n;
int a[N];
struct qq
{
	int x,id;// 
}s[N];
int f[N];
bool cmp (qq a,qq b){return a.x<b.x;}
int lb (int x){return x&(-x);}
void change (int x)
{
	while (x<=n)
	{
		f[x]++;
		x+=lb(x);	
	}
	return ;
}
int get (int x)
{
	//printf("YES:%d\n",x);
	int lalal=0;
	while (x>=1)
	{
		lalal=lalal+f[x];
		x-=lb(x);
	}
	return lalal;
}
int mymax (int x,int y){return x>y?x:y;}
int mymin (int x,int y){return x<y?x:y;}
int k;
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&a[u]);
		s[u].x=mymax(0,a[u]-u);
		s[u].id=u;
	}
	sort(s+1,s+1+n,cmp);
/*	for (int u=1;u<=n;u++)
		printf("%d %d\n",s[u].x,s[u].id);
	printf("\n");*/
	int ans=0;
	for (int u=1;u<=n;u++)
	{
		int t=s[u].x;//
		change(s[u].id);
		ans=mymax(ans,get(mymin(n,k-t-1)));
		/*printf("%d %d %d\n",s[u].x,s[u].id,k-t);
		printf("%d\n",get(mymin(n,k-t)));*/
	}
	printf("%d\n",ans);
	return 0;
}
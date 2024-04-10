#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
#include<set>
typedef long long ll;
typedef double db;
int n,k;
char str[111111];
void reverse(int l,int r)
{
	int mid=(l+r)>>1;
	register int i;
	for(i=l;i<=mid;i++)
	{
		int x=i,y=r+l-i;
		char t=str[x];
		str[x]=str[y],str[y]=t;
	}
}
char emm[]="()";
int find(int S,int opt)
{
	while(str[S]!=emm[opt])S++;
	return S;
}
int xx[111111],yy[111111],tot;
void record(int x,int y)
{
	xx[++tot]=x,yy[tot]=y;
}
void replay()
{
	printf("%d\n",tot);
	for(register int i=1;i<=tot;i++)
		printf("%d %d\n",xx[i],yy[i]);
}
void exec()
{
	tot=0;
	scanf("%d%d%s",&n,&k,str+1);
	register int i;
	for(i=1;i<=(k-1)*2;i++)
	{
		if(i&1)
		{
			int t=find(i,0);
			record(i,t);
			reverse(i,t);
		}
		else
		{
			int t=find(i,1);
			record(i,t);
			reverse(i,t);
		}
	}int rst=((n-k*2)>>1)+1;
	for(i=k*2-1;i<=k*2-2+rst;i++)
	{
		int t=find(i,0);
		record(i,t);
		reverse(i,t);
	}replay();
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)exec();
}
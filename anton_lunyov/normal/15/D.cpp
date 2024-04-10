#include <stdio.h>
#include <algorithm>
using namespace std;

#define fill(ar,val) memset(ar,val,sizeof ar)
#define max(a,b) ((a)>(b)?(a):(b))

typedef __int64 LL;

#define N 1111
int n,m;
LL a[N][N],s[N][N],b[N][N];
int qs,qe;
int q[N];

struct vert
{
	int x,y;
	LL h;
	vert(){}
	vert(int x_,int y_,LL h_){x=x_;y=y_;h=h_;}
	bool operator<(const vert &a) const
	{
		if(h!=a.h) return h<a.h;
		if(x!=a.x) return x<a.x;
		return y<a.y;
	}
};

vert ans[N*N];
int len;
vert st[N*N];
int mark[N][N];

int main()
{
	int n,m,w,h;
	while(scanf("%d%d%d%d",&n,&m,&w,&h)>0)
	{
		int i,j;
		for(i=1;i<=n;i++)
		{
			qs=qe=0;
			for(j=1;j<=m;j++)
			{
				scanf("%I64d",&a[i][j]);
				s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
				while(qe>qs && a[i][q[qe-1]] > a[i][j])
					qe--;
				q[qe++]=j;
				if(qs<qe && q[qs]<=j-h) qs++;
				if(j>=h) b[i][j-h+1]=a[i][q[qs]];
			}
		}
		for(j=1;j<=m-h+1;j++)
		{
			qs=qe=0;
			for(i=1;i<=n;i++)
			{
				if(qs<qe && q[qs]<=i-w) qs++;
				while(qe>qs && b[q[qe-1]][j] > b[i][j])
					qe--;
				q[qe++]=i;
				if(i>=w)
					a[i-w+1][j]=b[q[qs]][j];
			}
		};
		int num=0;
		for(i=1;i<=n-w+1;i++)
			for(j=1;j<=m-h+1;j++)
				st[num++]=vert(i,j,s[i+w-1][j+h-1]-s[i-1][j+h-1]-s[i+w-1][j-1]+s[i-1][j-1]-w*h*a[i][j]);
		sort(st,st+num);
		fill(mark,0);
		len=0;
		for(int k=0;k<num;k++)
		{
			int x=st[k].x;
			int y=st[k].y;
			if(mark[x][y]) continue;
			ans[len++]=st[k];
			for(i=max(x-w+1,1);i<=x+w-1 && i<=n-w+1;i++)
				for(j=max(y-h+1,1);j<=y+h-1 && j<=m-h+1;j++)
					mark[i][j]=1;
		}
		printf("%d\n",len);
		for(i=0;i<len;i++)
		{
			vert p=ans[i];
			printf("%d %d %I64d\n",p.x,p.y,p.h);
		}
	}
	return 0;
}
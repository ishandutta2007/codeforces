#include<cstdio>
using namespace std;
#define N 5050
int tr1[N][N],tr2[N*2][N],tr3[N*2][N],n,q,a,b,c,d,e;
void add1(int x,int y,int d){for(int i=x;i<=n;i+=i&-i)for(int j=y;j<=n;j+=j&-j)tr1[i][j]+=d;}
int query1(int x,int y){int as=0;for(int i=x;i;i-=i&-i)for(int j=y;j;j-=j&-j)as+=tr1[i][j];return as;}
void add2(int x,int y,int d){for(int i=x;i<=n*2;i+=i&-i)for(int j=y;j<=n;j+=j&-j)tr2[i][j]+=d;}
int query2(int x,int y){int as=0;for(int i=x;i;i-=i&-i)for(int j=y;j;j-=j&-j)as+=tr2[i][j];return as;}
void add3(int x,int y,int d){for(int i=x;i<=n*2;i+=i&-i)for(int j=y;j<=n;j+=j&-j)tr3[i][j]+=d;}
int query3(int x,int y){int as=0;for(int i=x;i;i-=i&-i)for(int j=y;j;j-=j&-j)as+=tr3[i][j];return as;}
void doit1(int l1,int r1,int l2,int r2){if(l1<1)l1=1;if(l2<1)l2=1;if(r2<1)return;if(r1<1)return;if(l1>r1||l2>r2)return;add1(l1,l2,1);add1(l1,r2+1,-1);add1(r1+1,l2,-1);add1(r1+1,r2+1,1);}
void doit2(int l1,int r1,int l2,int r2){if(l1<1)l1=1;if(l2<1)l2=1;if(r2<1)return;if(r1<1)return;if(l1>r1||l2>r2)return;add2(l1,l2,1);add2(l1,r2+1,-1);add2(r1+1,l2,-1);add2(r1+1,r2+1,1);}
void doit3(int l1,int r1,int l2,int r2){if(l1<1)l1=1;if(l2<1)l2=1;if(r2<1)return;if(r1<1)return;if(l1>r1||l2>r2)return;add3(l1,l2,1);add3(l1,r2+1,-1);add3(r1+1,l2,-1);add3(r1+1,r2+1,1);}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&a);
		if(a==1)
		{
			scanf("%d%d%d%d",&b,&c,&d,&e);
			if(b==1)
			{
				doit1(c,c+e,1,d-1);
				doit2(1,c+d+e,c,c+e);
			}
			if(b==2)
			{
				doit1(c,c+e,d+1,n);
				doit3(1,c-d+n+e,c,c+e);
			}
			if(b==3)
			{
				doit1(c-e,c,1,d-1);
				doit3(c-d+n-e,n*2,c-e,c);
			}
			if(b==4)
			{
				doit1(c-e,c,d+1,n);
				doit2(c+d-e,n*2,c-e,c);
			}
		}
		else
		{
			scanf("%d%d",&b,&c);
			int as=query2(b+c,b)+query3(b-c+n,b)-query1(b,c);
			printf("%d\n",as);
		}
	}
}
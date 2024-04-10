#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200005;
const int inf=1000000000;

int n,q;
char str[N];

struct Matrix
{
	int a[5][5];
	
	void unit(int c)
	{
		for (int i=0;i<=4;i++)
			for (int j=0;j<=4;j++)
				a[i][j]=(i==j)?0:inf;
		if (c==-1) a[0][0]=a[1][1]=a[2][2]=a[3][3]=a[4][4]=inf;
		else if (c==2) a[0][0]=1,a[0][1]=0;
		else if (c==0) a[1][1]=1,a[1][2]=0;
		else if (c==1) a[2][2]=1,a[2][3]=0;
		else if (c==7) a[3][3]=1,a[3][4]=0;
		else if (c==6) a[3][3]=1,a[4][4]=1;
	}
}t[N*4];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

Matrix merge(Matrix a,Matrix b)
{
	Matrix c;c.unit(-1);
	for (int i=0;i<=4;i++)
		for (int k=0;k<=4;k++)
			for (int j=0;j<=4;j++)
				c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
	return c;
}

void build(int d,int l,int r)
{
	if (l==r) {t[d].unit(str[l]-'0');return;}
	int mid=(l+r)/2;
	build(d*2,l,mid);build(d*2+1,mid+1,r);
	t[d]=merge(t[d*2],t[d*2+1]);
}

Matrix query(int d,int l,int r,int x,int y)
{
	if (l==x&&r==y) return t[d];
	int mid=(l+r)/2;
	if (y<=mid) return query(d*2,l,mid,x,y);
	else if (x>mid) return query(d*2+1,mid+1,r,x,y);
	else return merge(query(d*2,l,mid,x,mid),query(d*2+1,mid+1,r,mid+1,y));
}

int main()
{
	n=read();q=read();
	scanf("%s",str+1);
	build(1,1,n);
	while (q--)
	{
		int l=read(),r=read();
		Matrix ans=query(1,1,n,l,r);
		printf("%d\n",ans.a[0][4]<inf?ans.a[0][4]:-1);
	}
	return 0;
}
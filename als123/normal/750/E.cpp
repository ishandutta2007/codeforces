#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAX=1<<28;
const int N=200005;
char ss[N];
struct matrix
{
	int s[5][5];
	matrix operator + (const matrix x) const
	{
		matrix a;
		for (int u=0;u<5;u++)
			for (int i=0;i<5;i++)
			{
				a.s[u][i]=MAX;
				for (int j=0;j<5;j++)
				{
				//	printf("u:%d i:%d j:%d s[u][j]:%d s[j][i]:%d\n",u,i,j,s[u][j]);
					a.s[u][i]=min(a.s[u][i],s[u][j]+x.s[j][i]);
				}
			}
		return a;
	}
};
struct qq
{
	int l,r;
	int s1,s2;
	matrix c;
}tr[N<<1];int num;
void bt (int l,int r)
{
	int a=++num;
	tr[a].l=l;tr[a].r=r;
	if (l==r)
	{
		for (int u=0;u<5;u++)
			for (int i=0;i<5;i++)
				tr[a].c.s[u][i]=(u==i)?0:MAX;
		if (ss[l]=='2')	{tr[a].c.s[0][0]=1;tr[a].c.s[0][1]=0;}
		if (ss[l]=='0')	{tr[a].c.s[1][1]=1;tr[a].c.s[1][2]=0;}
		if (ss[l]=='1')	{tr[a].c.s[2][2]=1;tr[a].c.s[2][3]=0;}
		if (ss[l]=='7')	{tr[a].c.s[3][3]=1;tr[a].c.s[3][4]=0;}
		if (ss[l]=='6')	{tr[a].c.s[3][3]=1;tr[a].c.s[4][4]=1;}
	/*	for (int u=0;u<4;u++)
	{
		for (int i=0;i<4;i++)
			printf("%d ",tr[a].c.s[u][i]);
		printf("\n");
	}*/
		return ;
	}
	int mid=(l+r)>>1;
	tr[a].s1=num+1;bt(l,mid);
	tr[a].s2=num+1;bt(mid+1,r);
	tr[a].c=tr[tr[a].s1].c+tr[tr[a].s2].c;
/*	printf("%d %d\n",l,r);
	for (int u=0;u<4;u++)
	{
		for (int i=0;i<4;i++)
			printf("%d ",tr[a].c.s[u][i]);
		printf("\n");
	}
	system("pause");*/
}
matrix find (int now,int l,int r)
{
/*	printf("%d %d %d %d %d\n",now,tr[now].l,tr[now].r,l,r);
	system("pause");*/
	if (tr[now].l==l&&tr[now].r==r)	return tr[now].c;
	int s1=tr[now].s1,s2=tr[now].s2;
	int mid=(tr[now].l+tr[now].r)>>1;
	if (r<=mid) return find(s1,l,r);
	else if (l>mid) return find(s2,l,r);
	else return find(s1,l,mid)+find(s2,mid+1,r);
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("%s",ss+1);
	bt(1,n);
	for (int u=1;u<=q;u++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		matrix ans=find(1,l,r);
		if (ans.s[0][4]==MAX) printf("-1\n");
		else printf("%d\n",ans.s[0][4]);
	}
	return 0;
}
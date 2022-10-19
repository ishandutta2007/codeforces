#include<bits/stdc++.h>
using namespace std;
int la,lb,lla,llb,n,l[10],v[10],q[10];
const int N=35;
char a[10][N],b[N][N],c[N][N];
inline void fz()
{
	memset(c,'.',sizeof(c));
	la=lla;
	lb=llb;
	for (int i=1;i<=la;++i)
		for (int j=1;j<=lb;++j)
			c[i][j]=b[i][j];
}
inline void pd()
{
	if (la==0)
	{
		fz();
		return;
	}
	int k=0;
	for (int i=1;i<=min(lb,llb);++i)
	{
		for (int j=1;j<=min(la,lla);++j)
		{
			if (b[i][j]>c[i][j])
				{k=1;break;}
			if (b[i][j]<c[i][j])
				{k=2;break;}
		}
		if (k!=0)
			break;
		if (la<lla)
			k=2;
		if (la>lla)
			k=1;
		if (k!=0)
			break;
	}
	if (k==2)
		fz();
}
inline void work()
{
	if (l[v[1]]!=l[v[2]]+l[v[3]]-1)
		return;
	if (l[v[4]]!=l[v[5]]+l[v[6]]-1)
		return;
	if (a[v[2]][1]!=a[v[5]][1])
		return;
	if (a[v[3]][l[v[3]]]!=a[v[6]][l[v[6]]])
		return;
	if (a[v[2]][l[v[2]]]!=a[v[4]][1])
		return;
	if (a[v[5]][l[v[5]]]!=a[v[1]][1])
		return;
	if (a[v[1]][l[v[1]]]!=a[v[6]][1])
		return;
	if (a[v[4]][l[v[4]]]!=a[v[3]][1])
		return;
	if (a[v[1]][l[v[2]]]!=a[v[4]][l[v[5]]])
		return;
	memset(b,'.',sizeof(b));
	llb=l[v[1]];
	lla=l[v[4]];
	for (int i=1;i<=l[v[1]];++i)
		b[l[v[5]]][i]=a[v[1]][i];
	for (int i=1;i<=l[v[2]];++i)
		b[1][i]=a[v[2]][i];
	for (int i=1;i<=l[v[3]];++i)
		b[l[v[4]]][i+l[v[2]]-1]=a[v[3]][i];
	for (int i=1;i<=l[v[4]];++i)
		b[i][l[v[2]]]=a[v[4]][i];
	for (int i=1;i<=l[v[5]];++i)
		b[i][1]=a[v[5]][i];
	for (int i=1;i<=l[v[6]];++i)
		b[i+l[v[5]]-1][l[v[1]]]=a[v[6]][i];
	pd();
}
void dfs(int x)
{
	if (x==7)
	{
		work();
		return;
	}
	for (int i=1;i<=6;++i)
		if (!q[i])
		{
			q[i]=1;
			v[x]=i;
			dfs(x+1);
			q[i]=0;
		}
}
int main()
{
	//freopen("a.in","r",stdin);
	for (int i=1;i<=6;++i)
		scanf("%s",a[i]+1);
	for (int i=1;i<=6;++i)
		l[i]=strlen(a[i]+1);
	dfs(1);
	if (la!=0)
	{
		for (int i=1;i<=la;++i)
		{
			for (int j=1;j<=lb;++j)
				putchar(c[i][j]);
			putchar('\n');
		}
	}
	else
		puts("Impossible");
	return 0;
}
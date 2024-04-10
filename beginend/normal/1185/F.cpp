#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=100005;
const int M=605;
const int inf=2e9+1;

int n,m,bin[15],a[N],pri[M],id[M],f[M],b[N];

int main()
{
	scanf("%d%d",&n,&m);
	bin[0]=1;
	for (int i=1;i<=9;i++) bin[i]=bin[i-1]*2;
	for (int i=1;i<=n;i++)
	{
		int s,x;
		scanf("%d",&s);
		while (s--) scanf("%d",&x),a[i]+=bin[x-1];
	}
	for (int i=0;i<bin[9];i++) pri[i]=inf;
	for (int i=1;i<=m;i++)
	{
		int c,s,t=0,x;scanf("%d%d",&c,&s);
		b[i]=c;
		while (s--) scanf("%d",&x),t+=bin[x-1];
		if (c<pri[t]) pri[t]=c,id[t]=i;
	}
	for (int i=1;i<=n;i++) f[a[i]]++;
	for (int i=0;i<9;i++)
		for (int j=0;j<bin[9];j++)
			if (j&bin[i]) f[j]+=f[j-bin[i]];
	int mx=0,mn_pri=inf,ansx,ansy;
	for (int i=0;i<bin[9]-1;i++)
		for (int j=i+1;j<bin[9];j++)
			if (pri[i]<inf&&pri[j]<inf&&(f[i|j]>mx||f[i|j]==mx&&pri[i]+pri[j]<mn_pri))
			{
				mx=f[i|j];
				mn_pri=pri[i]+pri[j];
				ansx=id[i];ansy=id[j];
			}
	if (mn_pri<inf)
	{
		printf("%d %d\n",ansx,ansy);
		return 0;
	}
	int mn1=inf,mn2=inf;
	for (int i=1;i<=m;i++)
		if (b[i]<mn1) mn2=mn1,ansy=ansx,mn1=b[i],ansx=i;
		else if (b[i]<mn2) mn2=b[i],ansy=i;
	printf("%d %d\n",ansx,ansy);
	return 0;
}
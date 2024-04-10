#include<bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x=0,w=1;char c=getchar();while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();return x*w;
}
int n,x,a[60][60],p[110],v[60];
vector<int> E[60];
inline bool cmp(int x,int y){return v[x]>v[y];}
int main()
{
	int T=rd();
	while(T--)
	{
		n=rd();
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=rd();
		puts("B");fflush(stdout);
		if((getchar()=='D')^((x=rd())>n))for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=-a[i][j];
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++)
		{
			E[i].resize(n);
			for(int j=1;j<=n;j++)v[j]=a[i][j],E[i][j-1]=j;
			sort(E[i].begin(),E[i].end(),cmp);
		}
		int m=n;
		while(m)
		{
			for(int i=1;i<=n;i++)if(!p[i])while(1)
			{
				int j=E[i].back();E[i].pop_back();
				if(!p[j+n]){p[i]=j+n;p[j+n]=i;--m;break;}
				if(a[i][j]>a[p[j+n]][j]){p[p[j+n]]=0;p[i]=j+n;p[j+n]=i;break;}
			}
		}
		while(1)
		{
			printf("%d\n",p[x]);fflush(stdout);
			x=rd();if(x<0)break;
		}
	}
	return 0;
}
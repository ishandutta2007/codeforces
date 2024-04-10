#include<cstdio>
#include<bitset>
using namespace std;
#define N 1056
bitset<N> s[N],v[N],t,p;
int n,a,b,is[N],fg[N][N],f1,f2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		while(a--)scanf("%d",&b),s[i].set(b,1);
		v[i].set(i,1);
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	{
		t=s[i]&s[j];
		if(t.count()==2)
		{
			int s1=-1,s2=0;
			for(int k=1;k<=n;k++)
			if(t[k])
			{
				if(s1==-1)s1=k;
				else s2=k;
			}
			if(fg[s1][s2])continue;
			printf("%d %d\n",s1,s2);f1=s1,f2=s2;
			v[s1].set(s2,1);
			v[s2].set(s1,1);
			is[s1]=is[s2]=fg[s1][s2]=fg[s2][s1]=1;
			p.set(s1,1);p.set(s2,1);
		}
	}
	if(!p.count())
	{
		for(int i=2;i<=n;i++)printf("1 %d\n",i);
		return 0;
	}
	if(p.count()==2)
	{
		int m1=0,m2=0,v1,fg=-1;
		for(int i=1;i<=n;i++)
		{
			int vl=s[i].count();
			if(vl>m1)m1=vl,v1=i;
			else if(vl>m2)m2=vl;
		}
		for(int i=1;i<=n;i++)if(s[i].count()!=n){
		int as=0;
		for(int j=1;j<=n;j++)if(s[i][j]&&j!=f1&&j!=f2&&!is[j])as=j;
		if(fg==-1)fg=as;
		if(s[i][fg])printf("%d %d\n",as,f1);
		else printf("%d %d\n",as,f2);is[as]=1;}
		return 0;
	}
	for(int i=1;i<=n;i++)
	if(!is[i])
	{
		int as=0,mn=1e9;
		for(int j=1;j<=n;j++)
		if(s[j][i]&&(s[j]&p).count()<mn)
		mn=(s[j]&p).count(),as=j;
		for(int j=1;j<=n;j++)
		if(v[j]==(s[as]&p))
		{printf("%d %d\n",i,j);break;}
	}
}//WA*15
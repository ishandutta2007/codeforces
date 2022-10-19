#include<cstdio>
#include<cmath>
#include<utility>
using namespace std;
int n,m,q,sq,t;
char c;
int st[322],ed[322],bl[100002];
char s[100002][12];
typedef pair<int,int> P;P p;
P to[100002][12];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline void getto(int x)
{
	for(int i=st[x];i<=ed[x];++i)
	{
		for(int j=1;j<=m;++j)to[i][j]=P(-1,-1);
		for(int j=0;j<=m+1;++j)
			if(!j || j==m+1 || s[i][j]=='^')
			{
				if(s[i][j]=='^')to[i][j]=(i==st[x]? P(i-1,j):to[i-1][j]);
				for(int k=j-1;k>0 && s[i][k]=='>';--k)to[i][k]=to[i][j];
				for(int k=j+1;k<=m && s[i][k]=='<';++k)to[i][k]=to[i][j];
			}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q),sq=sqrt(n),t=(n-1)/sq+1;
	for(int i=1;i<=m;++i)to[0][i]=P(0,i);
	for(int i=1;i<=n;++i)to[i][0]=P(i,0),to[i][m+1]=P(i,m+1);
	for(int i=1;i<=n;++i)scanf("%s",s[i]+1),bl[i]=(i-1)/sq+1;
	for(int i=1;i<=t;++i)st[i]=(i-1)*sq+1,ed[i]=min(i*sq,n),getto(i);
	while(q--)
	{
		do c=getchar();while(c!='A' && c!='C');
		scanf("%d%d",&p.first,&p.second);
		if(c=='A')
		{
			while(p.first>0 && p.second>0 && p.second<=m)p=to[p.first][p.second];
			printf("%d %d\n",p.first,p.second);
		}
		else
		{
			do c=getchar();while(c!='<' && c!='>' && c!='^');
			s[p.first][p.second]=c,getto(bl[p.first]);
		}
	}
	return 0;
}
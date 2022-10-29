#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2000005;
int n,m,t,i,j,k,bg,ed,qx[N],qy[N],f[10][5]={{-1,0},{1,0},{0,-1},{0,1}},d[1005][1005];
long long w;
bool v[1005][1005];
char s[1005][1005];
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(s[i][j]==s[i-1][j]||s[i][j]==s[i+1][j]||s[i][j]==s[i][j-1]||s[i][j]==s[i][j+1])
			{
				++ed;
				qx[ed]=i,qy[ed]=j;
				v[i][j]=true;
			}
	bg=1;
	while(bg<=ed)
	{
		for(i=0;i<4;++i)
		{
			j=qx[bg]+f[i][0],k=qy[bg]+f[i][1];
			if(j>=1&&j<=n&&k>=1&&k<=m&&!v[j][k])
			{
				++ed;
				qx[ed]=j,qy[ed]=k;
				v[j][k]=true;
				d[j][k]=d[qx[bg]][qy[bg]]+1;
			}
		}
		++bg;
	}
	while(t--)
	{
		scanf("%d%d%lld",&i,&j,&w);
		if(!v[i][j]||w<=d[i][j]||(w-d[i][j])%2==0)
			printf("%c\n",s[i][j]);
		else
			printf("%c\n",s[i][j]=='0'?'1':'0');
	}
	return 0;
}
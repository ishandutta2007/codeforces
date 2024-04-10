#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int md=1000000007;
int d,cnt,ch[50005][10],fail[50005],f[55][50005][2],i,j,k,ans,q[50005],bg,ed;
char s[1005],s1[55],s2[55];
bool v[50005],vis[55][50005][2];
int dfs(int x,int y,bool t)
{
	if(x>d)
		return v[y]?1:0;
	if(vis[x][y][t])
		return f[x][y][t];
	int up=(t?s[x]-'0':9),rtn=0;
	for(int z=0;z<=up;++z)
		rtn=(rtn+dfs(x+1,!v[y]?ch[y][z]:y,t&&z==up))%md;
	f[x][y][t]=rtn;
	vis[x][y][t]=true;
	return rtn;
}
int main()
{
	scanf("%s",s+1);
	scanf("%s%s",s1+1,s2+1);
	d=strlen(s1+1);
	for(i=1;s[i+d/2-1];++i)
	{
		for(j=i,k=0;j<=i+d/2-1;++j)
		{
			if(!ch[k][s[j]-'0'])
				ch[k][s[j]-'0']=++cnt;
			k=ch[k][s[j]-'0'];
		}
		v[k]=true;
	}
	for(i=0;i<10;++i)
		if(ch[0][i])
			q[++ed]=ch[0][i];
	bg=1;
	while(bg<=ed)
	{
		for(i=0;i<10;++i)
			if(ch[q[bg]][i])
			{
				q[++ed]=ch[q[bg]][i];
				fail[q[ed]]=ch[fail[q[bg]]][i];
			}
			else
				ch[q[bg]][i]=ch[fail[q[bg]]][i];
		++bg;
	}
	for(i=1;i<=d;++i)
		s[i]=s2[i];
	ans=dfs(1,0,true);
	s1[d]--;
	for(i=d;i>=1;--i)
		if(s1[i]<'0')
		{
			s1[i]+=10;
			s1[i-1]--;
		}
		else
			break;
	for(i=1;i<=d;++i)
		s[i]=s1[i];
	for(i=0;i<=d+1;++i)
		for(j=0;j<=cnt;++j)
			vis[i][j][0]=vis[i][j][1]=false;
	ans=(ans-dfs(1,0,true)+md)%md;
	printf("%d",ans);
	return 0;
}
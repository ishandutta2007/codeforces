#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,i,j,k,ch[105][26],lst[105][26];
ll K,f[105],g[105][105],w,ans;
char s[105];
int main()
{
	scanf("%d%lld",&n,&K);
	scanf("%s",s+1);
	for(i=1;i<=n;++i)
	{
		for(j=0;j<26;++j)
		{
			if(s[i-1]!=j+'a')
				lst[i+1][j]=(lst[i][j]==0?1:lst[i][j]);
			else
				lst[i+1][j]=i;
		}
		for(j=0;j<26;++j)
			for(k=lst[i+1][j];k&&!ch[k][s[i]-'a'];k=lst[k][j])
			{
				ch[k][s[i]-'a']=i+1;
				//printf("%d %d %c\n",k,i+1,s[i]);
			}
	}
	for(i=n+1;i>=1;--i)
	{
		f[i]=1;
		for(j=0;j<26;++j)
			if(ch[i][j])
			{
				if(f[i]==-1||f[ch[i][j]]==-1)
					f[i]=-1;
				else
				{
					f[i]+=f[ch[i][j]];
					if(f[i]>K)
						f[i]=-1;
				}
			}
	}
	if(f[1]!=-1&&f[1]<K)
	{
		printf("-1");
		return 0;
	}
	for(i=n+1;i>=1;--i)
	{
		g[i][1]=1;
		for(j=0;j<26;++j)
			if(ch[i][j])
			{
				for(k=1;k<=n;++k)
					{
						if(g[i][k+1]==-1||g[ch[i][j]][k]==-1)
							g[i][k+1]=-1;
						else
						{
							g[i][k+1]+=g[ch[i][j]][k];
							if(g[i][k+1]>K)
								g[i][k+1]=-1;
						}
					}
			}
	}
	for(i=n+1;i>=1;--i)
	{
		if(g[1][i]==-1||g[1][i]>=K)
			w=K;
		else
			w=g[1][i];
		ans+=w*(n-i+1);
		K-=w;
		if(K==0)
			break;
	}
	//for(i=1;i<=n+1;++i)
		//printf("%d %lld\n",i-1,g[1][i]);
	printf("%lld",ans);
	return 0;
}
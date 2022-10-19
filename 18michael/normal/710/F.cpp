#include<bits/stdc++.h>
#define Mx 18
#define LL long long
using namespace std;
int m,n=0,now;
LL ans;
int ed[300002],O[300002];
char s[300002];
vector<int> vec[300002];
struct ACAM
{
	int tot;
	int fail[300002],cnt[300002],dep[300002];
	int to[300002][26];
	inline void clear()
	{
		for(int i=0;i<=tot;++i)fail[i]=cnt[i]=0,memset(to[i],0,sizeof(to[i]));
		tot=0;
	}
}a[19];
int main()
{
	scanf("%d",&m);
	for(int o;m--;)
	{
		scanf("%d%s",&o,s+ed[n]),ed[n+1]=ed[n]+strlen(s+ed[n]);
		if(o==3)
		{
			ans=0;
			for(int i=0;i<=Mx;++i)
				if(a[i].tot)
				{
					now=0;
					for(int j=ed[n];j<ed[n+1];++j)
					{
						while(now && !a[i].to[now][s[j]-'a'])now=a[i].fail[now];
						ans+=a[i].cnt[now=a[i].to[now][s[j]-'a']];
					}
				}
			printf("%lld\n",ans),fflush(stdout);
		}
		else
		{
			O[++n]=(o==1? 1:-1);
			for(int i=0;i<=Mx;++i)
			{
				if(a[i].tot)
				{
					a[i].clear();
					continue;
				}
				for(int j=0;j<=ed[n]-ed[n-(1<<i)];++j)vec[j].clear();
				for(int j=n-(1<<i)+1;j<=n;++j)
				{
					now=0;
					for(int k=ed[j-1];k<ed[j];++k)
					{
						if(!a[i].to[now][s[k]-'a'])a[i].to[now][s[k]-'a']=(++a[i].tot);
						vec[k-ed[j-1]].push_back(now),now=a[i].to[now][s[k]-'a'];
					}
					a[i].cnt[now]+=O[j];
				}
				for(int j=0;j<=ed[n]-ed[n-(1<<i)];++j)
					for(int k=0;k<vec[j].size();++k)
						for(int l=0;l<26;++l)
							if(a[i].to[vec[j][k]][l])
							{
								now=a[i].fail[vec[j][k]];
								while(now && !a[i].to[now][l])now=a[i].fail[now];
								a[i].dep[a[i].to[vec[j][k]][l]]=a[i].dep[a[i].fail[a[i].to[vec[j][k]][l]]=(now==vec[j][k]? 0:a[i].to[now][l])]+1;
							}
				for(int j=0;j<=ed[n]-ed[n-(1<<i)];++j)vec[j].clear();
				for(int j=0;j<=a[i].tot;++j)vec[a[i].dep[j]].push_back(j);
				for(int j=0;j<=ed[n]-ed[n-(1<<i)];++j)
					for(int k=0;k<vec[j].size();++k)
						a[i].cnt[vec[j][k]]+=a[i].cnt[a[i].fail[vec[j][k]]];
				break;
			}
		}
	}
	return 0;
}
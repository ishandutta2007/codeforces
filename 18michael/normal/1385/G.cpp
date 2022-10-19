#include<cstdio>
#include<vector>
using namespace std;
int n,r,Test_num;bool ok;
int rt[400002],siz[400002];
bool vis[400002];
typedef pair<int,int> P;
vector<P> vec[200002];
vector<int> ans;
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d",&n),ok=1;
		for(int i=1;i<=n;++i)vec[i].clear(),rt[i]=i,rt[i+n]=i+n,siz[i]=1,siz[i+n]=0,vis[i]=0;
		for(int i=1,x;i<=n;++i)scanf("%d",&x),vec[x].push_back(P(1,i));
		for(int i=1,x;i<=n;++i)scanf("%d",&x),vec[x].push_back(P(2,i));
		for(int i=1;i<=n;++i)if(vec[i].size()!=2){ok=0;break;}
		if(!ok){puts("-1");continue;}
		for(int i=1,a,b,c,d;i<=n;++i)
		{
			a=vec[i][0].first,b=vec[i][0].second,c=vec[i][1].first,d=vec[i][1].second;
			if(b==d)continue;getroot(b),getroot(d),getroot(b+n),getroot(d+n);
			if(a==c)
			{
				if(rt[b]==rt[d]){ok=0;break;}
				if(rt[b]!=rt[d+n])siz[rt[d+n]]+=siz[rt[b]],siz[rt[d]]+=siz[rt[b+n]],rt[rt[b]]=rt[d+n],rt[rt[b+n]]=rt[d];
			}
			else
			{
				if(rt[b]==rt[d+n]){ok=0;break;}
				if(rt[b]!=rt[d])siz[rt[d]]+=siz[rt[b]],siz[rt[d+n]]+=siz[rt[b+n]],rt[rt[b]]=rt[d],rt[rt[b+n]]=rt[d+n];
			}
		}
		if(!ok){puts("-1");continue;}
		for(int i=1;i<=n;++i)getroot(i),getroot(i+n);
		ans.clear(),r=0;
		for(int i=1;i<=n;++i)
			if(!vis[i])
			{
				getroot(i),getroot(i+n);
				if(rt[i]==i)
				{
					if(!r)
					{
						if(siz[rt[i]]>siz[rt[i+n]])r=rt[i+n];
						else r=rt[i];
					}
					else
					{
						if(siz[rt[i]]>siz[rt[i+n]])siz[r]+=siz[rt[i+n]],rt[rt[i+n]]=r;
						else siz[r]+=siz[rt[i]],rt[rt[i]]=r;
					}
				}
			}
		for(int i=1;i<=n;++i)
		{
			getroot(i);
			if(rt[i]==r)ans.push_back(i);
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);puts("");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int ss[26][200005],vist[26][200005],fail[200005],fa[200005],q[200005],tot=1;
char cc[200005];
int dep[200005],L[200005],R[200005],K[200005],ddd[200005];
vector<int>g[200005];
int HyDroUseLess[200005],bg[200005],en[200005],tt=0;
long long ans[200005],HE[200005];
void dfs_1(int x)
{
	for(int i=0;i<26;i++)if(vist[i][x])
	{
		int cu=ss[i][x];
		dep[cu]=dep[x]+1;
		dfs_1(cu);
	}
}
void dfs_2(int CHKSB)
{
	bg[CHKSB]=en[CHKSB]=++tt;
	for(int i=0;i<g[CHKSB].size();i++)
	{
		int cu=g[CHKSB][i];
		dfs_2(cu);
		en[CHKSB]=en[cu]; 
	}
}
vector<int>QWQ[100005];
vector<pair<int,int> >WMH[100005];
void add(int x,int s)
{
	while(x<=tot)
	{
		HyDroUseLess[x]+=s;
		x+=x&-x; 
	}
}
int query(int x)
{
	int ans=0;
	while(x)
	{
		ans+=HyDroUseLess[x];
		x-=x&-x;
	}
	return ans;
}
int main()
{
	int n,m,rt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",cc+1);
		int len=strlen(cc+1),r=rt;
		for(int j=1;j<=len;j++)
		{
			if(!ss[cc[j]-'a'][r])ss[cc[j]-'a'][r]=++tot;
			fa[ss[cc[j]-'a'][r]]=r;
			r=ss[cc[j]-'a'][r];
		}
		ddd[i]=r;
		for(int j=1;j<=len;j++)cc[j]=0;
	}
	for(int i=0;i<26;i++)ss[i][0]=rt;
	int head=0,tail=-1;
	q[++tail]=rt;
	while(head<=tail)
	{
		int x=q[head++];
		for(int i=0;i<26;i++)
		{
			if(!ss[i][x])ss[i][x]=ss[i][fail[x]];
			else
			{
				vist[i][x]=1;
				fail[ss[i][x]]=ss[i][fail[x]];
				g[fail[ss[i][x]]].push_back(ss[i][x]);
				q[++tail]=ss[i][x];
			}
		}
	}
	dfs_1(rt);
	int S=min(tot+0.0,sqrt(1ll*m*log2(tot)));
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&L[i],&R[i],&K[i]);
		if(dep[ddd[K[i]]]>=S)QWQ[K[i]].push_back(i);
		else
		{
			WMH[R[i]].push_back(make_pair(K[i],i));
			if(L[i]-1)WMH[L[i]-1].push_back(make_pair(K[i],-i));
		}
	}
	dfs_2(rt);
	for(int i=1;i<=n;i++)
	{
		int x=ddd[i];
		if(dep[x]>=S)
		{
			int xx=x;
			while(xx)
			{
				HyDroUseLess[bg[xx]]=1;
				xx=fa[xx];
			}
			for(int j=1;j<=tot;j++)HyDroUseLess[j]+=HyDroUseLess[j-1];
			for(int j=1;j<=n;j++)
			{
				HE[j]=HE[j-1]+HyDroUseLess[en[ddd[j]]]-HyDroUseLess[bg[ddd[j]]-1];
			}
			for(int j=0;j<QWQ[i].size();j++)
			{
				int wz=QWQ[i][j];
				ans[wz]=HE[R[wz]]-HE[L[wz]-1];
			}
			memset(HyDroUseLess,0,sizeof(HyDroUseLess));
		}
	}
	for(int i=1;i<=n;i++)
	{
		add(bg[ddd[i]],1);
		add(en[ddd[i]]+1,-1);
		for(int j=0;j<WMH[i].size();j++)
		{
			int cu=WMH[i][j].first,c2=WMH[i][j].second;
			int uc=ddd[cu],aa=0;
			while(uc)
			{
				aa+=query(bg[uc]);
				uc=fa[uc];
			}
			ans[abs(c2)]+=(c2/abs(c2))*aa;
		}
	}
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m,t,mp1_t,tmp_t,Test_num,mn,Mx,ans;
int a[1000002],mx[1000002],T[1000002],T1[1000002];
typedef pair<int,int> P;
P p;
map<int,P> mp;
map<int,P>::iterator it;
map<int,int> mp1;
vector<int> vec[1000002];
struct aaa
{
	P a,b;
};
struct bbb
{
	P p;
	int o;
	inline bool operator < (const bbb &a) const
	{
		return p<a.p;
	}
}tmp[2000002];
vector<aaa> Vec;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),t=mp1_t=tmp_t=0,mp.clear(),mp1.clear(),Vec.clear(),mn=ans=inf,Mx=-inf;
		for(int i=1;i<=n;++i)
		{
			read(a[i]),mx[i]=i,vec[i].clear(),T[i]=T1[i]=0;
			if(!mp1.count(a[i]))mp1[a[i]]=(++mp1_t);
			vec[mp1[a[i]]].push_back(i);
		}
		for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),mx[x]=max(mx[x],y);
		for(int i=1,x,s;i<=n;++i)
		{
			t=max(t,mx[i]),x=mp1[a[i]],s=T1[x],++T1[x];
			while(T[x]<vec[x].size() && vec[x][T[x]]<=t)++T[x];
			//printf("i:%d T[%d]=%d\n",i,x,T[x]);
			if(!mp.count(a[i]))
			{
				mp[a[i]]=P(s,T[x]-1);
				//printf("! %d %d %d\n",i,s,T[x]-1);
				continue;
			}
			p=mp[a[i]];
			if(p.second>=i)
			{
				mp[a[i]]=P(p.first,T[x]-1);
				continue;
			}
			if(p.first!=p.second)Vec.push_back((aaa){P(vec[x][p.first],vec[x][p.second-1]),P(vec[x][p.first+1],vec[x][p.second])});
			mp[a[i]]=P(s,T[x]-1);
			//printf("!! %d %d %d\n",i,s,T[x]-1);
		}
		for(it=mp.begin();it!=mp.end();++it)
		{
			int x=mp1[(*it).first];
			p=(*it).second;
			if(p.first!=p.second)Vec.push_back((aaa){P(vec[x][p.first],vec[x][p.second-1]),P(vec[x][p.first+1],vec[x][p.second])});
		}
		//sort(Vec.begin(),Vec.end());
		for(int i=0;i<Vec.size();++i)
		{
			//printf("{(%d,%d),(%d,%d)}",Vec[i].a.first,Vec[i].a.second,Vec[i].b.first,Vec[i].b.second);
			Mx=max(Mx,Vec[i].a.second);
			tmp[++tmp_t]=(bbb){P(Vec[i].a.first,Vec[i].b.second),0};
			tmp[++tmp_t]=(bbb){Vec[i].b,1};
		}
		//puts("");
		sort(tmp+1,tmp+tmp_t+1);
		if(!tmp_t)ans=0;
		for(int i=1;i<=tmp_t;++i)
		{
			//printf("%d:%d %d\n",i,Mx,tmp[i].p.first);
			ans=min(ans,Mx-tmp[i].p.first+1);
			if(tmp[i].o==1)break;
			Mx=max(Mx,tmp[i].p.second);
		}
		printf("%d\n",ans);
	}
	return 0;
}
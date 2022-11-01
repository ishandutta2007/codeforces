#include <bits/stdc++.h>
using namespace std;
#define N ((int)601*1000)
#define SQ ((int)500)

int n,q,C,ans,base_ans,res[N];
int _l[N],_r[N],_c[N];
set <int> _add[2*N],_rem[2*N],_now;
int sz=1,cnt[N],cnt_e[2*N],best[N];
map <pair<int,int>,int> mp;
vector <pair<int,int> > e[N],big_e[N],qu;
vector <int> vec,v_c;
pair <int,int> fen[N];

void change(pair <int,int> &x,int y)
{
	if(cnt[x.first]<cnt[y])x.second=x.first,x.first=y;
	else if(cnt[x.second]<cnt[y] && y!=x.first)x.second=y;
}

void update(int x,int v){for(;x<N;x+=x&-x)change(fen[x],v);}

pair <int,int> query(int x)
{
	pair <int,int> res={0,0};
	for(;x>0;x-=x&-x)change(res,fen[x].first),change(res,fen[x].second);
	return res;
}

int main()
{
	scanf("%d%d",&n,&C);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&_l[i],&_r[i],&_c[i]);
		vec.push_back(_l[i]);vec.push_back(_r[i]);
		v_c.push_back(_c[i]);
	}
	v_c.push_back(-1);sort(v_c.begin(),v_c.end());v_c.resize(unique(v_c.begin(),v_c.end())-v_c.begin());
	sort(vec.begin(),vec.end());vec.resize(unique(vec.begin(),vec.end())-vec.begin());
	for(int i=1;i<=n;i++)
	{
		_add[lower_bound(vec.begin(),vec.end(),_l[i])-vec.begin()].insert(i);
		_rem[lower_bound(vec.begin(),vec.end(),_r[i])-vec.begin()].insert(i);
	}
	for(int i=0;i<vec.size();i++)
	{
		for(auto u:_add[i])_now.insert(u);
		for(auto u:_rem[i])_now.erase(u);
		if(_now.size()==2)
		{
			int v=*_now.begin(),u=*_now.rbegin();
			if(v>u)swap(v,u);
			if(!mp[{v,u}])
			{
				mp[{v,u}]=sz;
				e[v].push_back({u,sz});
				e[u].push_back({v,sz});
				sz++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(e[i].size()<SQ)continue;
		for(auto u:e[i])
			big_e[u.first].push_back({i,u.second});
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int x;scanf("%d",&x);
		if(!vec.size())printf("%d\n",x);
		qu.push_back({x,i});
	}
	if(!vec.size())return 0;
	sort(qu.begin(),qu.end());reverse(qu.begin(),qu.end());
	base_ans=vec[0];
	while(qu.size() && qu.back().first<=ans+base_ans)res[qu.back().second]=qu.back().first,qu.pop_back();
	for(int i=0;i<(int)vec.size()-1;i++)
	{
		for(auto u:_add[i])_now.insert(u);
		for(auto u:_rem[i])_now.erase(u);
		int len=vec[i+1]-vec[i];
		if(_now.size()==2)
		{
			int v=*_now.begin(),u=*_now.rbegin();
			if(_c[v]+_c[u]>C)continue;
			if(v>u)swap(v,u);
			int id=mp[{v,u}];
			cnt_e[id]+=len;
			ans=max(ans,cnt[v]+cnt[u]+cnt_e[id]);
			if(e[v].size()>=SQ)best[v]=max(best[v],cnt[u]+cnt_e[id]);
			if(e[u].size()>=SQ)best[u]=max(best[u],cnt[v]+cnt_e[id]);
		}
		if(_now.size()==1)
		{
			int v=*_now.begin();
			if(_c[v]>C)continue;
			cnt[v]+=len;ans=max(ans,cnt[v]);
			//
			update(lower_bound(v_c.begin(),v_c.end(),_c[v])-v_c.begin(),v);
			int id=upper_bound(v_c.begin(),v_c.end(),C-_c[v])-v_c.begin()-1;
			if(id!=0)
			{
				pair <int,int> p=query(id);
				if(p.first!=v)ans=max(ans,cnt[v]+cnt[p.first]);
				else ans=max(ans,cnt[v]+cnt[p.second]);
			}
			//
			int now=0;
			if(e[v].size()>=SQ)now=best[v];
			else for(auto u:e[v])if(_c[v]+_c[u.first]<=C)now=max(now,cnt_e[u.second]+cnt[u.first]);
			now+=cnt[v];
			ans=max(ans,now);
			for(auto u:big_e[v])if(_c[v]+_c[u.first]<=C)best[u.first]=max(best[u.first],cnt[v]+cnt_e[u.second]);
		}
		if(_now.size()==0)base_ans+=len;
		while(qu.size() && qu.back().first<=ans+base_ans)res[qu.back().second]=vec[i+1]-(ans+base_ans-qu.back().first),qu.pop_back();
	}
	while(qu.size())res[qu.back().second]=vec.back()+qu.back().first-(ans+base_ans),qu.pop_back();
	for(int i=0;i<q;i++)printf("%d\n",res[i]);
	return 0;
}
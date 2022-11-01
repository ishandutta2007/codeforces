#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define MOD ((ll)1e9+7)

struct Node
{
	int l,r,pref;
	ll hash;
	Node(){l=r=pref=hash=0;}	
};

int n,m,strt,fnsh,sz=1,root[N],par[N];
ll tvn[N];
vector <pair<int,int> > e[N];
bool mark[N];
Node seg[300*N];

int update_rem(int ql,int qr,int id,int xl=0,int xr=N)
{
	if(qr<=xl || xr<=ql)return id;
	if(ql<=xl && xr<=qr)return 0;
	int mid=(xl+xr)/2,now=sz;sz++;
	seg[now]=seg[id];
	seg[now].l=update_rem(ql,qr,seg[id].l,xl,mid);
	seg[now].r=update_rem(ql,qr,seg[id].r,mid,xr);
	seg[now].hash=(seg[seg[now].l].hash+tvn[mid-xl]*seg[seg[now].r].hash)%MOD;
	seg[now].pref=seg[seg[now].l].pref;
	if(seg[now].pref==mid-xl)seg[now].pref+=seg[seg[now].r].pref;
	return now;
}

int update_add(int q,int id,int xl=0,int xr=N)
{
	if(xl==xr-1)
	{
		seg[sz].hash=seg[sz].pref=1;
		sz++;
		return sz-1;
	}
	int mid=(xl+xr)/2,now=sz;sz++;
	seg[now]=seg[id];
	if(q<mid)seg[now].l=update_add(q,seg[id].l,xl,mid);
	else seg[now].r=update_add(q,seg[id].r,mid,xr);
	seg[now].hash=(seg[seg[now].l].hash+tvn[mid-xl]*seg[seg[now].r].hash)%MOD;
	seg[now].pref=seg[seg[now].l].pref;
	if(seg[now].pref==mid-xl)seg[now].pref+=seg[seg[now].r].pref;
	return now;
}

int query_pref(int q,int id,int xl=0,int xr=N)
{
	if(xl>=q)return seg[id].pref;
	int mid=(xl+xr)/2;
	if(q<mid)
	{
		int res=query_pref(q,seg[id].l,xl,mid);
		if(res==mid-q)res+=seg[seg[id].r].pref;
		return res;
	}
	return query_pref(q,seg[id].r,mid,xr);
}

bool query_comp(int id1,int id2,int xl=0,int xr=N)
{
	if(xl==xr-1)return seg[id1].hash<seg[id2].hash;
	int mid=(xl+xr)/2;
	if(seg[seg[id1].r].hash!=seg[seg[id2].r].hash)return query_comp(seg[id1].r,seg[id2].r,mid,xr);
	return query_comp(seg[id1].l,seg[id2].l,xl,mid);
}

struct cmp
{
	bool operator ()(int x,int y) const
	{
		if(seg[root[x]].hash==seg[root[y]].hash)return x<y;
		return query_comp(root[x],root[y]);
	}
};

int main()
{
//	ios_base::sync_with_stdio(0);cin.tie(0);
	tvn[0]=1;for(int i=1;i<N;i++)tvn[i]=(tvn[i-1]*2)%MOD;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int v,u,w;
		cin>>v>>u>>w;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	cin>>strt>>fnsh;
	set <int,cmp> s;s.insert(strt);mark[strt]=1;
	while(s.size())
	{
		int x=*s.begin();s.erase(s.begin());
		if(x==fnsh)
		{
			vector <int> res;
			while(fnsh)
			{
				res.push_back(fnsh);
				fnsh=par[fnsh];
			}
			reverse(res.begin(),res.end());
			cout<<seg[root[x]].hash<<"\n"<<res.size()<<"\n";
			for(auto u:res)cout<<u<<" ";cout<<"\n";
			return 0;
		}
		for(auto u:e[x])
		{
			int len=query_pref(u.second,root[x]);
			int ex=update_rem(u.second,u.second+len,root[x]);
			ex=update_add(u.second+len,ex);
			if(!mark[u.first] || query_comp(ex,root[u.first]))
			{
				mark[u.first]=1;
				par[u.first]=x;
				s.erase(u.first);
				root[u.first]=ex;
				s.insert(u.first);
			}
		}
	}
	cout<<"-1\n";
    return 0;
}
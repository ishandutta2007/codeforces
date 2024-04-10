#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)201*1000)
#define INF ((ll)1e10)


ll n,m;
vector <ll> num;
pair <char,pair<ll,ll> > in[N];
map <ll,ll> _id;
set <ll> st[N];
ll maxi[4*N],ans;

void add(ll q,ll xl,ll xr,ll id,ll val)
{
	if(xl==xr-1)
	{
		maxi[id]=*(st[xl].rbegin());
		return ;
	}
	ll mid=(xl+xr)/2;
	if(q<mid)add(q,xl,mid,id*2,val);
	else add(q,mid,xr,id*2+1,val);
	maxi[id]=max(maxi[id*2],maxi[id*2+1]);
}

void del(ll q,ll xl,ll xr,ll id,ll val)
{
	if(xl==xr-1)
	{
		if(st[xl].size()==0)maxi[id]=-1;
		else maxi[id]=*(st[xl].rbegin());
		return ;
	}
	ll mid=(xl+xr)/2;
	if(q<mid)del(q,xl,mid,id*2,val);
	else del(q,mid,xr,id*2+1,val);
	maxi[id]=max(maxi[id*2],maxi[id*2+1]);
}

void go(ll xl,ll xr,ll id,ll val)
{
	if(xl==xr-1)
	{
		ans=xl;
		return ;
	}
	ll mid=(xl+xr)/2;
	if(maxi[id*2]>val)go(xl,mid,id*2,val);
	else go(mid,xr,id*2+1,val);
}

bool query(ll ql,ll qr,ll xl,ll xr,ll id,ll val)
{
	if(xr<=ql || qr<=xl)return 0;
	if(ql<=xl && xr<=qr)
	{
		if(maxi[id]<=val)return 0;
		go(xl,xr,id,val);
		return 1;
	}
	ll mid=(xl+xr)/2;
	if(query(ql,qr,xl,mid,id*2,val))return 1;
	return query(ql,qr,mid,xr,id*2+1,val);
}

int main()
{
	scanf("%d",&m);
	memset(maxi,-1,sizeof maxi);
	for(int i=0;i<m;i++)
	{
		char ex[10];
		scanf("%s%d%d",&ex,&in[i].second.first,&in[i].second.second);
		in[i].first=ex[0];
		num.push_back(in[i].second.first);
	}
	sort(num.begin(),num.end());num.resize(unique(num.begin(),num.end())-num.begin());
	for(int i=0;i<num.size();i++)_id[num[i]]=n++;
	for(int i=0;i<m;i++)
	{
		char s=in[i].first;
		ll x=_id[in[i].second.first],y=in[i].second.second;
		if(s=='a')st[x].insert(y),add(x,0,n,1,y);
		if(s=='r')st[x].erase(y),del(x,0,n,1,y);
		if(s=='f')
		{
			x++;
			if(!query(x,n,0,n,1,y))printf("-1\n");
			else printf("%d %d\n",num[ans],*st[ans].upper_bound(y));
		}
	}
	return 0;
}
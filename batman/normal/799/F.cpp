#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)201*1000)
#define MOD ((ll)1e9+7)

struct Node
{
	int lazy,min,num;
	ll sum;
};

int n,m,prt[N];
ll ans;
Node seg[2][2*N];
vector <int> _l[N];
set <int> s[2];

void shift(int in,int id)
{
	int ex=seg[in][id].lazy;
	seg[in][id].lazy=0;
	seg[in][id*2].lazy+=ex;
	seg[in][id*2].min+=ex;
	seg[in][id*2+1].lazy+=ex;
	seg[in][id*2+1].min+=ex;
}

Node merge(Node x,Node y)
{
	if(x.min<y.min)return {0,x.min,x.num,x.sum};
	if(x.min>y.min)return {0,y.min,y.num,y.sum};
	return {0,x.min,x.num+y.num,x.sum+y.sum};
}

void build(int xl=0,int xr=m/2+5,int id=1)
{
	if(xl>=xr-1)
	{
		seg[0][id]={0,0,(xr-xl),(xl==xr)?0:(xl*2+1)};
		seg[1][id]={0,0,(xr-xl),(xl==xr)?0:(xl*2+2)};
		return ;
	}
	int mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
	seg[0][id]={0,0,(xr-xl),seg[0][id*2].sum+seg[0][id*2+1].sum};
	seg[1][id]={0,0,(xr-xl),seg[1][id*2].sum+seg[1][id*2+1].sum};
}

void update(int ql,int qr,int val,int in,int xl=0,int xr=m/2+5,int id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[in][id].lazy+=val;
		seg[in][id].min+=val;
		return ;
	}
	shift(in,id);
	int mid=(xl+xr)/2;
	update(ql,qr,val,in,xl,mid,id*2);
	update(ql,qr,val,in,mid,xr,id*2+1);
	seg[in][id]=merge(seg[in][id*2],seg[in][id*2+1]);
}

Node query(int ql,int qr,int in,int xl=0,int xr=m/2+5,int id=1)
{
	if(qr<=xl || xr<=ql)return {0,(ll)1e9,0,0};
	if(ql<=xl && xr<=qr)
	{
		return seg[in][id];	
	}
	shift(in,id);
	int mid=(xl+xr)/2;
	return merge(query(ql,qr,in,xl,mid,id*2),query(ql,qr,in,mid,xr,id*2+1));
}

int main()
{
	scanf("%d%d",&n,&m);
	build();
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);l--;r--;
		prt[l]++;
		prt[r+1]--;
		update((l+1)/2,(r+2)/2-((r-l)%2==0 && l%2==0),1,!(l&1));
		if((r-l+1)%2==0)
			update((r+1)/2,m/2+5,1,!(r&1)),
			update((r+2)/2,m/2+5,1,(r&1));
		_l[l].push_back(r);
	}
	for(int i=0;i<m;i++)
	{
		for(auto u:_l[i])
		{
			int l=i,r=u;
			update((l+1)/2,(r+2)/2-((r-l)%2==0 && l%2==0),-1,!(l&1));
			if((r-l+1)%2==0)
				update((r+1)/2,m/2+5,-1,!(r&1)),
				update((r+2)/2,m/2+5,-1,(r&1));
			s[(u&1)].insert(u);
		}
		while(s[0].size() && *s[0].begin()<i)s[0].erase(s[0].begin());
		while(s[1].size() && *s[1].begin()<i)s[1].erase(s[1].begin());
		if(s[!(i&1)].size())
		{
			int r=*s[!(i&1)].begin();
			update((r+1)/2,m/2+5,1,!(r&1)),
			update((r+2)/2,m/2+5,1,(r&1));
		}
		int maxi=-1;
		if(s[0].size())maxi=max(maxi,*s[0].rbegin());
		if(s[1].size())maxi=max(maxi,*s[1].rbegin());
		if(maxi!=-1)
			update((i+1)/2,(maxi-((maxi-i+1)&1)+2)/2,1,!(i&1));
		Node res=merge(query(i/2,(m+(!(i&1)))/2,(i&1)),query((i+1)/2,(m+(i&1))/2,!(i&1)));
		if(res.min==0)ans+=res.sum-1LL*res.num*i;
		if(s[!(i&1)].size())
		{
			int r=*s[!(i&1)].begin();
			update((r+1)/2,m/2+5,-1,!(r&1)),
			update((r+2)/2,m/2+5,-1,(r&1));
		}
		if(maxi!=-1)
			update((i+1)/2,(maxi-((maxi-i+1)&1)+2)/2,-1,!(i&1));
	}
	for(int i=1;i<m;i++)prt[i]+=prt[i-1];
	for(int i=0,now=0;i<m;i++)
	{
		if(!prt[i])
			now++,ans-=1LL*(1+now)*now/2;
		else
			now=0;
	}
	cout<<ans;
	return 0;
}
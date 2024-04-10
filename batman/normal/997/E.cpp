#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)121*1000)

struct Node
{
	int mini,cnt,lazy,lazy_ans;
	ll ans;
	Node(){mini=cnt=lazy=ans=lazy_ans=0;}
};

int n,q,a[N];
ll ans[N];
vector <pair<int,int> > qu[N];
Node seg[4*N];

void build(int xl=0,int xr=n+1,int id=1)
{
	seg[id].mini=xl;
	seg[id].cnt=1;
	if(xl==xr-1)return ;
	int mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
}

void shift(int id)
{
	seg[id*2].mini+=seg[id].lazy;
	seg[id*2].lazy+=seg[id].lazy;
	seg[id*2+1].mini+=seg[id].lazy;
	seg[id*2+1].lazy+=seg[id].lazy;
	seg[id].lazy=0;
	if(seg[id].mini==seg[id*2].mini)
		seg[id*2].ans+=1LL*seg[id].lazy_ans*seg[id*2].cnt,
		seg[id*2].lazy_ans+=seg[id].lazy_ans;
	if(seg[id].mini==seg[id*2+1].mini)
		seg[id*2+1].ans+=1LL*seg[id].lazy_ans*seg[id*2+1].cnt,
		seg[id*2+1].lazy_ans+=seg[id].lazy_ans;
	seg[id].lazy_ans=0;
}

Node merge(const Node &x,const Node &y)
{
	Node res;
	res.mini=min(x.mini,y.mini);
	if(x.mini==res.mini)res.cnt+=x.cnt;
	if(y.mini==res.mini)res.cnt+=y.cnt;
	res.ans=x.ans+y.ans;
	return res;
}

void update(int ql,int qr,int val,int xl=0,int xr=n+1,int id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[id].mini+=val;
		seg[id].lazy+=val;
		return ;
	}
	int mid=(xl+xr)/2;
	shift(id);
	update(ql,qr,val,xl,mid,id*2);
	update(ql,qr,val,mid,xr,id*2+1);
	seg[id]=merge(seg[id*2],seg[id*2+1]);
}

ll query(int ql,int qr,int xl=0,int xr=n+1,int id=1)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)return seg[id].ans;
	int mid=(xl+xr)/2;
	shift(id);
	return query(ql,qr,xl,mid,id*2)+query(ql,qr,mid,xr,id*2+1);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	build();
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		qu[r].push_back({l,i});
	}
	vector <int> maxi,mini;
	maxi.push_back(0);mini.push_back(0);
	for(int i=1;i<=n;i++)
	{
		while(maxi.size()>1 && a[maxi.back()]<a[i])
		{
			int ex=maxi.back();maxi.pop_back();
			update(maxi.back()+1,ex+1,a[i]-a[ex]);
		}
		maxi.push_back(i);
		while(mini.size()>1 && a[mini.back()]>a[i])
		{
			int ex=mini.back();mini.pop_back();
			update(mini.back()+1,ex+1,-(a[i]-a[ex]));
		}
		mini.push_back(i);
		update(1,n+1,-1);
		seg[1].lazy_ans++;
		seg[1].ans+=seg[1].cnt;
		if(seg[1].mini!=0)cout<<"hir\n";
		for(auto u:qu[i])
			ans[u.second]=query(u.first,i+1);
	}
	for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
	return 0;
}
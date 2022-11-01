#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)201*1000)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

int q,n,a[N],deg[N];
map <int,int> id;
vector <int> e[N];
pair <int,int> qu[N];
int strt[N],fnsh[N],rev_strt[N],num;

void dfs(int x)
{
	rev_strt[num]=x;strt[x]=num++;
	for(auto u:e[x])
		dfs(u);
	fnsh[x]=num;
}

ll seg[2][4*N],lazy[4*N];

void mrg(int id)
{
	seg[0][id]=(seg[0][id*2]+seg[0][id*2+1])%MOD;
	seg[1][id]=(seg[1][id*2]+seg[1][id*2+1])%MOD;
}

void shift(int id)
{
	seg[0][id*2]*=lazy[id];seg[0][id*2]%=MOD;
	seg[1][id*2]*=lazy[id];seg[1][id*2]%=MOD;
	seg[0][id*2+1]*=lazy[id];seg[0][id*2+1]%=MOD;
	seg[1][id*2+1]*=lazy[id];seg[1][id*2+1]%=MOD;
	lazy[id*2]*=lazy[id];lazy[id*2]%=MOD;
	lazy[id*2+1]*=lazy[id];lazy[id*2+1]%=MOD;
	lazy[id]=1;
}

void build(int xl=0,int xr=n,int id=1)
{
	lazy[id]=1;
	if(xl==xr-1)
	{
		seg[0][id]=a[rev_strt[xl]];
		return ;
	}
	int mid=(xl+xr)/2;
	build(xl,mid,id*2);
	build(mid,xr,id*2+1);
	mrg(id);
}

void update1(int q,int xl=0,int xr=n,int id=1)
{
	if(xl==xr-1)
	{
		seg[1][id]=seg[0][id];
		return ;
	}
	int mid=(xl+xr)/2;
	shift(id);
	if(q<mid)update1(q,xl,mid,id*2);
	else update1(q,mid,xr,id*2+1);
	mrg(id);
}

void update2(int ql,int qr,ll val,int xl=0,int xr=n,int id=1)
{
	if(qr<=xl || xr<=ql)return ;
	if(ql<=xl && xr<=qr)
	{
		seg[0][id]*=val;seg[0][id]%=MOD;
		seg[1][id]*=val;seg[1][id]%=MOD;
		lazy[id]*=val;lazy[id]%=MOD;
		return ;
	}
	int mid=(xl+xr)/2;
	shift(id);
	update2(ql,qr,val,xl,mid,id*2);
	update2(ql,qr,val,mid,xr,id*2+1);
	mrg(id);
}

ll query(int ql,int qr,int xl=0,int xr=n,int id=1)
{
	if(qr<=xl || xr<=ql)return 0;
	if(ql<=xl && xr<=qr)return seg[1][id];
	int mid=(xl+xr)/2;
	shift(id);
	return (query(ql,qr,xl,mid,id*2)+query(ql,qr,mid,xr,id*2+1))%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ex;
	cin>>ex>>q;
    id[ex]=++n;a[n]=ex;
    for(int i=0;i<q;i++)
    {
    	int t,x,y;
    	cin>>t;
    	qu[i].second=-1;
    	if(t==1)
    	{
    		cin>>x>>y;
    		id[y]=++n;a[n]=y;y=n;
    		e[x].push_back(y);
    		qu[i]={x,y};
		}
		if(t==2)
			cin>>qu[i].first;
	}
	dfs(1);
	build();
	update1(strt[1]);deg[1]=1;
	for(int i=0;i<q;i++)
	{
		int x=qu[i].first,y=qu[i].second;
		if(y==-1)
			cout<<((query(strt[x],fnsh[x])*tavan((((query(strt[x],strt[x]+1)*tavan(a[x],MOD-2))%MOD)*tavan(deg[x],MOD-2))%MOD,MOD-2))%MOD)<<"\n";
		else
		{
			update2(strt[x],fnsh[x],((deg[x]+1)*tavan(deg[x],MOD-2))%MOD);
			update1(strt[y]);
			deg[x]++;deg[y]=1;
		}
	}
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)201*1000)

int n,q,a[N],fen[N];
ll ans[N];
vector <pair<int,pair<int,int> > > qu[N];

void update(int x,int val){for(;x<N;x+=x&-x)fen[x]+=val;}
int query(int x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		int x,y,x2,y2;
		cin>>y>>x>>y2>>x2;
		ans[i]=1LL*(x-1)*(x-2)/2+1LL*(n-x2)*(n-x2-1)/2+1LL*(y-1)*(y-2)/2+1LL*(n-y2)*(n-y2-1)/2;
		qu[y-1].push_back({x-1,{i,0}});
		qu[y-1].push_back({x2,{-i,y-1}});
		qu[y2].push_back({x-1,{-i,x-1}});
		qu[y2].push_back({x2,{i,n-x2-y2}});
	}
	for(int i=1;i<=n;i++)
	{
		update(a[i],1);
		for(auto u:qu[i])
		{
			int now=u.second.second;
			if(u.second.first<0)now-=query(u.first);
			else now+=query(u.first);
			ans[abs(u.second.first)]-=1LL*now*(now-1)/2;
		}
	}
	for(int i=1;i<=q;i++)
		cout<<1LL*n*(n-1)/2-ans[i]<<"\n";
	return 0;
}
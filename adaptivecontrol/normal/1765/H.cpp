#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int p[2005],tp[2005];
int in[2005];
V<int> v[2005];
P<int,int> ed[2005];
int n,m;
int val[2005];
bool check(int x){
	FOR(i,1,n)in[i]=0,val[i]=0;
	FOR(i,1,m)in[ed[i].F]++;
	queue<int> q;
	FOR(i,1,n)if(!in[i])q.emplace(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(auto u:v[x]){
			gmin(tp[u],tp[x]-1);
			if(--in[u]==0)q.emplace(u);
		}
	}
	FOR(i,1,n){
		if(tp[i]<=0){
			RE 0;
		}
		val[tp[i]]++;
	}
	int sum=0;
	FOR(i,1,n){
		sum+=val[i];
		if(sum>i)RE 0;
	}
	RE 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>p[i];
	FOR(i,1,m){
		cin>>ed[i].F>>ed[i].S;
		v[ed[i].S].PB(ed[i].F);
	}
	FOR(s,1,n){
		int l=1,r=p[s],mid,ans=-1;
		while(r>=l){
			mid=(l+r)>>1;
			FOR(i,1,n)tp[i]=p[i];
			tp[s]=mid;
			if(check(mid)){
				r=mid-1;ans=mid;
			}else l=mid+1;
		}
		cout<<ans<<' ';
	}
	RE 0;
}
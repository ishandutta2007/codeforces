#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
struct node{
	ll to,cost;
};
vector<node> a[500010];
ll ans0[500010],ansa[500010];
ll k,n,u,v,w;
void dfs(ll x,ll fa){
	priority_queue<ll> q;
	ll ans=0;
	repeat(i,0,a[x].size()){
		ll p=a[x][i].to;
		if(p==fa)continue;
		dfs(p,x);
		ans+=ans0[p];
		q.push(ansa[p]-ans0[p]+a[x][i].cost);
	}
	repeat(i,0,k-1){
		if(q.empty())break;
		if(q.top()<=0)break;
		ans+=q.top();
		q.pop();
	}
	ansa[x]=ans;
	repeat(i,0,1){
		if(q.empty())break;
		if(q.top()<=0)break;
		ans+=q.top();
		q.pop();
	}
	ans0[x]=ans;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		repeat(i,0,n-1){
			cin>>u>>v>>w;u--,v--;
			a[u].push_back((node){v,w});
			a[v].push_back((node){u,w});
		}
		dfs(0,-1);
		cout<<ans0[0]<<endl;
		repeat(i,0,n)
			a[i].clear();
	}
	return 0;
}
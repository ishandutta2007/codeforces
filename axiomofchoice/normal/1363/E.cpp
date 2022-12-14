#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll;
#define int ll
int n,x;
vector<int> a[N];
int cost[N],b[N],c[N],ans,cnt[N][2];
void dfs(int x,int fa){
	if(fa!=-1)cost[x]=min(cost[x],cost[fa]); 
	for(auto p:a[x])
	if(p!=fa){
		dfs(p,x);
		cnt[x][0]+=cnt[p][0];
		cnt[x][1]+=cnt[p][1];
	}
	if(b[x]!=c[x])cnt[x][b[x]]++;
	int t=min(cnt[x][0],cnt[x][1]);
	ans+=2*t*cost[x];
	cnt[x][0]-=t;
	cnt[x][1]-=t;
}
signed main(){
	cin>>n;
	repeat(i,0,n)cin>>cost[i]>>b[i]>>c[i];
	repeat(i,0,n-1){
		int x,y; cin>>x>>y; x--,y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(0,-1);
	if(cnt[0][0] || cnt[0][1])cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
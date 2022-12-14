#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
#define int ll
vector<int> a[N];
int n,m,k;
deque<int> rec; pair<int,int> record;
int dis[N],fa[N],ans=inf;
queue<int> q;
void bfs(int s){
	fill(dis,dis+n+1,-1); dis[s]=0;
	q.push(s); fa[s]=-1;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(auto p:a[x])
		if(p!=fa[x]){
			if(dis[p]==-1){
				dis[p]=dis[x]+1;
				fa[p]=x;
				q.push(p);
			}
			else{
				if(ans>dis[x]+dis[p]+1){
					ans=dis[x]+dis[p]+1;
					record={x,p};
				}
			}
		}
	}
}
signed main(){
	cin>>n>>m>>k;
	repeat(i,0,m){
		int x,y; cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if(n-1!=m){
		bfs(1);
		{
			for(int i=record.first;i!=1;i=fa[i])rec.push_front(i);
			for(int i=record.second;i!=1;i=fa[i])rec.push_back(i);
			int t=1;
			while(rec.front()==rec.back()){
				t=rec.front();
				rec.pop_front(),rec.pop_back();
			}
			rec.push_back(t);
		} 
		if((int)rec.size()<=k){
			cout<<2<<endl;
			cout<<rec.size()<<endl;
			for(auto i:rec)cout<<i<<' ';
		}
		else{
			cout<<1<<endl;
			repeat(i,0,(k+1)/2)
				cout<<rec[i*2]<<' ';
		}
	}
	else{
		bfs(1);
		int cnt=0;
		repeat(i,1,n+1)cnt+=dis[i]%2==1;
		int co=cnt>=(k+1)/2;
		repeat(i,1,n+1)
		if(dis[i]%2==co)
			rec.push_back(i);
		cout<<1<<endl;
		repeat(i,0,(k+1)/2)
			cout<<rec[i]<<' ';
	}
	return 0;
}
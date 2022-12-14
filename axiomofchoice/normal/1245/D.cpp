#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define maxn 100010
#define inf 1e9
#define int ll
int T,n;
struct DSU{//d[x]=d[y]d[x]==d[y]
	int a[2010];
	void init(){
		repeat(i,0,n+1)a[i]=i;
	}
	int fa(int x){
		return a[x]==x?x:a[x]=fa(a[x]);
	}
	int& operator[](int x){
		return a[fa(x)];
	}
}d;
struct node{
	int x,y,c,k;
}a[2010];
struct node2{
	int u,v,cost;
	bool operator<(node2 b)const{return cost>b.cost;}
};
priority_queue<node2> q;
int ans=0;
vector<int> ansbuild;
vector<pii> anspath;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	d.init();
	repeat(i,0,n)
		cin>>a[i].x>>a[i].y;
	repeat(i,0,n)cin>>a[i].c;
	repeat(i,0,n)cin>>a[i].k;
	repeat(i,0,n)
	repeat(j,i,n){
		if(i==j)q.push((node2){i,i,a[i].c});
		else q.push((node2){i,j,
		(a[i].k+a[j].k)*
		(abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y))});
	}
	while(!q.empty()){
		int u=q.top().u,v=q.top().v,cost=q.top().cost; q.pop();
		if(u==v){
			if(d[u]==d[n])continue;
			else{
				d[u]=d[n];
				ansbuild.push_back(u);
				ans+=cost;
			}
		}
		else{
			if(d[u]==d[v])continue;
			if(d[u]!=d[v]){
				d[u]=d[v];
				anspath.push_back((pii){u,v});
				ans+=cost;
			}
		}
	}
	cout<<ans<<endl;
	cout<<ansbuild.size()<<endl;
	repeat(i,0,ansbuild.size())
		cout<<ansbuild[i]+1<<' ';
	cout<<endl<<anspath.size()<<endl;
	repeat(i,0,anspath.size())
		cout<<anspath[i].first+1<<' '
		<<anspath[i].second+1<<endl;
	return 0;
}
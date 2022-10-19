#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,a,b,da,db,cnt,head[N],dep[N];
struct edge{
	int to,next;
	edge(){}
	edge(int u,int v){to = u;next = v;}
}e[N<<1];
void add(int u,int v){
	e[++cnt] = edge(v,head[u]);
	head[u] = cnt;
}
void init(){
	rep(i,1,n) head[i] = -1,dep[i] = 0;
	cnt = 0;
}
void dfs(int u,int fa){
	dep[u] = dep[fa]+1;
	for(int i = head[u];~i;i = e[i].next){
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v,u);
	}
}
int solve(){
	if(db <= 2*da) return 1;
	dfs(a,0);
	if(dep[b]-1 <= da) return 1;
	dfs(1,0);
	int pos = max_element(dep+1,dep+n+1)-dep;// cout << pos << endl;
	dfs(pos,0);
	int len = *max_element(dep+1,dep+n+1);// cout<< len << endl;
	if(da*2 >= len-1) return 1;
	return 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);init();
 		rep(i,2,n){
 			int u,v;
 			scanf("%d%d",&u,&v);
 			add(u,v);add(v,u);
 		}
 		if(solve()) puts("Alice");
 		else puts("Bob");
 	}
	return 0;
}
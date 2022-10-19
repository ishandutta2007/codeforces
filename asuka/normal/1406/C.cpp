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
int t,n,head[N],f[N],siz[N],son[N],fat[N],cnt;
struct edge{
	int to,next;
	edge(){}
	edge(int a,int b){to = a;next = b;}
}e[N<<1];
void init(){
	cnt = 0;
	rep(i,1,n) head[i] = -1;
	rep(i,1,n) f[i] = fat[i] = son[i] = siz[i] = 0;
}
void add(int u,int v){
	e[++cnt] = edge(v,head[u]);
	head[u] = cnt;
}
void dfs(int u,int fa){
	siz[u] = 1;fat[u] = fa;
	for(int i = head[u];~i;i = e[i].next){
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v,u);siz[u] += siz[v];
		if(siz[v] > siz[son[u]]){
			son[u] = v;
		}
	}
	f[u] = siz[son[u]];
	if(n-siz[u] > siz[son[u]]){
		son[u] = fa;f[u] = n-siz[u];
	}
}
int get_leaf(int u,int fa){
	//cout << u << ' ' << fa << endl;
	fat[u] = fa;
	int flag = 0;
	for(int i = head[u];~i;i = e[i].next){
		int v = e[i].to;
		if(v == fa) continue;
		int ans = get_leaf(v,u);
		if(ans) return ans;
		flag = 1;
	}
	if(flag == 0) return u;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d",&n);
 		init();
 		rep(i,2,n){
 			int u,v;
 			scanf("%d%d",&u,&v);
 			add(u,v);add(v,u);
 		}
 		dfs(1,0);
 		int val = *min_element(f+1,f+n+1);
 		VI temp;
 		rep(i,1,n) if(f[i] == val) temp.pb(i);
 		if(temp.size() > 1){
 			int u = temp[0],v = temp[1],tu = get_leaf(u,v);
 			//cout << u << ' ' << v << ' ' << tu << endl;
			printf("%d %d\n",tu,fat[tu]);
			printf("%d %d\n",tu,v);
 		}else{
 			int u = 1,v = e[head[u]].to;
 			printf("%d %d\n",u,v);
 			printf("%d %d\n",u,v);
 		}
 	}
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define N 300015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
using namespace std;
int n,k,f[N],in[N],pos[N];
VI e[N];
namespace DSU{
	int fa[N];
	deque<int> s[N];
	int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
	void uni(int u,int v){
		u = find(u); v = find(v);
		if(u == v) return;
		if(s[u].size() > s[v].size()){
			while(!s[v].empty()) s[u].push_back(s[v].front()),s[v].pop_front();
			fa[v] = u;
		}else{
			while(!s[u].empty()) s[v].push_front(s[u].back()),s[u].pop_back();
			fa[u] = v;
		}
		return;
	}
}
using namespace DSU;
void add(int u,int v){
	e[u].pb(v),in[v]++;
//	printf("edge: %d %d\n",u,v);
}
queue<int> q;
void topo(){
	VI ans;
	rep(i,1,n) {
		if(fa[i] == i && in[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto it=s[u].begin();it!=s[u].end();it++) ans.pb(*it);
		for(auto v:e[u]){
			if(--in[v] == 0) q.push(v);
		}
	}
	if((int)ans.size() == n){
		for(auto x:ans) printf("%d ",x);
	}else{
		puts("0");
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&k);
 	rep(i,1,n) scanf("%d",&f[i]);
 	rep(i,1,n) fa[i] = i,s[i].pb(i);
 	rep(i,1,k){
 		int a,b; scanf("%d%d",&a,&b);
 		int sa = find(a),sb = find(b);
 		// printf("*** %d %d\n",s[sa].back(),s[sb].front());
 		if(s[sa].back() == a && s[sb].front() == b && sa != sb){
 			uni(sa,sb);
 			// nxt[a] = b;
 		}else{
 			// puts("AAA");
 			puts("0");
 			return 0;
 		}
 	}
 	// rep(i,1,n) printf("%d ",find(i));
 	// printf("\n");
 	rep(i,1,n){
 		int cur = 0;
 		for(auto it = s[i].begin();it != s[i].end();it++) pos[*it] = ++cur;
 	}
 	rep(i,1,n){
 		if(f[i]){
 			if(find(f[i]) == find(i)){
 				if(pos[f[i]] > pos[i]){
 					puts("0");
 					return 0;
 				}
 			}else{
 				add(find(f[i]),find(i));
 			}
 		}
 	}
 	topo();
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
int t,n,m,k,in[N],vis[N],gkp[N];
queue<int> q;
VI e[N],cli;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d",&t);
 	while(t--){
 		scanf("%d%d%d",&n,&m,&k);
 		while(!q.empty()) q.pop();
 		rep(i,1,n) e[i].clear(),in[i] = vis[i] = gkp[i] = 0;
 		rep(i,1,m){
 			int u,v; scanf("%d%d",&u,&v);
 			e[u].pb(v); e[v].pb(u);
 			in[u]++;in[v]++;
 		}
 		int tot = n;
 		if(k*(k-1) > 2*m) {puts("-1"); continue;}
 		rep(i,1,n) if(in[i] < k) q.push(i);
 		rep(i,1,n) sort(all(e[i]));
 		while(!q.empty()){
 			int u = q.front(); q.pop();
 			if(vis[u]) continue;
 			tot--;
 			vis[u] = 1;
 			// rep(i,1,n) cout << in[i] << ' ';
 			// cout << endl;
 			if(in[u] == k-1){
 				//cout << u << "fuck" << endl;
				cli.clear(); cli.pb(u);
				for(auto x:e[u]){
					if(vis[x]) continue;
					cli.pb(x);
				}
				bool ff = 0;
				for(auto p:cli){
					for(auto q:cli){
						if(p == q) continue;
						if(!binary_search(all(e[p]),q)){
						//	if(u == 1 || u == 2 || u == 3) puts("???");
							ff = 1; break;
						}
					}
				}
				if(ff == 0){
					puts("2");
					for(auto x:cli) printf("%d ",x);
					printf("\n");
					goto fuckyou;
				}
			}
			vis[u] = 1;
			//cout << "WTF" << u << endl;
 			for(auto v:e[u]){
 				in[v]--;
 				if(vis[v]) continue;
 				//cout << u << " -> " << v << endl;
 				if(in[v] < k) q.push(v);
 			}
 		}
 		if(tot > 0){
 			printf("%d %d\n",1,tot);
 			rep(i,1,n) if(!vis[i]) printf("%d ",i);
 			printf("\n");
 		}else puts("-1");
 		fuckyou: continue;
 	}
	return 0;
}
/*
1
2 1 2
1 2
*/
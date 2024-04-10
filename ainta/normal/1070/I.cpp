#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

int TC;
#define N_ 10100
#define M_ 101000
struct MaxFlow{
	vector<int>G[N_];
	struct Edge{
		int b, e, f;
	}E[M_];
	int EC, flow, PV[N_], Q[N_], Level[N_], n, source, sink, INF = 1e9;
	void init(int N, int S, int T){
		source = S, sink = T, flow = EC = 0;
		n = N;
		for(int i=0;i<=n;i++)G[i].clear();
	}
	void Add_Edge(int a, int b, int f){
		G[a].push_back(EC);
		G[b].push_back(EC+1);
		E[EC++] = {a,b,f};
		E[EC++] = {b,a,0};
	}
	int BlockFlow(int a, int f){
		if(a==sink)return f;
		for(int &i = PV[a]; i>=0;i--){
			int t = G[a][i];
			if(E[t].f && Level[E[t].e] == Level[a] + 1){
				int ff = BlockFlow(E[t].e, min(E[t].f, f));
				if(ff){
					E[t].f -= ff;
					E[t^1].f += ff;
					return ff;
				}
			}
		}
		return 0;
	}
	bool GetLevel(){
		int head = 0, tail = 0, i;
		for(i=1;i<=n;i++)Level[i] = -1;
		Q[++tail] = source; Level[source] = 0;
		while(head < tail){
			int x = Q[++head];
			for(auto &t : G[x]){
				if(E[t].f && Level[E[t].e] == -1){
					Level[E[t].e] = Level[x] + 1;
					Q[++tail] = E[t].e;
				}
			}
		}
		return Level[sink]!=-1;
	}
	void Dinic(){
		int i, t;
		flow = 0;
		while(GetLevel()){
			for(i=1;i<=n;i++)PV[i] = G[i].size()-1;
			while(t = BlockFlow(source, INF)){
				flow+=t;
			}
		}
	}
}G1;
int n, m, K, Deg[N_], Num[N_];
struct EEE{
	int a, b;
}EE[N_];
void Solve(){
	int i;
	scanf("%d%d%d",&n,&m,&K);
	for(i=1;i<=n;i++)Deg[i]=0;
	for(i=1;i<=m;i++){
		Num[i] = 0;
		scanf("%d%d",&EE[i].a,&EE[i].b);
		Deg[EE[i].a]++,Deg[EE[i].b]++;
	}
	G1.init(n+m+2,n+m+1,n+m+2);
	int s = 0;
	for(i=1;i<=n;i++){
		int t = max(Deg[i]-K,0) * 2;
		s+=t;
		G1.Add_Edge(G1.source, i, t);
	}
	for(i=1;i<=m;i++){
		G1.Add_Edge(EE[i].a, n+i, 1);
		G1.Add_Edge(EE[i].b, n+i, 1);
		G1.Add_Edge(n+i,G1.sink,1);
	}
	G1.Dinic();
	if(G1.flow != s){
		for(i=1;i<=m;i++)printf("%d ",0);
		puts("");
	}
	else{
		int cnt = 0, ccc = 0;
		for(i=1;i<=n;i++){
			for(auto &t : G1.G[i]){
				if(G1.E[t].f == 0 && G1.E[t].e >= n+1 && G1.E[t].e <= n+m){
					Num[G1.E[t].e - n] = m+1+ccc/2;
					ccc++;
				}
			}
		}
		for(i=1;i<=m;i++){
			if(!Num[i])Num[i]=++cnt;
			printf("%d ",Num[i]);
		}
		puts("");
	}
}
int main() {
	scanf("%d",&TC);
	while(TC--){
		Solve();
	}
}
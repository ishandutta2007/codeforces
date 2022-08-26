#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int T , N , M; struct Edge{int end , upEd , w , id;}Ed[_ << 1]; int head[_] , cntEd , ans[_] , x[_] , y[_];
void addEd(int a , int b , int c , int i){Ed[++cntEd] = (Edge){b , head[a] , c , i}; head[a] = cntEd;}
int fa[_ << 1]; int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
void merge(int p , int q){fa[find(p)] = find(q);}

void dfs1(int x , int p){
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			dfs1(Ed[i].end , x);
			if(Ed[i].w != -1){
				int p = __builtin_popcount(Ed[i].w) & 1;
				merge(x , Ed[i].end + N * p); merge(x + N , Ed[i].end + N - N * p);
			}
		}
}

void dfs2(int x , int p){
	for(int i = head[x] ; i ; i = Ed[i].upEd)
		if(Ed[i].end != p){
			dfs2(Ed[i].end , x);
			if(Ed[i].w != -1) ans[Ed[i].id] = Ed[i].w;
			else if(find(x) == find(Ed[i].end)){ans[Ed[i].id] = 0;}
			else{merge(x , Ed[i].end + N); merge(x + N , Ed[i].end); ans[Ed[i].id] = 1;}
		}
}

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cntEd = 0; cin >> N >> M; for(int i = 1 ; i <= N ; ++i){fa[i] = i; fa[i + N] = i + N; head[i] = 0;}
		for(int i = 1 ; i < N ; ++i){int p , q , v; cin >> p >> q >> v; x[i] = p; y[i] = q; addEd(p , q , v , i); addEd(q , p , v , i);}
		for(int i = 1 ; i <= M ; ++i){int a , b , p; cin >> a >> b >> p; merge(a , b + N * p); merge(a + N , b + N - N * p);}
		dfs1(1 , 0); bool flg = 1; for(int i = 1 ; i <= N ; ++i) flg &= find(i) != find(i + N);
		if(!flg){cout << "NO" << endl; continue;}
		cout << "YES" << endl; dfs2(1 , 0);
		for(int i = 1 ; i < N ; ++i) cout << x[i] << ' ' << y[i] << ' ' << ans[i] << '\n';
	}
	return 0;
}
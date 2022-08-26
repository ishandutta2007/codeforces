#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int T , N , M; set < int > out[_]; int ans[_];
struct qry{int s , t , id , c;}; vector < qry > pot1 , pot2;
struct dsu{
	int fa[_] , sz[_] , suf[_] , hd[_] , tl[_];
	void init(){for(int i = 1 ; i <= N ; ++i){fa[i] = i; sz[i] = 1; suf[i] = 0; hd[i] = tl[i] = i;}}
	int find(int x){return fa[x] == x ? x : find(fa[x]);}
}U1 , U2;

void solve(int L , int R , vector < qry > pot){
	if(L == R){for(auto t : pot) ans[t.id] = pot2[L].c; return;}
	int mid = (L + R) >> 1; vector < pair < int* , int > > mdf;
	for(int i = L ; i <= mid ; ++i){
		int p = U1.find(pot2[i].s) , q = U1.find(pot2[i].t); if(p == q) continue;
		if(U1.sz[p] > U1.sz[q]) swap(p , q);
		mdf.emplace_back(&U1.fa[p] , p); U1.fa[p] = q; mdf.emplace_back(&U1.sz[q] , U1.sz[q]); U1.sz[q] += U1.sz[p];
		vector < pair < int , int > > edge;
		for(int x = U1.hd[p] ; x ; x = U1.suf[x])
			for(int y = U1.hd[q] ; y ; y = U1.suf[y]){
				int a = U2.find(x) , b = U2.find(y);
				bool flg = 0; if(U2.sz[a] > U2.sz[b]) swap(a , b);
				for(int p = a ; p && !flg ; p = U2.suf[p])
					for(int q = b ; q && !flg ; q = U2.suf[q])
						if(out[p].find(q) == out[p].end()){edge.emplace_back(make_pair(a , b)); flg = 1;}
			}
		for(auto t : edge){
			if(U2.find(t.first) == U2.find(t.second)) continue;
			int a = U2.find(t.first) , b = U2.find(t.second); if(U2.sz[a] > U2.sz[b]) swap(a , b);
			mdf.emplace_back(&U2.fa[a] , a); U2.fa[a] = b; mdf.emplace_back(&U2.sz[b] , U2.sz[b]); U2.sz[b] += U2.sz[a];
			int q = U2.tl[b]; mdf.emplace_back(&U2.suf[q] , 0); U2.suf[q] = a; mdf.emplace_back(&U2.tl[b] , q); U2.tl[b] = U2.tl[a];}
		static bool vis[_]; vector < int > lft;
		for(int x = U1.hd[p] ; x ; x = U1.suf[x]){int t = U2.find(x); if(!vis[t]){vis[t] = 1; lft.emplace_back(t);}}
		for(int x = U1.hd[q] ; x ; x = U1.suf[x]){int t = U2.find(x); if(!vis[t]){vis[t] = 1; lft.emplace_back(t);}}
		for(auto t : lft) vis[t] = 0;
		lft.emplace_back(0); for(int i = 0 ; i + 1 < lft.size() ; ++i){mdf.emplace_back(&U1.suf[lft[i]] , U1.suf[lft[i]]); U1.suf[lft[i]] = lft[i + 1];}
		mdf.emplace_back(&U1.hd[q] , U1.hd[q]); U1.hd[q] = lft[0];
	}
	vector < qry > QL , QR; for(auto t : pot) (U2.find(t.s) == U2.find(t.t) ? QL : QR).emplace_back(t);
	solve(mid + 1 , R , QR); reverse(mdf.begin() , mdf.end()); for(auto t : mdf) *t.first = t.second;
	solve(L , mid , QL);
}

int main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N >> M; pot1.clear(); pot2.clear(); for(int i = 1 ; i <= N ; ++i) out[i].clear();
		U1.init(); U2.init(); for(int i = 1 ; i <= M ; ++i){qry P; cin >> P.s >> P.t >> P.c; P.id = i; out[P.s].insert(P.t); out[P.t].insert(P.s); pot1.push_back(P); pot2.push_back(P);}
		sort(pot2.begin() , pot2.end() , [&](qry p , qry q){return p.c < q.c;});
		solve(0 , M - 1 , pot1); for(int i = 1 ; i <= M ; ++i) cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}
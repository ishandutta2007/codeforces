#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; vector < int > nxt[_]; int N , K , dep[_] , mxd[_] , son[_];
void dfs1(int x , int p){
	dep[x] = dep[p] + 1; mxd[x] = dep[x]; son[x] = x;
	for(auto t : nxt[x])
		if(t != p){
			dfs1(t , x);
			if(mxd[t] > mxd[x]){mxd[x] = mxd[t]; son[x] = t;}
		}
}

vector < int > comp;
void dfs2(int x , int p){
	if(son[p] != x) comp.push_back(mxd[x] - dep[x] + 1);
	for(auto t : nxt[x]) if(t != p) dfs2(t , x);
}

int main(){
	ios::sync_with_stdio(0); cin >> N >> K;
	for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	dfs1(1 , 0); dfs2(1 , 0); sort(comp.begin() , comp.end()); reverse(comp.begin() , comp.end());
	if(comp.size() <= K)
		if(comp.size() > N / 2) cout << 1ll * comp.size() * (N - comp.size());
		else if(K <= N / 2) cout << 1ll * K * (N - K);
		else cout << 1ll * (N / 2) * (N - N / 2);
	else{
		int l = 0; for(int i = 0 ; i < K ; ++i) l += comp[i] - 1;
		int r = N;
		while(l < r){
			int mid = (l + r) >> 1;
			long long vl = 1ll * mid * (K - (N - mid - K)) , vr = 1ll * (mid + 1) * (K - (N - mid - 1 - K));
			vl <= vr ? r = mid : l = mid + 1;
		}
		cout << 1ll * l * (K - (N - l - K));
	}
	return 0;
}
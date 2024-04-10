#include<bits/stdc++.h>
using namespace std;

const int _ = 2e5 + 7; int T , N , fa[_] , dep[_]; vector < int > nxt[_]; int ans[_]; set < pair < int , int > > node; set < int > ban;
void dfs(int x , int p){fa[x] = p; dep[x] = dep[p] + 1; for(auto t : nxt[x]) if(t != p) dfs(t , x);}

int main(){
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
		dfs(1 , 0); for(int i = 1 ; i <= N ; ++i) node.insert(make_pair(-dep[i] , i));
		int cnt = N , pre = 1; while(2 * pre <= N) pre *= 2;
		while(cnt){
			ban.clear(); auto t = node.begin();
			while(t != node.end()){
				if(ban.find(t->second) != ban.end()) ++t; else{ans[t->second] = cnt--; ban.insert(fa[t->second]); node.erase(t++);}
				if(cnt == pre - 1){pre >>= 1; break;}
			}
		}
		for(int i = 1 ; i <= N ; ++i){cout << ans[i] << ' '; nxt[i].clear();}
		cout << endl;
	}
	return 0;
}
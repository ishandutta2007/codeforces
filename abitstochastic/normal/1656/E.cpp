#include<bits/stdc++.h>
using namespace std;

vector < int > pot[100003]; int ans[100003];
void dfs(int x , int p , int v){
	ans[x] = v * (pot[x].size());
	for(auto t : pot[x]) if(t != p) dfs(t , x , -v);
}

int main(){
	int T; cin >> T;
	while(T--){
		int N; cin >> N; for(int i = 1 ; i <= N ; ++i) pot[i].clear();
		for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; pot[p].push_back(q); pot[q].push_back(p);}
		int rt = 1; while(pot[rt].size() == 1) ++rt;
		dfs(rt , 0 , 1); for(int i = 1 ; i <= N ; ++i) cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}
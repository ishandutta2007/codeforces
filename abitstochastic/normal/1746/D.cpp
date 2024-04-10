#include<bits/stdc++.h>
using namespace std;

#define int long long
int T , N , K , s[200003] , ans; vector < int > val , ch[200003];

int dfs(int x , int cnt){
	if(ch[x].empty()){ans += cnt * s[x]; return s[x];}
	int c = ch[x].size() , num = cnt / c , lft = cnt % c; vector < int > v;
	ans += s[x] * cnt; for(auto t : ch[x]) v.push_back(dfs(t , num));
	sort(v.begin() , v.end() , [&](int p , int q){return p > q;});
	for(int i = 0 ; i < lft ; ++i) ans += v[i];
	return v[lft] + s[x];
}

signed main(){
	for(cin >> T ; T ; --T){
		cin >> N >> K; ans = 0; for(int i = 1 ; i <= N ; ++i) ch[i].clear();
		for(int i = 2 ; i <= N ; ++i){int p; cin >> p; ch[p].push_back(i);}
		for(int i = 1 ; i <= N ; ++i) cin >> s[i];
		dfs(1 , K); cout << ans << endl;
	}
	return 0;
}
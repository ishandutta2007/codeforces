#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 2e5 + 7; vector < int > ch[_]; int L[_] , R[_] , T , N , cnt = 0;

int dfs(int x){
	int sum = 0; for(auto t : ch[x]) sum += dfs(t);
	if(sum < L[x]){sum = R[x]; ++cnt;}
	return min(sum , R[x]);
}

signed main(){
	ios::sync_with_stdio(0);
	for(cin >> T ; T ; --T){
		cin >> N; for(int i = 1 ; i <= N ; ++i){ch[i].clear();}
		for(int i = 2 ; i <= N ; ++i){int p; cin >> p; ch[p].push_back(i);}
		for(int i = 1 ; i <= N ; ++i) cin >> L[i] >> R[i];
		cnt = 0; dfs(1); cout << cnt << '\n';
	}
	
	return 0;
}
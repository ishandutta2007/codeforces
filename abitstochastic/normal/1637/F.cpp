#include<bits/stdc++.h>
using namespace std;

#define int long long
const int _ = 2e5 + 7; vector < int > ch[_]; int N , H[_] , ans;
int dfs(int x , int p){
	vector < int > nxt; nxt.push_back(0);
	for(auto t : ch[x]) if(t != p){nxt.push_back(dfs(t , x));}
	sort(nxt.begin() , nxt.end()); int mx = max(nxt.back() , H[x]);
	ans += max(0ll , H[x] - nxt.back()); nxt.pop_back();
	if(!p){ans += max(0ll , H[x] - nxt.back()); nxt.pop_back();}
	return mx;
}

signed main(){
	ios::sync_with_stdio(0); cin >> N; int mx = 0;
	for(int i = 1 ; i <= N ; ++i){cin >> H[i]; mx = H[i] > H[mx] ? i : mx;}
	for(int i = 1 ; i < N ; ++i){int p , q; cin >> p >> q; ch[p].push_back(q); ch[q].push_back(p);}
	dfs(mx , 0); cout << ans; return 0;
}
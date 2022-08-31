#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int _ = 1003; int X[_] , cost[_] , ans[_] , N , M , id[_]; vector < int > nxt[_];

namespace flow{
	const int _ = 1e5 + 7 , __ = 5e6 + 7;
	struct Edge{int end , upEd; ll f;}Ed[__]; int head[_] , cntEd , S , T;
	void addEd(int a , int b , ll c){Ed[++cntEd] = (Edge){b , head[a] , c}; head[a] = cntEd;}
	void addE(int a , int b , ll c){addEd(a , b , c); addEd(b , a , 0);}
	void clr(){memset(head , 0 , sizeof(int) * (T + 1)); S = T = 0; cntEd = 1;}

	int cur[_] , dep[_]; queue < int > q;
	bool bfs(){
		while(!q.empty()) q.pop();
		memset(dep , 0 , sizeof(int) * (T + 1));
		dep[S] = 1; q.push(S);
		while(!q.empty()){
			int t = q.front(); q.pop();
			for(int i = head[t] ; i ; i = Ed[i].upEd)
				if(Ed[i].f && !dep[Ed[i].end]){
					dep[Ed[i].end] = dep[t] + 1; q.push(Ed[i].end);
					if(Ed[i].end == T){memcpy(cur , head , sizeof(int) * (T + 1)); return 1;}
				}
		}
		return 0;
	}

	ll dfs(int x , ll f){
		if(x == T) return f;
		ll sum = 0;
		for(int &i = cur[x] ; i ; i = Ed[i].upEd)
			if(Ed[i].f && dep[Ed[i].end] == dep[x] + 1){
				ll t = dfs(Ed[i].end , min(Ed[i].f , f - sum));
				Ed[i].f -= t; Ed[i ^ 1].f += t; sum += t;
				if(sum == f) break;
			}
		return sum;
	}
}using flow::addE;

void divide(int l , int r , vector < int > p){
	if(p.empty()) return;
	if(l == r){for(auto t : p) ans[t] = l; return;}
	flow::clr(); flow::T = p.size() + 1;  int mid = (l + r) >> 1;
	for(int i = 0 ; i < p.size() ; ++i) id[p[i]] = i + 1;
	for(int i = 0 ; i < p.size() ; ++i){
		if(cost[p[i]] > mid) addE(i + 1 , flow::T , 1);
		else addE(0 , i + 1 , 1);
		for(auto t : nxt[p[i]]) if(id[t]) addE(id[t] , i + 1 , 1e9);
	}
	while(flow::bfs()) flow::dfs(0 , 1e9);
	vector < int > L , R;
	for(int i = 0 ; i < p.size() ; ++i){id[p[i]] = 0; if(flow::dep[i + 1]) L.push_back(p[i]); else R.push_back(p[i]);}
	divide(l , mid , L); divide(mid + 1 , r , R);
}

int main(){
	cin >> N >> M; for(int i = 1 ; i <= N ; ++i) cin >> cost[i];
	for(int i = 1 ; i <= M ; ++i){int p , q; cin >> p >> q; nxt[p].push_back(q);}
	vector < int > pot; for(int i = 1 ; i <= N ; ++i) pot.push_back(i);
	divide(-1e9 , 1e9 , pot); for(int i = 1 ; i <= N ; ++i) cout << ans[i] << ' ';
	return 0;
}
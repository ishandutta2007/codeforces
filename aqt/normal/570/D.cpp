
// Problem : D. Tree Requests
// Contest : Codeforces - Codeforces Round #316 (Div. 2)
// URL : https://codeforces.com/contest/570/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
vector<int> graph[500005];
int bit[1000005];
int val[500005];
int lft[500005];
int rht[500005];
int dep[500005];
vector<int> lst[500005];
vector<int> qu[500005];
int x[500005];
bool ans[500005];
int t;

void dfs(int n){
	lft[n] = ++t;
	lst[dep[n]].push_back(n);
	for(int e : graph[n]){
		dep[e] = dep[n] + 1;
		dfs(e);
	}
	rht[n] = ++t;
}

void upd(int n, int v){
	while(n <= 2*N){
		bit[n] ^= v;
		n += n&-n;
	}
}

int query(int n){
	int ret = 0;
	while(n){
		ret ^= bit[n];
		n -= n&-n;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 2; i<=N; i++){
		int p;
		cin >> p;
		graph[p].push_back(i);
	}
	for(int i = 1; i<=N; i++){
		char c;
		cin >> c;
		val[i] = (1<<(c-'a'));
	}
	dep[1] = 1;
	dfs(1);
	for(int q = 1; q<=Q; q++){
		cin >> x[q];
		int d;
		cin >> d;
		qu[d].push_back(q);
	}
	for(int d = 1; d<=N; d++){
		for(int n : lst[d]){
			upd(rht[n], val[n]);
		}
		for(int q : qu[d]){
			ans[q] = (__builtin_popcount(query(rht[x[q]]) ^ query(lft[x[q]])) <= 1);
		}
		for(int n : lst[d]){
			upd(rht[n], val[n]);
		}
	}
	for(int q = 1; q<=Q; q++){
		cout << (ans[q] ? "Yes\n" : "No\n");
	}
}
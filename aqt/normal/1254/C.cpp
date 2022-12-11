
// Problem : C. Point Ordering
// Contest : Codeforces - Codeforces Round #601 (Div. 1)
// URL : https://codeforces.com/contest/1254/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> ans = {0, 1};
vector<pair<long long, int>> v;
long long dist[2005];
int typ[2005];
bool tkn[2005];

long long query(int t, int i, int j, int k){
	assert(i != j && i != k && j != k);
	cout << t << " " << i << " " << j << " " << k << endl;
	long long n;
	cin >> n;
	return n;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	int nxt = 2;
	for(int i= 3; i<=N; i++){
		if(query(2, 1, nxt, i) == -1){
			nxt = i;
		}
	}
	//assert(nxt == 3);
	ans.push_back(nxt);
	for(int i = 2; i<=N; i++){
		if(i != nxt){
			dist[i] = query(1, 1, nxt, i);
			v.emplace_back(dist[i], i);
		}
	}
	sort(v.begin(), v.end());
	int far = v.back().second;
	for(int i = 2; i<=N; i++){
		if(i != far && i != nxt){
			typ[i] = query(2, 1, far, i);
		}
	}
	for(auto p : v){
		if(typ[p.second] == -1){
			ans.push_back(p.second);
		}
	}
	ans.push_back(far);
	reverse(v.begin(), v.end());
	for(auto p : v){
		if(typ[p.second] == 1){
			ans.push_back(p.second);
		}
	}
	//Graham Scan Failed (2N Queries at most not N)
	/*
	for(auto p : v){
		int n = p.second;
		while(ans.back() != nxt && query(2, ans[ans.size()-2], ans.back(), n) == -1){
			assert(ans.back() != nxt);
			ans.pop_back();
		}
		ans.push_back(n);
	}
	for(auto n : ans){
		tkn[n] = 1;
	}
	for(int i = v.size()-1; i>=0; i--){
		if(!tkn[v[i].second]){
			ans.push_back(v[i].second);
		}
	}
	*/
	for(int n : ans){
		cout << n << " ";
	}
}
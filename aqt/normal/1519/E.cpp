
// Problem : E. Off by One
// Contest : Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1519/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
map<pair<long long, long long>, vector<pair<pair<long long, long long>, int>>> graph;
set<pair<long long, long long>> vis;
vector<pair<int, int>> ans;
bool tkn[200005];

void dfs(pair<long long, long long> n, int p){
	//cout << n.first << " " << n.second << " " << p << endl;
	vis.insert(n);
	vector<int> lst;
	if(p){
		lst.emplace_back(p);
	}
	//cout << "here" << endl;
	for(auto e : graph[n]){
		if(e.second != p){
			if(!vis.count(e.first)){
				dfs(e.first, e.second);
			}		
			if(!tkn[e.second]){
				//cout << e.second << endl;
				lst.emplace_back(e.second);
			}
		}
	}
	//cout << "yo :" << n.first << " " << n.second << " " << p << endl;
	for(int i = (int) (lst.size()) - 1; i > 0; i -= 2){
		ans.emplace_back(lst[i], lst[i - 1]);
		tkn[lst[i]] = tkn[lst[i - 1]] = 1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; i++){
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		long long x1 = d * (a + b);
		long long y1 = c * b;
		long long g1 = __gcd(x1, y1);
		x1 /= g1;
		y1 /= g1;
		long long y2 = b * (c + d);
		long long x2 = a * d;
		long long g2 = __gcd(x2, y2);
		x2 /= g2;
		y2 /= g2;
		pair<long long, long long> p = make_pair(x1, y1);
		pair<long long, long long> q = make_pair(x2, y2);
		graph[p].emplace_back(q, i);
		graph[q].emplace_back(p, i);
	}
	for(auto p : graph){
		if(!vis.count(p.first)){
			dfs(p.first, 0);
		}
	}
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
}
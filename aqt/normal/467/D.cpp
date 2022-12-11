
// Problem : D. Fedor and Essay
// Contest : Codeforces - Codeforces Round #267 (Div. 2)
// URL : https://codeforces.com/contest/467/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, C;
vector<string> essay;
map<string, vector<string>> graph;
map<string, int> low, dfn, cmp;
vector<string> stk;
pair<int, int> dp[500005];
vector<int> cgraph[500005];
bool done[500005];
set<string> instk;
int t;

string conversion(string s){
	for(char &c : s){
		if(c >= 'A' && c <= 'Z'){
			c += 'a' - 'A';
		}
	}
	return s;
}

void dfs(string s){
	//assert(s.size());
	low[s] = dfn[s] = ++t;
	stk.push_back(s);
	instk.insert(s);
	for(string e : graph[s]){
		if(!dfn[e]){
			dfs(e);
			low[s] = min(low[s], low[e]);
		}
		else if(instk.count(e)){
			low[s] = min(low[s], low[e]);
		}
	}
	//cout << s << " " << low[s] << " " << dfn[s] << "\n";
	if(low[s] == dfn[s]){
		string c;
		C++;
		dp[C] = make_pair(INT_MAX/2, 0);
		do{
			c = stk.back();
			stk.pop_back();
			cmp[c] = C;
			int cnt = 0;
			for(char k : c){
				cnt += (k == 'r');
			}
			dp[C] = min(dp[C], make_pair(cnt, (int) c.size()));
			/*
			for(string e : graph[s]){
				if(!cmp[e]){
					//cout << e << " " << low[e] << " " << dfn[e] << endl;
				}
				cgraph[C].push_back(cmp[e]);
			}
			*/
			instk.erase(c);
		}
		while(c != s);
		//cout << C << " " << s << "\n";
	}
	//cout << s << " " << low[s] << " " << dfn[s] << "\n";
}

pair<int, int> solve(int n){
	if(done[n]){
		return dp[n];
	}
	done[n] = 1;
	for(int e : cgraph[n]){
		dp[n] = min(dp[n], solve(e));
	}
	//cout << n << " " << dp[n].second << "\n";
	return dp[n];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		string s;
		cin >> s;
		essay.push_back(conversion(s));
	}
	cin >> M;
	while(M--){
		string a, b;
		cin >> a >> b;
		a = conversion(a), b = conversion(b);
		graph[a].push_back(b);
	}
	for(auto p : graph){
		//cout << p.first << "\n";
		if(!dfn[p.first]){
			dfs(p.first);
		}
		//cout << p.first << " " << cmp[p.first] << "\n";
	}
	for(auto p : graph){
		for(auto e : p.second){
			cgraph[cmp[p.first]].push_back(cmp[e]);
		}
	}
	pair<long long, long long> ans = {0, 0};
	for(auto s : essay){
		int c = cmp[s];
		if(c){
			auto p = solve(c);
			ans.first += p.first;
			ans.second += p.second;
			//assert(p.second);
			//cout << s << " " << c << " " << p.first << " " << p.second << "\n";
		}
		else{
			int cnt = 0;
			for(int k : s){
				cnt += (k == 'r');
			}
			ans.first += cnt;
			ans.second += s.size();
			assert(s.size());
		}
	}
	cout << ans.first << " " << ans.second << "\n";
}
#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, s;
int in[N];
int last[N];
int sorted[N];
set <int> place[N];
set <int> value[N];

int cnt;
map <int, int> M;

int dir[N];
bool vis[N];
vector <int> cur;

void solve(int c){
	if(place[c].size() == 0)
		return;

	int v1 = *place[c].begin(), v2 = *value[c].begin();
	place[c].erase(v1);
	value[c].erase(v2);
	
	int st = v1;
	dir[v1] = v2;
	
	if(last[in[st]] > 0)
		swap(dir[st], dir[last[in[st]]]);
	last[in[st]] = st;

	vector <int> cycle;
	cycle.push_back(v1);

	while(v2 != st){
		v1 = v2;
		last[in[v1]] = v1;
		cycle.push_back(v1);
		
		c = in[v1];
		place[c].erase(v1);
		
		v2 = *value[c].begin();
		value[c].erase(v2);
		dir[v1] = v2;
	}
	
	for(int v: cycle)
		if(place[in[v]].size())
			solve(in[v]);
}

void dfs(int u){
	vis[u] = true;
	cur.push_back(u);
	
	if(!vis[dir[u]])
		dfs(dir[u]);
}

int main(){
	scanf("%d %d", &n, &s);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &in[i]);
		sorted[i] = in[i];
	}
	
	int inc = 0;
	sort(sorted + 1, sorted + n + 1);

	for(int i = 1; i <= n; ++i){
		if(in[i] != sorted[i])
			++inc;
		
		if(!M.count(sorted[i]))
			M[sorted[i]] = ++cnt;
	}

	if(inc > s){
		puts("-1");
		return 0;
	}
	
	for(int i = 1; i <= n; ++i){
		in[i] = M[in[i]];
		sorted[i] = M[sorted[i]];
	}
	
	for(int i = 1; i <= n; ++i)
		if(in[i] != sorted[i]){
			place[in[i]].insert(i);
			value[sorted[i]].insert(i);
		}
	
	vector <vector <int> > ans;
	for(int i = 1; i <= n; ++i){
		if(place[i].size() == 0)
			continue;
		solve(i);
	}
	
	for(int i = 1; i <= n; ++i)
		vis[i] = in[i] == sorted[i];
	
	for(int i = 1; i <= n; ++i)
		if(!vis[i]){
			cur.clear();
			dfs(i);
			ans.push_back(cur);
		}
	
	s -= inc;
	if(s >= 3 && ans.size() >= 3){
		s = min(s, (int)ans.size());
		vector <int> help, help2;
		
		while(s--){
			for(auto v: ans.back())
				help.push_back(v);

			help2.push_back(ans.back()[0]);
			ans.pop_back();
		}
		
		reverse(help2.begin(), help2.end());
		ans.push_back(help);
		ans.push_back(help2);
	}
	
	printf("%d\n", (int)ans.size());
	for(auto V: ans){
		printf("%d\n", (int)V.size());
		for(auto v: V)
			printf("%d ", v);
		puts("");
	}

	return 0;
}
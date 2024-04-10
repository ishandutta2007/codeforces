#include <bits/stdc++.h>

using namespace std;

typedef long double T;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 5007;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n, m;
int _n[3];
vector <int> G[N];

int cnt_id;
int dp[N];

bool type[N];
vector <int> who[2][N];

int ans[N];
bool vis[N];
int color[N];

void no(){
	puts("NO");
	exit(0);
}

void dfs(int u){
	vis[u] = true;
	who[color[u]][cnt_id].push_back(u);

	for(auto v: G[u])
		if(!vis[v]){
			color[v] = color[u] ^ 1;
			dfs(v);
		}
		else if(color[v] == color[u])
			no();
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < 3; ++i)
		scanf("%d", &_n[i]);
	
	for(int i = 1; i <= m; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	vector <PII> vals;
	for(int i = 1; i <= n; ++i)
		if(!vis[i]){
			cnt_id++;
			dfs(i);

			if(who[0][cnt_id].size() > who[1][cnt_id].size())
				swap(who[0][cnt_id], who[1][cnt_id]);

			_n[1] -= who[0][cnt_id].size();
			vals.push_back({who[1][cnt_id].size() - who[0][cnt_id].size(), cnt_id});
		}
	
	if(_n[1] < 0)
		no();
	
	for(int i = 1; i <= n; ++i)
		dp[i] = -1;	
	dp[0] = 0;

	for(auto v: vals)
		for(int i = n - v.st; i >= 0; --i)
			if(dp[i] != -1 && dp[i + v.st] == -1)
				dp[i + v.st] = v.nd;
	
	if(dp[_n[1]] == -1)
		no();
	
	int cur = _n[1];
	while(cur){
		type[dp[cur]] = true;
		cur -= who[1][dp[cur]].size() - who[0][dp[cur]].size();
	}
	
	vector <int> Left, Right;
	for(int i = 1; i <= cnt_id; ++i){
		for(auto v: who[type[i]][i])
			Left.push_back(v);
		for(auto v: who[type[i] ^ 1][i])
			Right.push_back(v);
	}
	
	for(auto v: Left)
		ans[v] = 2;
	
	for(auto v: Right)
		if(_n[0]){
			ans[v] = 1;
			--_n[0];
		}
		else
			ans[v] = 3;
	
	puts("YES");
	for(int i = 1; i <= n; ++i)
		printf("%c", ans[i] + '0');
	puts("");
	return 0;
}
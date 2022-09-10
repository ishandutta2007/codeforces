#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PII pair <int, int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back

const int mxn = 1e5 + 7;
const int INF = 1e9 + 7;
const int MX = 1e9 + 9;

int n, m;
int licz = 0;
int war[mxn];
vector <int> V[mxn];
int mn[mxn][2];
int mx[mxn][2];

void dfs(int u){
	mn[licz][war[u] - 1] = min(mn[licz][war[u] - 1], u);
	mx[licz][war[u] - 1] = max(mx[licz][war[u] - 1], u);
	for(int i = 0; i < V[u].size(); ++i)
		if(war[V[u][i]] == 0){
			war[V[u][i]] = war[u] ^ 3;
			dfs(V[u][i]);
		}
}

bool check(){
	for(int i = 1; i <= n; ++i)
		for(int j = 0; j < V[i].size(); ++j)
			if(war[i] == war[V[i][j]])
				return false;
	return true;
}

int main(){
	scanf("%d %d", &n, &m);
	if(m == 0){
		printf("%d\n", n - 1);
		return 0;
	}
	
	for(int i = 1; i <= m; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a == b)
			continue;
		V[a].pb(b);
		V[b].pb(a);
	}
	
	int result = 0;
	for(int i = 1; i <= n; ++i)
		if(war[i] == 0){
			war[i] = 1;
			++licz;
			mn[licz][0] = mn[licz][1] = INF;
			dfs(i);
			if(mx[licz][0] > mx[licz][1]){
				swap(mx[licz][1], mx[licz][0]);
				swap(mn[licz][1], mn[licz][0]);
			}
		}
	
	if(!check()){
		puts("0");
		return 0;
	}
	
	int MN = INF;
	int MX = 0;
	for(int i = 1; i <= licz; ++i){
//		printf("%d %d %d %d\n", mn[i][0], mx[i][0], mn[i][1], mx[i][1]);
		if(mx[i][0] == 0)
			continue;
		MN = min(MN, mn[i][1]);
		MX = max(MX, mx[i][0]);
	}

	printf("%d\n", max(MN - MX, 0));
	return 0;
}
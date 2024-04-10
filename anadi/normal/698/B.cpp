#include <bits/stdc++.h>

using namespace std;

typedef double LD;
typedef long long int LL;

#define mp make_pair
#define st first
#define nd second
#define PII pair <int, int>
#define pb push_back
#define PLL pair <LL, LL>
#define pb push_back

const int INF = 1e9 + 9;
const LL MX = 1e9 + 7LL;
const int mxn = 2e5 + 7;

int n;
int root;
int rep[mxn];
bool ok[mxn];
int res = 0;
vector <int> V[mxn];
int father[mxn];
bool visited[mxn];

int Find(int a){
	if(rep[a] == a)
		return a;
	return rep[a] = Find(rep[a]);
}

bool Union(int a, int b){
	int fa = Find(a);
	int fb = Find(b);
	if(fa == fb)
		return false;
	rep[fa] = fb;
	return true;
}

void dfs(int u){
	visited[u] = true;
	if(ok[u]){
		++res;
		father[u] = root;
	}
		
	for(int i = 0; i < V[u].size(); ++i)
		if(!visited[V[u][i]])
			dfs(V[u][i]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		rep[i] = i;
	
	for(int i = 1; i <= n; ++i){
		int a;
		scanf("%d", &a);
		father[i] = a;
		if(a == i){
			if(root != 0)
				ok[i] = true;
			else
				root = i;
			continue;
		}
		
		if(!Union(i, a))
			ok[i] = true;
		else{
			V[i].pb(a);
			V[a].pb(i);
		}
	}
	
	if(root == 0){
		for(int i = 1; i <= n; ++i)
			if(ok[i]){
				root = i;
				break;
			}
	}
	
	for(int i = 1; i <= n; ++i)
		if(!visited[i])
			dfs(i);
	
	printf("%d\n", res);
	for(int i = 1; i <= n; ++i)
		printf("%d ", father[i]);
	return 0;
}
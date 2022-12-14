#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
const ll inf = (1ll << 63), maxn = 2e5 + 100;
vector <int> v[maxn];
bool visited[maxn], mark[maxn];
int par[maxn];

void dfs (int u, int p){
	visited[u] = 1;
	par[u] = p;
	for (auto w : v[u])
		if (!visited[w])
			dfs (w, u);
}

int main(){
	int n, r1, r2;
	cin >> n >> r1 >> r2;
	for (int i = 1; i <= n; i++){
		if (i == r1)
			continue;
		int p;
		cin >> p;
		v[p].PB(i);
		v[i].PB(p);
	}
	dfs (r2, -1);
	for (int i = 1; i <= n; i++){
		if (i == r2)
			continue;
		cout << par[i] << " ";
	}
}
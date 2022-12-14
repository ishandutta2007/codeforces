#include <iostream>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 100;
vector <int> v[maxn];
bool visited[maxn];
int edg, nod;

void dfs (int u){
	visited[u] = 1;
	nod ++;
	for (auto w : v[u]){
		edg ++;
		if (!visited[w])
			dfs (w);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			nod = 0;
			edg = 0;
			dfs (i);
			if (edg / 2 != 1ll * nod * (nod - 1) / 2)
				return cout << "NO" << endl, 0;
		}
	}
	cout << "YES" << endl;
}
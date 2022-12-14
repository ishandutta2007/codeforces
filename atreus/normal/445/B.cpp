#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 1e4 + 100;
vector <int> v[maxn];
int a[maxn], cnt;
bool visited[maxn];

void dfs (int u){
	cnt ++;
	visited[u] = 1;
	for (auto w : v[u])
		if (!visited[w])
			dfs (w);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	ll ans = 1;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			cnt = -1;
			dfs (i);
			ans *= (1ll << cnt);
		}
	}
	cout << ans << endl;
}
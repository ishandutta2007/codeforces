#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <set>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#define F first
#define S second
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 1e5 + 500;
vector <int> v[maxn];
int h[maxn], eve, odd;
bool ans, visited[maxn];

void dfs (int u){
	visited[u] = 1;
	if (h[u] % 2 == 0)
		eve ++;
	else
		odd ++;
	for (auto w : v[u])
		if (!visited[w])
			dfs (w);
}

void check_ans0(int u, int height){
	visited[u] = 1;
	h[u] = height;
	for (auto w : v[u]){
		if (!visited[w])
			check_ans0 (w, height + 1);
		if (h[w] % 2 == h[u] % 2)
			ans = 1;
	}
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
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			check_ans0(i, 0);
	if (ans)
		return cout << 0 << " " << ans << endl, 0;
	bool ansis1 = false;
	memset (visited, 0, sizeof visited);
	ll cnt = 0;
	for (int i = 1; i <= n; i++)
		if (v[i].size() >= 2)
			ansis1 = 1;
	if (ansis1){
		for (int i = 1; i <= n; i++){
			if (!visited[i]){
				dfs (i);
				cnt += (1ll * eve * (eve - 1) / 2) + (1ll * odd * (odd - 1) / 2);
				eve = 0;
				odd = 0;
			}
		}
		return cout << 1 << " " << cnt << endl, 0;
	}
	if (m > 0){
		return cout << 2 << " " << 1ll * m * (n - 2) << endl, 0;
	}
	cout << 3 << " " << 1ll * n * (n - 1) * (n - 2) / 6 << endl;
}
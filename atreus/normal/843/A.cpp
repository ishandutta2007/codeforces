#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#include <unordered_map>

#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 1e5 + 100;
pair <int, int> p[maxn];
vector <int> v[maxn], ans;
bool mark[maxn];

void dfs(int u){
	mark[u] = 1;
	ans.PB(u);
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i];
		if (!mark[w])
			dfs (w);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i].F;
		p[i].S = i;
	}
	sort (p + 1, p + n + 1);
	for (int i = 1; i <= n; i++){
		v[i].PB(p[i].S);
		v[p[i].S].PB(i);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		if (!mark[i]){
			cnt ++;
			dfs (i);
		}
	}
	memset (mark, 0, sizeof mark);
	cout << cnt << endl;
	for (int i = 1; i <= n; i++){
		ans.clear();
		if (!mark[i]){
			dfs (i);
			cout << ans.size() << " ";
			for (int j = 0; j < ans.size(); j++)
				cout << ans[j] << " ";
			cout << endl;
		}
	}
}
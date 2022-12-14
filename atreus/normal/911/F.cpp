#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>
#include <cmath>

#define MP make_pair
#define F first
#define S second
#define PB push_back

using namespace std;

const int maxn = 2e5 + 100;
vector <int> v[maxn];
bool mark1[maxn], mark[maxn];
int q[3];
int d[3][maxn], par[maxn];

void print_ans(int u){
	mark1[u] = 1;
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i];
		if (!mark1[w])
			print_ans(w);
	}
	if (!mark[u]){
		if (d[1][u] > d[2][u])
			cout << u << " " << q[1] << " " << u << endl;
		else
			cout << u << " " << q[2] << " " << u << endl;
	}
}

void dfs (int u, int h, int p){
	mark[u] = 1;
	d[p][u] = h;
	for (int i = 0; i < v[u].size(); i++){
		int w = v[u][i];
		if (!mark[w]){
			par[w] = u;
			dfs (w, h + 1, p);
		}
	}
}

int main () {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB(w);
		v[w].PB(u);
	}
	dfs (1, 0, 1);
	memset (mark, 0, sizeof mark);
	memset (par, 0, sizeof par);
	int mxx = 0;
	for (int i = 1; i <= n; i++){
		if (mxx < d[1][i]){
			mxx = d[1][i];
			q[1] = i;
		}
	}
	memset (d[1], 0, sizeof d[1]);
	dfs (q[1], 0, 1);
	memset (mark, 0, sizeof mark);
	mxx = 0;
	for (int i = 1; i <= n; i++){
		if (mxx < d[1][i]){
			mxx = d[1][i];
			q[2] = i;
		}
	}
	dfs (q[2], 0, 2);
	memset (mark, 0, sizeof mark);
	int idx = q[1];
	mark[q[2]] = 1;
	while (idx != q[2]){
		mark[idx] = 1;
		idx = par[idx];
	}
	long long ans = 0, cnt = 0;
	for (int i = 1; i <= n; i++){
		if (!mark[i]){
			ans += max(d[1][i], d[2][i]);
		}
		else
			cnt ++;
	}
	ans += cnt * (cnt - 1) / 2;
	cout << ans << endl;
	print_ans(q[1]);
	idx = q[1];
	while (idx != q[2]){
		cout << idx << " " << q[2] << " " << idx << endl;
		idx = par[idx];
	}
}
/**
 *    author:  Atreus
 *    created: 18.01.2019 13:47:30
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 3000 + 10;

struct edge{
	int v;
	int u;
	int w;
	bool operator < (const edge &other) const{
		return w < other.w;
	}
};

edge e[maxn];
int n;
ll sum = 0;
ll x[maxn], y[maxn];

bool check(){
	for (int i = 1; i <= n; i++)
		if (x[i] != 0)
			if (sum - y[i] < x[i])
				return 1;
	return 0;
}

int par[maxn];

int get_par(int v){
	return par[v] < 0 ? v : get_par(par[v]);
}

void merge(int v, int u){
	x[v] += x[u];
	y[v] += y[u];
	x[u] = 0;
	y[u] = 0;
	par[u] = v;
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		cin >> e[i].v >> e[i].u >> e[i].w;
	sort(e, e + n - 1);
	for (int v = 1; v <= n; v++){
		cin >> x[v];
		y[v] = 1;
		sum += x[v];
	}
	for (int i = 0; i < n - 1; i++){
		merge(get_par(e[i].v), get_par(e[i].u));
		if (check())
			return cout << e[i].w << endl, 0;
	}
	cout << e[n - 2].w << endl;
}
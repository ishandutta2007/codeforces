#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 5000 + 50;
const int maxm = 1e5 + 50;

int n, m;
int par[maxn];

struct edge{
	int v;
	int u;
	int w;
	int idx;
	bool operator < (const edge & oth) const{
		return make_pair(w, idx) < make_pair(oth.w, oth.idx);
	}
};

edge e[maxm], e2[maxm];

int get_par(int v){
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}

bool merge(int v, int u){
	if ((v = get_par(v)) == (u = get_par(u)))
		return 0;
	par[v] = u;
	return 1;
}

int check(int x){
	memset(par, -1, sizeof par);
	for (int i = 0; i < m; i++)
		if (e[i].v == 1 or e[i].u == 1)
			e[i].w += x;
	sort(e, e + m);
	int cnt = 0, connected = 0;
	for (int i = 0; i < m; i++){
		if (merge(e[i].v, e[i].u)){
			cnt += (e[i].v == 1) + (e[i].u == 1);
			connected ++;
		}
	}
	if (connected != n - 1){
		cout << -1 << endl;
		exit(0);
	}
	for (int i = 0; i < m; i++)
		if (e[i].v == 1 or e[i].u == 1)
			e[i].w -= x;
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	int k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		cin >> e[i].v >> e[i].u >> e[i].w;
		e[i].w *= 2;
		e[i].idx = i + 1;
	}
	sort(e, e + m);
	int lo = -200001, hi = 200000 + 1;
	if (check(lo) < k or check(hi) > k)
		return cout << -1 << endl, 0;
	while (hi - lo > 1){
		int mid = (lo + hi) >> 1;
		if (check(mid) <= k)
			hi = mid;
		else
			lo = mid;
	}
	for (int i = 0; i < m; i++)
		if (e[i].v == 1 or e[i].u == 1)
			e[i].w += hi;
	memset(par, -1, sizeof par);
	ll mst = 0;
	vector<int> v;
	sort(e, e + m);
	for (int i = 0; i < m; i++)
		e[i].w += hi;
	for (int i = 0; i < m; i++){
		if (merge(e[i].v, e[i].u)){
			v.push_back(e[i].idx);
			mst += e[i].w;
		}
	}
	cout << n - 1 << endl;
	for (int i = 0; i < n - 1; i++)
		cout << v[i] << " ";
	cout << endl;
}
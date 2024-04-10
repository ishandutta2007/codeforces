/**
 *    author:  Atreus
 *    created: 23.01.2019 19:17
 **/
#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 2e5 + 10;
int par[maxn];
pair<int, pair<int, int> > e[maxn];

int get_par(int v){
	return par[v] < 0 ? v : par[v] = get_par(par[v]);
}

void merge(int v, int u){
	if ((v = get_par(v)) == (u = get_par(u)))
		return;
	par[v] = u;
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(par, -1, sizeof par);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		cin >> e[i].second.first >> e[i].second.second >> e[i].first;
	sort(e, e + m);
	int answer = -n + 1;
	for (int i = 0; i < m; i++){
		int v = e[i].second.first, u = e[i].second.second;
		if (get_par(v) != get_par(u))
			answer ++;
		if (i == m - 1 or e[i].first != e[i + 1].first){
			for (int j = i; j >= 0 and e[j].first == e[i].first; j--){
				merge(e[j].second.first, e[j].second.second);
			}
		}
	}
	cout << answer << endl;
}
#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;

int par[maxn];

int get_par(int v){
	if (par[v] < 0)
		return v;
	return par[v] = get_par(par[v]);
}

void merge(int v, int u){
	v = get_par(v), u = get_par(u);
	par[u] += par[v];
	par[v] = u;
}

pii a[maxn];
bool mark[maxn];
int ans[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a + 1, a + n + 1, greater <pii>());
	
	memset (par, -1, sizeof par);
	int ptr = 1;
	for (int i = 1; i <= n; i++){
		int idx = a[i].S;
		if (mark[idx + 1])
			merge(idx, idx + 1);
		if (mark[idx - 1])
			merge(idx, idx - 1);
		mark[idx] = 1;
		idx = get_par(idx);
		while (ptr <= -par[idx]){
			ans[ptr ++] = a[i].F;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}
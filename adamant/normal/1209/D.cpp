#include<bits/stdc++.h>
 
using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;
int par[maxn], sz[maxn];
int get(int v) {
	return v == par[v] ? v : par[v] = get(par[v]);
}
void uni(int a, int b) {
	a = get(a);
	b = get(b);
	if(a != b) {
		par[a] = b;
		sz[b] += sz[a];
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    iota(par, par + maxn, 0);
    fill(sz, sz + maxn, 1);
    int n, k;
    cin >> n >> k;
    int x[k], y[k];
    int good = 0;
    for(int i = 0; i < k; i++) {
		cin >> x[i] >> y[i];
		uni(x[i] - 1, y[i] - 1);
	}
	for(int i = 0; i < n; i++) {
		if(i == par[i]) {
			good += sz[i] - 1;
		}
	}
	cout << k - good << endl;
	
}
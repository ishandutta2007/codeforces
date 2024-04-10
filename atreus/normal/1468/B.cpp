#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll maxn = 1e6 + 10;
const ll mod = 1e9 + 7;

int a[maxn], b[maxn], ans[maxn], r[maxn];
ll par[maxn];

int get_r(int x){
	return r[x] == 0 ? x : r[x] = get_r(r[x]);
}

ld miangin(int l, int r){
	return 1. * (par[r]-par[l-1]) / (r-l+1);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		par[i] = par[i-1] + a[i];
	}
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	int ptr = m;
	set<pair<ld,int>> S;
	for (int i = 1; i < n; i++)
		S.insert({-a[i],i});
	int maxLen = 0;
	while (!S.empty()){
		while (ptr >= 1 and b[ptr] >= -(*S.begin()).first)
			ans[ptr--] = maxLen;
		int x = (*S.begin()).second;
		int nex = get_r(x);
		S.erase({-miangin(x,nex),x});
		r[nex] = nex+1;
		if (get_r(nex+1) != n){
			S.erase({-miangin(nex+1,get_r(nex+1)),nex+1});
			S.insert({-miangin(x,get_r(x)),x});
		}
		maxLen = max(maxLen, get_r(x)-x);
	}
	while (ptr >= 1)
		ans[ptr--] = n-1;
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " \n"[i == m];
}
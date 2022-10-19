#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
const ll inv2 = 5e8 + 4;
ll qpow(ll b, ll p){
	ll ret = 1LL;
	while(p){
		if(p & 1)
			ret = ret * b % Mod;
		b = b * b % Mod;
		p >>= 1;
	}
	return ret;
}

int n;
vector<int> v[222];
ll f[222][222]; // probability to go left
ll ans = 0;

int sz[222], par[222], dept[222];
void dfs0(int now, int rt){
	sz[now] = 1;
	rep(i, (int)v[now].size()){
		if(v[now][i] != par[now]){
			dept[v[now][i]] = dept[now] + 1;
			par[v[now][i]] = now;
			dfs0(v[now][i], rt);
			sz[now] += sz[v[now][i]];
		}
	}
}
void dfs1(int now, int rt){
	rep(i, (int)v[now].size())
		if(v[now][i] != par[now])
			dfs1(v[now][i], rt);
	if(now < rt){
		int nowpos = now;
		int nxtsz = sz[now];
		do {
			nowpos = par[nowpos];
			ans = (ans + f[dept[nowpos]][dept[now] - dept[nowpos]] * (sz[nowpos] - nxtsz)) % Mod;
			nxtsz = sz[nowpos];
		} while(nowpos != rt);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	rep(i, n + 1)
		f[0][i] = 1, f[i][0] = 0;
	for(int l = 1; l <= n; l++)
		for(int r = 1; r <= n; r++)
			f[l][r] = (f[l - 1][r] + f[l][r - 1]) * inv2 % Mod;
	rep(i, n){
		par[i] = -1;
		dept[i] = 0;
		dfs0(i, i);
		dfs1(i, i);
	}
	ans = ans * qpow(n, Mod - 2) % Mod;
	cout << ans << endl;
	return 0;
}
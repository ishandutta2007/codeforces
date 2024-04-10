#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll qabs(ll a){
	return (a < 0) ? -a : a;
}

int n, m;
vector< pair<int, ll> > v[200200];
vector<int> rev[200200];
int q;

bool used[200200];
int cnt = 0;
int ord[200200], ind[200200];
int bel[200200];
void dfs0(int now){
	used[now] = 1;
	rep(i, (int)v[now].size()){
		if(!used[v[now][i].first]){
			dfs0(v[now][i].first);
		}
	}
	ord[cnt] = now;
	ind[now] = cnt;
	cnt++;
}
int nowscc = 0;
void dfs1(int now){
	bel[now] = nowscc;
	rep(i, (int)rev[now].size()){
		if(bel[rev[now][i]] < 0){
			dfs1(rev[now][i]);
		}
	}
}

int par[200200];
ll dept[200200];
ll g[200200];
void dfs2(int now){
	rep(i, (int)v[now].size()){
		if(par[v[now][i].first] < 0){
			par[v[now][i].first] = now;
			dept[v[now][i].first] = dept[now] + v[now][i].second;
			dfs2(v[now][i].first);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	rep(i, m){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		v[a].push_back(make_pair(b, c));
		rev[b].push_back(a);
	}
	memset(used, 0, sizeof(used));
	rep(i, n) if(!used[i]) dfs0(i);
	memset(bel, -1, sizeof(bel));
	for(int i = n - 1; i >= 0; i--) if(bel[ord[i]] < 0){
		dfs1(ord[i]);
		nowscc++;
	}
	memset(par, -1, sizeof(par));
	rep(i, n){
		if(par[i] < 0){
			par[i] = i;
			dept[i] = 0;
			dfs2(i);
		}
	} 
	memset(g, 0, sizeof(g));
//	rep(i, n){	cout << bel[i] << " ";	} cout << endl;
	rep(now, n){
		rep(i, (int)v[now].size()){
			if(bel[v[now][i].first] == bel[now] && par[v[now][i].first] != now){
//				cout << now << " " << v[now][i].first << endl;
				g[bel[now]] = __gcd(g[bel[now]], qabs(dept[now] + v[now][i].second - dept[v[now][i].first]));
			}
		}
	}
//	rep(i, n) cout << g[i] << " "; cout << endl;
	cin >> q;
	while(q--){
		int pos;
		ll s, t;
		cin >> pos >> s >> t;
		pos--;
		ll stp = __gcd(g[bel[pos]], t);
		if(s % stp == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
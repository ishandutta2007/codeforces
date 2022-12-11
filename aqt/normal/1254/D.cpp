// Problem : D. Tree Queries
// Contest : Codeforces - Codeforces Round #601 (Div. 1)
// URL : https://codeforces.com/contest/1254/problem/D
// Memory Limit : 512 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, Q;
const long long MOD = 998244353;
const int B = 200;
vector<int> graph[150005];
long long val[150005];
vector<int> hvy;
bool ishvy[150005];
int sz[150005];
int lft[150005], rht[150005], t;
long long bit[150005];
int par[150005];
vector<pair<int, int>> lst[150005];
long long inv[150005];

long long mult(long long a ,long long b){
	return a*b%MOD;
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret, ret);
	if(e&1){
		ret = mult(ret, b);
	}
	return ret;
}

void dfs(int n){
	lft[n] = ++t;
	sz[n] = 1;
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dfs(e);
			sz[n] += sz[e];
		}
	}
	rht[n] = t;
}

void upd(int n, long long v){
	if(v < 0){
		v += MOD;
	}
	while(n <= N){
		bit[n] = add(bit[n], v);
		n += n&-n;
	}
}

long long query(int n){
	long long ret = 0;
	while(n){
		ret = add(ret, bit[n]);
		n -= n&-n;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> Q;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	for(int i = 1; i<=N; i++){
		if(graph[i].size() > B){
			hvy.emplace_back(i);
			ishvy[i] = 1;
		}
	}
	dfs(1);
	const long long invN = qikpow(N, MOD-2);
	for(int i = 0; i<=N; i++){
	    inv[i] = mult(invN, i);
	}
	for(int n : hvy){
		for(int e : graph[n]){
			if(e != par[n]){
				lst[n].emplace_back(lft[e], sz[e]);
			}
		}
	}
	while(Q--){
		int c,n ,d;
		cin >> c >> n;
		if(c == 1){
			cin >> d;
			val[n] = add(val[n], d);
			if(!ishvy[n]){
				upd(1, d-mult(d, inv[N-sz[n]]));
				upd(lft[n], mult(d, inv[N-sz[n]]));
				upd(rht[n]+1, -mult(d, inv[N-sz[n]]));
				for(int e : graph[n]){
					if(e != par[n]){
						upd(lft[e], -mult(d, inv[sz[e]]));
						upd(rht[e]+1, mult(d, inv[sz[e]]));
					}
				}
			}
		}
		else{
			long long out = query(lft[n]);
			for(int k : hvy){
				if(k == n){
					out = add(out, val[k]);
				}
				else if(lft[k] < lft[n] && rht[k] >= rht[n]){
					auto it = --upper_bound(lst[k].begin(), lst[k].end(), make_pair(lft[n], INT_MAX));
					out = add(out, mult(val[k], mult(invN, N-it->second)));
				}
				else{
					out = add(out, mult(val[k], mult(invN, sz[k])));
				}
			}
			cout << out << "\n";
		}
	}
}
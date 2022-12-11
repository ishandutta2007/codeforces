
// Problem : B. Tree Array
// Contest : Codeforces - Codeforces Round #728 (Div. 1)
// URL : https://codeforces.com/contest/1540/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long pas[205][205];
const long long MOD = 1e9+7;
long long cache[205][205];
vector<int> graph[205];
int par[205];
bool vis[205];

long long add(long long a, long long b){
	return (a + b) % MOD;
}

long long mult(long long a, long long b){
	return a * b % MOD;
}

long long qikpow(long long b, long long e){
	if(!e){
		return 1;
	}
	long long ret = qikpow(b, e / 2);
	ret = mult(ret, ret);
	if(e & 1){
		ret = mult(ret, b);
	}
	return ret;
}

long long sub(long long a, long long b){
	return ((a - b) % MOD + MOD ) % MOD;
}

long long divd(long long a, long long b){
	return mult(a, qikpow(b, MOD - 2));
}

void dfs1(int n){
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dfs1(e);
		}
	}
}

int dfs2(int n, int p){
	int sz = 1;
	for(int e : graph[n]){
		if(!vis[e] && p != e){
			sz += dfs2(e, n);
		}
	}
	return sz;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 0; i <= N; i++){
		pas[i][0] = 1;
		for(int j = 1; j <= i; j++){
			pas[i][j] = add(pas[i-1][j], pas[i-1][j-1]);
		}
	}	
	for(int i = 1; i < N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	long long ans = 0;
	for(int n = 1; n <= N; n++){
		fill(par, par+1+N, 0);
		dfs1(n);
		vis[n] = 1;
		for(int k = n+1; k <= N; k++){
			int cur = k, len = 0;
			while(cur != n){
				vis[cur] = 1;
				len++;
				cur = par[cur];
			}
			cur = k;
			for(int t = len; t; t--){
				int s = dfs2(cur, 0);
				//cout << s << "\n";
				long long tot = divd(s, N);
				if(t == len){
					ans = add(ans, tot);
				}
				else{
					/*
					long long p = 1;//qikpow(divd(1, 2), len);					
					cout << p << " " << pas[len - 1][len - t] << "\n";
					p = mult(p, divd(pas[len - 1][len - t], pas[len][len-t]));
					cout << n << " " << k << " " << cur << "\n";
					cout << p << " " << tot << "\n";
					ans = add(ans, mult(p, tot));
					*/
					//cout << n << " " << k << " " << cur << "\n";
					//cout << tot << "\n";
					if(!cache[len][t]){
						for(int c = 0; c < t; c++){
							cache[len][t] = add(cache[len][t], mult(pas[c+len-t-1][len-t-1], qikpow(divd(1, 2), c+len-t)));
							//cout << mult(mult(pas[c+len-t-1][len-t-1], qikpow(divd(1, 2), c+len-t)), tot) << "\n";
						}		
					}
					ans = add(mult(tot, cache[len][t]), ans);
					
				}
				cur = par[cur];
			}
			cur = k;
			while(cur != n){
				vis[cur] = 0;
				cur = par[cur];
			}
		}
		vis[n] = 0;
	}
	cout << ans;
}
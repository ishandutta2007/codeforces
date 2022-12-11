
// Problem : E. Prince's Problem
// Contest : Codeforces - Codeforces Round #485 (Div. 1)
// URL : https://codeforces.com/contest/986/problem/E
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M = 10000000, Q;
const long long MOD = 1e9+7;
vector<int> graph[100005];
int par[17][100005], st[100005], ed[100005], dep[100005], t;
int u[100005], v[100005], w[100005], x[100005];
int arr[100005];
pair<int, int> srt[100005], qusrt[100005];
int ptr[10000005], quptr[10000005];
int sieve[10000005];
int bit[200005];
long long ans[100005];

void upd(int n, int v){
	while(n <= 2*N){
		bit[n] += v;
		n += n&-n;
	}
}

int query(int n){
	int ret = 0;
	while(n){
		ret += bit[n];
		n -= n&-n;
	}
	return ret;
}

void dfs(int n){
	st[n] = ++t;
	for(int e : graph[n]){
		if(e != par[0][n]){
			par[0][e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
	}
	ed[n] = ++t;
}

int lca(int u, int v){
	if(st[u] <= st[v] && ed[u] >= ed[v]){
		return u;
	}
	if(st[v] <= st[u] && ed[v] >= ed[u]){
		return v;
	}
	for(int d = 16; d>=0; d--){
		if(st[par[d][v]] <= st[u] && ed[par[d][v]] >= ed[u]){
			
		}
		else if(par[d][v]){
			v = par[d][v];
		}
	}
	return par[0][v];
}

long long qikpow(long long b, long long e){
	long long ret = 1;
	//cout << b << " " << e << "\n";
	while(e){
		if(e&1){
			ret *= b;
			ret %= MOD;
		}
		b *= b;
		b %= MOD;
		e >>= 1;
	}
	//cout << ret << "\n";
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for(int d = 1; d<=16; d++){
		for(int n = 1; n<=N; n++){
			par[d][n] = par[d-1][par[d-1][n]];
		}
	}
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
		srt[i].first = arr[i];
		srt[i].second = i;
	}
	sort(srt+1, srt+1+N);
	int idx = 1;
	for(int k = 1; k<=M+1; k++){
		ptr[k] = idx;
		while(idx <= N && srt[idx].first == k){
			idx++;
		}
	}
	for(int i = 2; i<=M; i++){
		if(!sieve[i]){
			for(int j = i; j<=M; j+=i){
				if(sieve[j]){
					sieve[j] = -1;
				}
				else{
					sieve[j] = i;
				}
			}
		}
	}
	cin >> Q;
	for(int q = 1; q<=Q; q++){
		cin >> u[q] >> v[q] >> x[q];
		w[q] = lca(u[q], v[q]);
		//cout << w[q] << "\n";
		qusrt[q].first = x[q];
		qusrt[q].second = q;
		ans[q] = 1;
	}
	sort(qusrt+1, qusrt+1+Q);
	idx = 1;
	for(int k = 1; k<=M+1; k++){
		quptr[k] = idx;
		while(idx <= Q && qusrt[idx].first == k){
			idx++;
		}
	}
	for(int k = 2; k<=M; k++){
		if(sieve[k] == -1){
			continue;
		}
		for(int a = k; a<=M; a+=k){
			for(int i = ptr[a]; i<ptr[a+1]; i++){
				upd(st[srt[i].second], 1);
				upd(ed[srt[i].second], -1);
			}
		}
		for(int a = k; a<=M; a+=k){
			for(int i = quptr[a]; i<quptr[a+1]; i++){
				int s = query(st[u[qusrt[i].second]]) + query(st[v[qusrt[i].second]]);
				s -= 2*query(st[w[qusrt[i].second]]);
				s += (arr[w[qusrt[i].second]]%k == 0);
				ans[qusrt[i].second] *= qikpow(sieve[k], s);
				ans[qusrt[i].second] %= MOD;
			}
		}
		for(int a = k; a<=M; a+=k){
			for(int i = ptr[a]; i<ptr[a+1]; i++){
				upd(st[srt[i].second], -1);
				upd(ed[srt[i].second], 1);
			}
		}
	}
	for(int q = 1; q<=Q; q++){
		cout << ans[q] << "\n";
	}
}

// Problem : G. Graph And Numbers
// Contest : Codeforces - Educational Codeforces Round 73 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1221/problem/G
// Memory Limit : 512 MB
// Time Limit : 3500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M, C, I;
bool B = 1;
long long adj[45];
bool solo[45];
int par[45];
int clr[45];
bool vis[45];
int dp[1<<21];

int getrt(int n){
	return par[n] = (par[n] == n ? n : getrt(par[n]));
}

void dfs(int n){
	vis[n] = 1;
	for(int e = 0; e<N; e++){
		if(adj[n]>>e&1){
			if(!vis[e]){
				clr[e] = clr[n] ^ 1;
				dfs(e);
			}
			else if(clr[e] == clr[n]){
				B = 0;
			}
		}
	}
}

vector<long long> gen(vector<int> v){
	int K = v.size();
	vector<long long> ret;
	for(int m = 0; m<1<<K; m++){
		long long crnt = 0;
		for(int k = 0; k<K; k++){
			if(m>>k&1){
				crnt |= (1LL<<v[k]);
			}
		}
		bool good = 1;
		for(int k = 0; k<K; k++){
			if(m>>k&1){
				good &= !(crnt&adj[v[k]]);
			}
		}
		if(good){
			ret.emplace_back(crnt);
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	fill(solo, solo+N, 1);
	C = N;
	for(int i = 1; i<N; i++){
		par[i] = i;
	}
	for(int i = 1; i<=M; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		solo[a] = solo[b] = 0;
		adj[a] |= (1LL<<b);
		adj[b] |= (1LL<<a);
		if(getrt(a) != getrt(b)){
			par[getrt(a)] = getrt(b);
			C--;
		}
	}
	for(int i = 0; i<N; i++){
		if(solo[i]){
			I++;
		}
		if(!vis[i]){
			dfs(i);
		}
	}
	long long ans = (1LL<<N);
	ans -= (1LL<<C);
	ans += 2*(1LL<<I);
	ans += B*(1LL<<C);
	ans -= (!M)*(1LL<<N);
	//cout << ans << " " << C << " " << I << "\n";
	vector<int> v1, v2;
	for(int i = 0; i<N; i++){
		if(i < 20){
			v1.emplace_back(i);
		}
		else{
			v2.emplace_back(i);
		}
	}
	auto m1 = gen(v1), m2 = gen(v2);
	int k1 = v1.size(), k2 = v2.size();
	for(auto m : m1){
		dp[m]++;
	}
	for(int k = 0; k<k1; k++){
		for(int m = 0; m<1<<k1; m++){
			if(m>>k&1){
				dp[m] += dp[m^(1<<k)];
			}
		}
	}
	for(auto m : m2){
		long long q = 0;
		for(int k = 20; k<N; k++){
			if(m>>k&1){
				q |= adj[k];
			}
		}
		//cout << q << endl;
		q %= (1LL<<k1);
		for(int k = 0; k<k1; k++){
			q ^= (1<<k);
		}
		//cout << q << endl;
		ans -= 2*dp[q];
	}
	cout << ans;
}
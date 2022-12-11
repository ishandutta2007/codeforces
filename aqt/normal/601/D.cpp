
// Problem : D. Acyclic Organic Compounds
// Contest : Codeforces - Codeforces Round #333 (Div. 1)
// URL : https://codeforces.com/contest/601/problem/D
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int N;
int par[300005];
int hvy[300005];
int sz[300005];
vector<int> graph[300005];
const long long MOD = 1e9+7;
pair<long long, long long> sd;
long long a[300005];
char c[300005];
long long tot[300005];
pair<long long, long long> coe[300005], con[300005];

long long add(long long a, long long b){
	return (a+b)%MOD;
}

long long mult(long long a, long long b){
	return a*b%MOD;
}

long long sub(long long a, long long b){
	return ((a-b)%MOD + MOD)%MOD;
}

pair<long long, long long> operator * (const pair<long long, long long> a, const pair<long long, long long> b){
	return {mult(a.first, b.first), mult(a.second, b.second)};
}

pair<long long, long long> operator + (const pair<long long, long long> a, const pair<long long, long long> b){
	return {add(a.first, b.first), add(a.second, b.second)};
}

pair<long long, long long> operator - (const pair<long long, long long> a, const pair<long long, long long> b){
	return {sub(a.first, b.first), sub(a.second, b.second)};
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

void dfs1(int n){
	sz[n] = 1;
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dfs1(e);
			sz[n] += sz[e];
			if(sz[hvy[n]] <= sz[e]){
				hvy[n] = e;
			}
		}
	}
}

set<pair<long long, long long>> dfs2(int n){
	//cout << n << " " << hvy[n] << endl;
	set<pair<long long, long long>> ret;
	coe[n] = {1, 1};
	if(hvy[n]){
		ret = dfs2(hvy[n]);
		coe[n] = coe[hvy[n]] * sd;
		con[n] = con[hvy[n]] * sd;
	}
	pair<long long, long long> k = make_pair(c[n], c[n]);
	con[n] = con[n] + k;	
	pair<long long, long long> inv = {qikpow(coe[n].first, MOD-2), qikpow(coe[n].second, MOD-2)};
	//cout << inv.first << " " << inv.second << endl;
	for(int e : graph[n]){
		if(e != par[n] && e != hvy[n]){
			//cout << n << " " << e << endl;
			auto s = dfs2(e);
			for(pair<long long, long long> q : s){
				pair<long long, long long> p = q * coe[e] + con[e];
				p = p * sd;
				p = p + k;
				p = p - con[n];
				p = p * inv;				
				ret.insert(p);
			}
		}
	}
	ret.insert((k - con[n])*inv);
	tot[n] = (long long) (ret.size()) + a[n];
	return ret;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sd.first = uniform_int_distribution<int>(MOD/2, MOD-1)(rando);
	sd.second = uniform_int_distribution<int>(MOD/2, MOD-1)(rando);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> a[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> c[i];
	}
	for(int i = 1; i<N; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs1(1);
	dfs2(1);
	long long ans1 = 0, ans2 = 0;
	for(int i = 1; i<=N; i++){
		if(tot[i] > ans1){
			ans1 = tot[i];
			ans2 = 1;
		}
		else if(tot[i] == ans1){
			ans2++;
		}
	}
	cout << ans1 << "\n" << ans2 << "\n";
	
}
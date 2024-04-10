
// Problem : G. Clusterization Counting
// Contest : Codeforces - Grakn Forces 2020
// URL : https://codeforces.com/contest/1408/problem/G
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, pair<int, int>>> edge;
int mat[1505][1505];
int dsu[1505];
vector<int> v[1505];
vector<int> lst[1505];
int cnt[1505], sz[1505];
int arr[1505];
long long dp[1505][1505];
const long long MOD = 998244353;

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? dsu[n] : getrt(dsu[n]));
}

long long add(long long a, long long b){
	return (a+b)%MOD;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			cin >> mat[i][j];
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<i; j++){
			edge.emplace_back(mat[i][j], make_pair(i, j));
		}
	}
	sort(edge.begin(), edge.end());
	for(int i = 1; i<=N;i ++){
		dsu[i] = i;
		sz[i] = 1;
		lst[i].push_back(i);
		v[i].push_back(1);
	}
	for(auto ee : edge){
		auto e = ee.second;
		if(getrt(e.first) != getrt(e.second)){
			int a = getrt(e.first), b = getrt(e.second);
			lst[a].insert(lst[a].end(), lst[b].begin(), lst[b].end());
			sz[a] += sz[b];
			dsu[b] = a;
			cnt[a] += cnt[b] + 1;
			if(cnt[a] == sz[a] * (sz[a]-1)/2){
				v[a].push_back(sz[a]);
			}
		}
		else{
			int p = getrt(e.first);
			cnt[p]++;
			if(cnt[p] == sz[p] * (sz[p]-1)/2){
				v[p].push_back(sz[p]);
			}
		}
	}
	for(int i = 1; i<=N; i++){
		if(sz[i] == N){
			reverse(lst[i].begin(), lst[i].end());
			for(int j = 1; j<=lst[i].size(); j++){
				arr[j] = lst[i][j-1];
				/*
				cout << arr[j] << ": ";
				for(int n : v[arr[j]]){
					cout << n << " ";
				}
				cout << "\n";
				*/
			}
		}
	}
	dp[0][0] = 1;
	for(int i = 1; i<=N; i++){
		int n = arr[i];
		for(int k = 1; k<=i; k++){
			for(int d : v[n]){
				dp[i][k] = add(dp[i][k], dp[i-d][k-1]);
			}
		}
	}
	for(int k = 1; k<=N; k++){
		cout << dp[N][k] << " ";
	}
}
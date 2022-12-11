
// Problem : B. Graph Coloring
// Contest : Codeforces - CROC 2016 - Final Round [Private, For Onsite Finalists Only]
// URL : https://codeforces.com/contest/662/problem/B
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int u[100005], v[100005];
bool b[100005];
int par[200005];
int sz[200005];

int getrt(int n){
	return par[n] = (par[n] == n ? n : getrt(par[n]));
}

void merge(int a, int b){
	a = getrt(a), b = getrt(b);
	sz[b] += sz[a];
	par[a] = b;
}

vector<int> solve(){
	for(int i = 1; i<=2*N; i++){
		par[i] = i;
		sz[i] = (i <= N);
	}
	for(int i = 1; i<=M; i++){
		if(b[i]){
			if(getrt(u[i]) != getrt(N+v[i])){
				merge(u[i], N+v[i]);
			}
			if(getrt(u[i]+N) != getrt(v[i])){
				merge(u[i]+N, v[i]);
			}
		}
		else{
			if(getrt(u[i]) != getrt(v[i])){
				merge(u[i], v[i]);
			}
			if(getrt(u[i]+N) != getrt(v[i]+N)){
				merge(u[i]+N, N+v[i]);
			}
		}
	}
	vector<int> ans;
	for(int n = 1; n<=N; n++){
		if(getrt(n) == getrt(n+N)){
			for(int k = 300000; k; k--){
				ans.push_back(k);
			}
			return ans;
		}
	}
	set<int> st;
	for(int n = 1; n<=N; n++){
		if(st.count(getrt(N+n))){
			
		}
		else if(st.count(getrt(n))){
			ans.push_back(n);
		}
		else{
			if(sz[getrt(n)] < sz[getrt(n+N)]){
				ans.push_back(n);
				st.insert(getrt(n));
			}
			else{
				st.insert(getrt(n+N));
			}
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		cin >> u[i] >> v[i];
		char c;
		cin >> c;
		b[i] = ('B' == c);
	}
	auto ans = solve();
	for(int i = 1; i<=M; i++){
		b[i] ^= 1;
	}
	auto temp = solve();
	if(temp.size() < ans.size()){
		swap(temp, ans);
	}
	if(ans.size() > N){
		cout << -1;
		return 0;
	}
	cout << ans.size() << "\n";
	for(int n : ans){
		cout << n << " ";
	}
}
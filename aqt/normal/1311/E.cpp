
// Problem : E. Construct the Binary Tree
// Contest : Codeforces - Codeforces Round #624 (Div. 3)
// URL : https://codeforces.com/contest/1311/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, D;
vector<int> v[5005];
int par[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;	
	while(T--){
		cin >> N >> D;
		long long tot = 1LL*N*(N-1)/2;
		for(int i= 1; i<=N; i++){
			v[i].clear();
			par[i] = i-1;
		}
		int idx = 1;
		for(int i = 1; i<=N; i++){
			v[i].push_back(i);
		}
		if(tot < D){
			cout << "NO\n";
			continue;
		}
		for(int i = N; i>idx && tot > D; i--){
			while(v[idx].empty()){
				idx++;
			}
			if(tot-D > i-1-idx){
				par[i] = v[idx].back();
				v[idx].pop_back();
				v[idx+1].push_back(i);
				v[idx+1].push_back(i);
				tot -= (i-1-idx);
			}
			else{
				int x = i-1-(tot - D);
				tot = D;
				par[i] = v[x].back();
			}
		}
		if(tot != D){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int i = 2; i<=N; i++){
			cout << par[i] << " ";
		}
		cout << "\n";
	}
}
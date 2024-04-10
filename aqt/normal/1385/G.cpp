
// Problem : G. Columns Swaps
// Contest : Codeforces - Codeforces Round #656 (Div. 3)
// URL : https://codeforces.com/contest/1385/problem/G
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int arr[2][200005];
pair<int, int> who[2][200005];
int dsu[400005];
int sz[400005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int unite(int a, int b){
	if(getrt(a) != getrt(b)){
		//cout << a << " " << b << " " << getrt(a) << " " << getrt(b) << "\n";
		sz[getrt(b)] += sz[getrt(a)];
		dsu[getrt(a)] = getrt(b);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		bool bad = 0;
		for(int i = 1; i<=N; i++){
			who[0][i] = who[1][i] = make_pair(0, 0);
		}
		for(int k = 0; k<2; k++){
			for(int i = 1; i<=N; i++){
				cin >> arr[k][i];
				if(who[1][arr[k][i]].second){
					bad = 1;
				}
				else if(who[0][arr[k][i]].second){
					who[1][arr[k][i]] = make_pair(k, i);
				}
				else{
					who[0][arr[k][i]] = make_pair(k, i);
				}
			}
		}
		if(bad){
			cout << -1 << "\n";
			continue;
		}
		iota(dsu+1, dsu+1+2*N, 1);
		fill(sz+1+N, sz+1+2*N, 1);
		fill(sz+1, sz+1+N, 0);
		for(int i= 1; i<=N; i++){
			if(who[1][i].second == who[0][i].second){
				
			}
			else if(who[1][i].first == who[0][i].first){
				int a = getrt(who[1][i].second), b = getrt(who[0][i].second);
				int ax = getrt(who[1][i].second + N) ,bx = getrt(who[0][i].second + N);
				if(a != bx){
					unite(a, bx);
					unite(b, ax);
				}
			}
			else{
				int a = getrt(who[1][i].second), b = getrt(who[0][i].second);
				int ax = getrt(who[1][i].second + N) ,bx = getrt(who[0][i].second + N);
				if(a != b){
					unite(a, b);
					unite(ax, bx);
				}				
			}
		}
		set<int> tkn;
		vector<int> ans;
		for(int i = 1; i<=N; i++){
			int p = getrt(i), q = getrt(i+N);
			if(tkn.count(p)){

			}
			else if(tkn.count(q)){
				ans.push_back(i);				
			}
			else if(sz[p] < sz[q]){
				tkn.insert(p);
			}
			else{
				tkn.insert(q);
				ans.push_back(i);
			}
		}
		cout << ans.size() << "\n";
		for(int n : ans){
			cout << n << " ";
		}
		cout << "\n";
	}
}
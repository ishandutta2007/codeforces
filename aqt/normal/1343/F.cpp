
// Problem : F. Restore the Permutation by Sorted Segments
// Contest : Codeforces - Codeforces Round #636 (Div. 3)
// URL : https://codeforces.com/contest/1343/problem/F
// Memory Limit : 0 MB
// Time Limit : 0 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int occ[205];
int tmp[205];
vector<vector<int>> v;
set<vector<int>> st;
int ans[205];
bool seen[205];
bool tkn[205];

int solve(int f){
	ans[1] = v[f][0], ans[2] = v[f][1];
	fill(seen+1, seen+1+N, 0);
	fill(tkn, tkn+N, 0);
	tkn[f] = 1;
	seen[ans[1]] = seen[ans[2]] = 1;
	//cout << " " << ans[1] << " " << ans[2] << " " << occ[ans[1]] << " " << occ[ans[2]] << "\n";
	if(occ[ans[1]] > occ[ans[2]]){
		swap(ans[1], ans[2]);
	}
	for(int i = 3; i<=N; i++){
		for(int j = 0; j<N-1; j++){
			if(v[j].size() <= i && !tkn[j]){
				bool b = 1;
				for(int k = i-1; k > i-v[j].size(); k--){
					//cout << j << " " << k << " " << ans[k] << "\n";
					//cout << "bs: " << binary_search(v[j].begin(), v[j].end(), ans[k]) << "\n";
					if(!binary_search(v[j].begin(), v[j].end(), ans[k])){
						b = 0;
						break;
					}
				}
				if(b){
					tkn[j] = 1;
					for(int n : v[j]){
						if(!seen[n]){
							ans[i] = n;
							seen[n] = 1;
							break;
						}
					}
					break;
				}
			}
			if(j == N-2){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i<N; i++){
			int k;
			cin >> k;
			vector<int> c;
			while(k--){
				int n;
				cin >> n;
				occ[n]++;
				tmp[n]++;
				c.push_back(n);
			}
			v.push_back(c);
		}
		random_shuffle(v.begin(), v.end());
		
		/*
		for(int i = 0; i<N-1; i++){
			for(int j : v[i]){
				cout << j << " ";
			}
			cout << "\n";
		}
		*/
		for(int i = 0; i<N-1; i++){
			if(v[i].size() == 2){
				if(solve(i)){
					break;
				}
			}
		}
		for(int i = 1; i<=N; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
		v.clear();
		fill(ans+1, ans+1+N, 0);
		fill(tmp+1, tmp+1+N, 0);
		fill(occ+1, occ+1+N, 0);
	}	
}
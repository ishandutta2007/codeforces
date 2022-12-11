
// Problem : A. k-Amazing Numbers
// Contest : Codeforces - Codeforces Round #673 (Div. 1)
// URL : https://codeforces.com/contest/1416/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T, N;
int ans[300005];
vector<int> pos[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i<=N; i++){
			pos[i].clear();
			ans[i] = INT_MAX;
		}
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			pos[n].push_back(i);
		}
		for(int i = N; i; i--){
			if(pos[i].size()){
				int bst = max(pos[i][0], N - pos[i].back() + 1);
				for(int j = 1; j<pos[i].size(); j++){
					bst = max(bst, pos[i][j] - pos[i][j-1]);
				}
				ans[bst] = i;
			}
		}
		for(int i = 1; i<=N; i++){
			if(i-1){
				ans[i] = min(ans[i], ans[i-1]);
			}
			if(ans[i] == INT_MAX){
				cout << -1 << " ";
			}
			else{
				cout << ans[i] << " ";
			}
		}
		cout << "\n";
	}
}
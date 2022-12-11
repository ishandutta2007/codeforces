
// Problem : C. Good String
// Contest : Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1389/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int D = 10;
vector<int> v[10];

int solve(int a, int b){
	int idx1 = 0, idx2 = 0;
	int len = 0, lst = 0;
	while(idx1 < v[a].size() && idx2 < v[b].size()){
		while(idx1 < v[a].size() && v[a][idx1] <= lst){
			idx1++;
		}
		if(idx1 < v[a].size()){
			lst = v[a][idx1];
			while(idx2 < v[b].size() && v[b][idx2] <= lst){
				idx2++;
			}
			if(idx2 < v[b].size()){
				lst = v[b][idx2];
				len++;
			}
			else{
				break;
			}
		}
		else{
			break;
		}
	}
	return 2*len;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		string s;
		cin >> s;
		int N = s.size();
		for(int d = 0; d<10; d++){
			v[d].clear();
		}
		for(int i = 1; i<=N; i++){
			v[s[i-1]-'0'].push_back(i);
		}
		int ans = 0;
		for(int i = 0; i<10; i++){
			ans = max(ans, (int) v[i].size());
		}
		for(int a = 0; a<10; a++){
			for(int b = 1; b<10; b++){
				ans = max(ans, solve(a, b));
				ans = max(solve(b, a), ans);
			}
		}
		cout << N - ans << "\n";
	}
}

// Problem : E. Merging Towers
// Contest : Codeforces - Educational Codeforces Round 91 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1380/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
set<int> st[200005];
bool exist[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int ans = N-1;
	for(int i = 1; i<=N; i++){
		int n;
		cin >> n;
		st[n].insert(i);
		if(st[n].count(i-1)){
			exist[i-1] = 1;
			ans--;
		}
	}
	cout << ans << "\n";
	M--;
	while(M--){
		int a, b;
		cin >> a >> b;
		if(st[b].size() > st[a].size()){
			swap(st[a], st[b]);
		}
		for(int n : st[b]){
			if(!exist[n-1]){
				exist[n-1] = st[a].count(n-1);
				ans -= exist[n-1];
			}
			if(!exist[n]){
				exist[n] = st[a].count(n+1);
				ans -= exist[n];
			}
			st[a].insert(n);
		}
		cout << ans << "\n";
	}
}
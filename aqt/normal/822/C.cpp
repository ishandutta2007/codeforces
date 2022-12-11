
// Problem : C. Hacker, pack your bags!
// Contest : Codeforces - Codeforces Round #422 (Div. 2)
// URL : https://codeforces.com/contest/822/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int M = 200000;
int mn[200005];
vector<pair<int, int>> query[200005];
vector<pair<int, int>> add[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, X;
	cin >> N >> X;
	fill(mn, mn+1+X, INT_MAX);
	for(int i = 1; i<=N; i++){
		int a, b, c;
		cin >> a >> b >> c;
		query[a].push_back({c, b-a+1});
		add[b].push_back({c, b-a+1}); 
	}
	int ans = INT_MAX;
	for(int i = 1; i<=M; i++){
		for(auto p : query[i]){
			//cout << p.first << " " << p.second << endl;
			if(p.second > X){
				continue;
			}
			if(mn[X-p.second] == INT_MAX){
				continue;
			}
			ans = min(mn[X-p.second] + p.first, ans);
		}
		for(auto p : add[i]){
			mn[p.second] = min(mn[p.second], p.first);
		}
	}
	cout << (ans == INT_MAX ? -1 : ans);
}
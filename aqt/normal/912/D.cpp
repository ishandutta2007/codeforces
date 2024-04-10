
// Problem : D. Fishes
// Contest : Codeforces Round #456 (Div. 2)
// URL : https://codeforces.com/problemset/problem/912/D
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

int N, M, R, K;
set<pair<int, int>> st;
priority_queue<pair<long long, pair<int, int>>> qu;

long long solve(int n, int m){
	long long a = max(1, n-R+1);
	a = min(N-R+1, n) - a + 1;
	long long b = max(1, m-R+1);
	b = min(M-R+1, m) - b + 1;
	return a*b;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> R >> K;
	st.insert({R, R});
	qu.push({solve(R, R), {R, R}});
	long long ans = 0;
	while(K--){
		auto p = qu.top();
		qu.pop();
		ans += p.first;
		int x = p.second.first, y = p.second.second;
		for(int i = x-1; i<=x+1; i++){
			for(int j = y-1; j<=y+1; j++){
				if(!st.count({i, j})){
					st.insert({i, j});
					qu.push({solve(i, j), {i, j}});
				}
			}
		}
	}
	cout << setprecision(13) << 1.0*ans/(1LL*(N-R+1)*(M-R+1)) << endl;
}
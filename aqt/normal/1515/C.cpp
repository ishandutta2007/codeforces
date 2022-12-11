
// Problem : C. Phoenix and Towers
// Contest : Codeforces - Codeforces Global Round 14
// URL : https://codeforces.com/contest/1515/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, M, X;
		cin >> N >> M >> X;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for(int i = 1; i <= M; i++){
			pq.push(make_pair(0, i));
		}
		cout << "YES\n";
		for(int i = 1; i <= N; i++){
			int h;
			cin >> h;
			auto p = pq.top();
			pq.pop();
			p.first += h;
			cout << p.second << " ";
			pq.push(p);
		}
		cout << "\n";
	}
}
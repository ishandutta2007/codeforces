#include <bits/stdc++.h>

using namespace std;

char out[505][505];

int main() {
	int T;
	cin >> T;
	while(T--) {
		int N, K, r, c;
		cin >> N >> K >> r >> c;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				out[i][j] = '.';
			}
		}
		r--,c--;
		out[r][c] = 'X';
		queue<pair<int, int>> qu;
		qu.push(make_pair(r, c));
		while(qu.size()) {
			auto n = qu.front();
			qu.pop();
			if(out[(n.first+K)%N][n.second] == '.') {
				qu.push(make_pair((n.first+K)%N, n.second));
				out[(n.first+K)%N][n.second] = 'X';
			}
			if(out[(n.first+1)%N][(n.second+1)%N] == '.') {
				qu.push(make_pair((n.first+1)%N, (n.second+1)%N));
				out[(n.first+1)%N][(n.second+1)%N] = 'X';
			}
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				cout << out[i][j];
			}
			cout << "\n";
		}
	}
}
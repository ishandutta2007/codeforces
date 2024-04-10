
// Problem : E. Math Test
// Contest : Codeforces - Educational Codeforces Round 120 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1622/problem/E
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
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<int> arr(N);
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}
		vector<vector<int>> v;
		vector<int> mskarr(M);
		for(int i = 0; i < N; i++) {
			v.push_back(vector<int>());
			for(int j = 0; j < M; j++) {
				char c;
				cin >> c;
				v[i].push_back(c == '1');
			}
		}
		vector<int> fre((1<<N) + 5);
		for(int j = 0; j < M; j++) {
			int msk = 0;
			for(int i = 0; i < N; i++) {
				msk |= (1<<i)*v[i][j];
			}
			fre[msk]++;
			mskarr[j] = msk;
		}
		int mx = 0;
		int bst = 0;
		vector<int> out(M);
		for(int n = 0; n < (1<<N); n++){
			vector<pair<int, int>> vec;
			int tot = 0;
			for(int i = 0; i < N; i++) {
				tot += ((n>>i&1^1)*2-1) * arr[i];
			}
			for(int m = 0; m < M; m++) {
				int val = 0;
				for(int i = 0; i < N; i++) {
					if(mskarr[m]>>i&1) {
						val += (n>>i&1)*2 - 1;
					}
				}
				vec.emplace_back(val, m);
			}
			sort(vec.begin(), vec.end());
			vector<int> tempout(M);
			for(int k = M; k; k--) {
				tot += vec[k-1].first * k;
				tempout[vec[k-1].second] = k;
			}
			if(mx <= tot) {
				mx = tot;
				bst = n;
				out = tempout;
			}
		}
		for(int n : out) {
			cout << n << " ";
		}
		cout << "\n";
	}
}
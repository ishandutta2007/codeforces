#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T;
	cin >> T;

	vector<char> cs;
	for (int i = 0; i < 26; i++)cs.push_back(i + 'a');
	for (int i = 0; i < 26; i++)cs.push_back(i + 'A');
	for (int i = 0; i < 10; i++)cs.push_back(i + '0');
	while (T--) {
		int N, M, K;
		cin >> N >> M >> K;
		vector<string> S(N);
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			for (int j = 0; j < M; j++) {
				if (S[i][j] == 'R')cnt++;
			}
		}
		vector<string> res = S;

		int n = cnt / K;

		int cur = 0;
		//cerr << n << endl;
		for (int i = 0; i < N; i++) {
			int A = 0;
			int B = M;
			int C = 1;
			if (i % 2 == 1) {
				A = M - 1;
				B = -1;
				C = -1;
			}
			for (int j = A; j != B; j += C) {
				res[i][j] = cs[cur];
				if (S[i][j] == 'R') {
					n--;
					cnt--;
					if (n <= 0) {
						if (K <= 1) {
							n = 1000000000;
						}else{
							K--;
							n = cnt / K;

							//cerr << n << endl;
							cur++;
						}
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			cout << res[i] << endl;
		}
	}
}
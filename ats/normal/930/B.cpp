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
vector < vector<string> > vs;
int C[26];

int D[26];
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string S;
	cin >> S;
	int N = S.size();
	string t;
	vs.resize(26);
	for (int i = 0; i < N; i++) {
		t.clear();
		for (int j = 0; j < N; j++) {
			t.push_back(S[(i + j) % N]);
		}
		vs[S[i] - 'a'].push_back(t);
	}
	int tt = 0;
	for (int i = 0; i < 26; i++) {
		C[i] = 0;
		D[i] = 0;
	}
	tt++;
	int mx = 0;
	double res = 0;
	int tmp;
	for (int i = 0; i < 26; i++) {
		mx = -1;
		tmp = 0;
		for (int j = 0; j < N; j++) {
			tmp = 0;
			for (int k = 0; k < (int)vs[i].size(); k++) {
				if (C[vs[i][k][j] - 'a'] != tt) {
					tmp++;
					C[vs[i][k][j] - 'a'] = tt;
				}
				else {
					if (D[vs[i][k][j] - 'a'] != tt) {
						tmp--;
						D[vs[i][k][j] - 'a'] = tt;
					}
				}
			}
			tt++;

			mx = max(tmp, mx);
		}

		//if (mx == (int)vs[i].size()) {
			res += (double)mx / N;
		//}
	}
	cout << setprecision(15) << res << endl;
}
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
	int N;
	cin >> N;
	int res = 0;
	char a;
	string S;
	vector<int> X(26,0);
	char x = '?';
	char aa = '?';
	bool f;
	for (int i = 0; i < N; i++) {
		cin >> a >> S;
		if (a == '.') {
			for (int i = 0; i < S.size(); i++) {
				X[S[i] - 'a'] = 1;
			}
		}
		else if (a == '!') {
			if (x != '?') {
				res++;
			}
			for (int i = 0; i < S.size(); i++) {
				if (X[S[i] - 'a'] < 5) {
					X[S[i] - 'a'] += 10;
				}
			}
			for (int i = 0; i < 26; i++) {
				if (X[i] > 5) {
					X[i] -= 10;
				}
				else {
					X[i] = 1;
				}
			}
		}
		else {
			X[S[0] - 'a'] = 1;
			if (x != '?') {
				
				if (S[0] != x) {
					res++;
				}
			}
		}
		if (x == '?') {
			f = false;
			aa = '?';
			for (int i = 0; i < 26; i++) {
				if (X[i] == 0) {
					if (aa == '?') {
						f = true;
						aa = i + 'a';
					}
					else {
						f = false;
					}
				}
			}
			if (f) {
				x = aa;
				/*cerr << endl;
				cerr << x << endl;
				cerr << endl;*/
			}
		}
	}
	cout << res << endl;
}
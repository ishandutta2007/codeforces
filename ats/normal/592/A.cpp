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
	vector<string> S(8);
	for (int i = 0; i < 8; i++) {
		cin >> S[i];
	}
	int w = 10, b = 10;
	for (int j = 0; j < 8; j++) {
		int mnw = -1;
		for (int i = 0; i < 8; i++) {
			if (S[i][j] == 'W') {
				mnw = i;
				break;
			}
			else if (S[i][j] == 'B') {
				break;
			}
		
		}
		if (mnw != -1) {
			w = min(w, mnw);
		}
		int mnb = -1;
		for (int i = 7; i >= 0; i--) {
			if (S[i][j] == 'B') {
				mnb = 7 - i;
				break;
			}
			else if (S[i][j] == 'W') {
				break;
			}
			
		}
		if (mnb != -1) {
			b = min(b, mnb);

		}
	}
	//cerr << w << " " << b << endl;
	if (w <= b) {
		cout << "A" << endl;
	}
	else {
		cout << "B" << endl;
	}
}
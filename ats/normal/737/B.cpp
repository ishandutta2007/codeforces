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
	int N, A, B, K;
	cin >> N >> A >> B >> K;
	string S;
	cin >> S;
	int c = 0;
	int tot = 0;
	for (int i = 0; i <= N; i++) {
		if (i == N || S[i] == '1') {
			tot += c / B;
			c = 0;
		}
		else {
			c++;
		}
	}

	if (tot < A) {
		cout << 0 << endl;
		cout << endl;
		return 0;
	}
	vector<int> res;
	for (int i = 0; i <= N; i++) {
		if (i == N || S[i] == '1') {
			c = 0;
		}
		else {
			c++;
			if (c == B) {
				c = 0;
				tot--;
				res.push_back(i + 1);
				if (tot < A) {
					break;
				}
			}
		}
	}

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;
}
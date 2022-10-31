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
struct V {
	int a[2];
	int from;
	int cnt = 0;
	V() {
		for (int i = 0; i < 2; i++) {
			a[i] = -1;
		}
	}
};
vector<V> vs;
vector<string> ss;
signed main() {
	ios::sync_with_stdio(false);

	V tmp;
	tmp.from = -1;
	for (int i = 0; i < 2; i++) {
		tmp.a[i] = -1;
	}

	int N;
	cin >> N;
	int cur;
	vs.clear();
	vs.push_back(tmp);
	vector<int> res;
	char c;
	string S;
	for (int i = 0; i < N; i++) {

		cin >> c;
		if (c == '?') {
			cin >> S;
			reverse(S.begin(), S.end());
			while (S.size() < 19)S.push_back('0');
			cur = 0;
			int ans = 0;
			bool ok = true;
			for (int j = 0; j < S.size(); j++) {
				if (vs[cur].a[(int)(S[j] - '0') % 2] == -1) {
					ok = false;
					break;
				}
				else {
					cur = vs[cur].a[(int)(S[j] - '0') % 2];
				}
			}
			if (ok) ans = vs[cur].cnt;
			res.push_back(ans);
		}
		else if (c == '+') {
			cin >> S;
			reverse(S.begin(), S.end());
			while (S.size() < 19)S.push_back('0');
			cur = 0;
			for (int j = 0; j < S.size(); j++) {
				if (vs[cur].a[(int)(S[j] - '0') % 2] == -1) {
					vs[cur].a[(int)(S[j] - '0') % 2] = (int)vs.size();
					tmp.from = cur;
					cur = vs.size();
					vs.push_back(tmp);
				}
				else {
					cur = vs[cur].a[(int)(S[j] - '0') % 2];


				}
			}
			vs[cur].cnt++;

		}
		else {
			cin >> S;
			reverse(S.begin(), S.end());
			while (S.size() < 19)S.push_back('0');
			cur = 0;
			for (int j = 0; j < S.size(); j++) {
				if (vs[cur].a[(int)(S[j] - '0') % 2] == -1) {
					vs[cur].a[(int)(S[j] - '0') % 2] = (int)vs.size();
					tmp.from = cur;
					cur = vs.size();
					vs.push_back(tmp);
				}
				else {
					cur = vs[cur].a[(int)(S[j] - '0') % 2];


				}
				
			}
			vs[cur].cnt--;
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
}
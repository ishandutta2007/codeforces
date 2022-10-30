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
	int a[10];
	int from;
	int type = 1;
	int cnt = 0;
	V() {
		for (int i = 0; i < 10; i++) {
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
	for (int i = 0; i < 10; i++) {
		tmp.a[i] = -1;
	}
	tmp.cnt = 0;
	int N;
	cin >> N;
	ss.clear();
	ss.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> ss[i];
	}
	int cur;
	vs.clear();
	vs.push_back(tmp);
	set<int> s;
	for (int i = 0; i < N; i++) {
		s.clear();
		for (int st = 0; st < ss[i].size(); st++) {
			cur = 0;
			for (int j = st; j < ss[i].size(); j++) {
				if (vs[cur].a[(int)(ss[i][j] - '0')] == -1) {
					vs[cur].a[(int)(ss[i][j] - '0')] = (int)vs.size();
					tmp.from = cur;
					cur = vs.size();
					vs.push_back(tmp);
				}
				else {
					cur = vs[cur].a[(int)(ss[i][j] - '0')];
				}
				if (s.count(cur) == 0) {
					vs[cur].cnt++;
					s.insert(cur);
				}
			}
		}
	}
	vector<int> mn(N, 1000000000);
	vector<string> res(N, "XXX");
	for (int i = 0; i < N; i++) {
		for (int st = 0; st < ss[i].size(); st++) {
			cur = 0;
			for (int j = st; j < ss[i].size(); j++) {
				cur = vs[cur].a[(int)(ss[i][j] - '0')];
				
				if (vs[cur].cnt == 1) {
					
					if (mn[i] > j - st + 1) {
						mn[i] = j - st + 1;
						res[i] = ss[i].substr(st, j - st + 1);
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << res[i] << endl;
	}
}
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
	string S;
	int a;
	int INF = (int)1 << 50;
	int l = -INF;
	int r = INF;
	set<int> st;
	st.insert(l);
	st.insert(r);
	int res = 1;
	for (int i = 0; i < N; i++) {
		cin >> S >> a;
		if (S[1] == 'D') {
			st.insert(a);
		}
		else {
			auto x = st.find(a);
			if (a >= l && a <= r) {
				if (a > l && a < r) {
					res = (res * 2) % MOD;
				}
				x--;
				l = (*x);
				x++; x++;
				r = (*x);
			}
			else {
				cout << 0 << endl;
				return 0;
			}
			st.erase(a);
		}
	}
	{
		auto x = st.find(l);
		x++;
		int c = 0;
		while ((*x) < r) {
			c++;
			x++;
		}
		res = (res * (c + 1)) % MOD;
	}
	cout << res << endl;
}
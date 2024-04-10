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
	string S;
	cin >> S;
	S = S.substr(5, S.size() - 5);
	int N = S.size();
	for (int i = 0; i < 5; i++) {
		S.push_back('.');
	}
	vector<bool> ok2(N + 5, false);
	vector<bool> ok3(N + 5, false);
	for (int i = N; i < ok2.size(); i++) {
		ok2[i] = true;
		ok3[i] = true;
	}
	set<string> st;
	for (int i = N - 2; i >= 0; i--) {

		if (i != N - 3 && ((S.substr(i, 2) != S.substr(i + 2, 2) && ok2[i + 2]) || ok3[i + 2])) {
			ok2[i] = true;
			st.insert(S.substr(i, 2));
		}
		if (i != N - 4 && i != N - 2 && ((S.substr(i, 3) != S.substr(i + 3, 3) && ok3[i + 3]) || ok2[i + 3])) {
			ok3[i] = true;
			st.insert(S.substr(i, 3));
		}


	}

	cout << st.size() << endl;
	for (auto s : st) {
		cout << s << endl;
	}
}
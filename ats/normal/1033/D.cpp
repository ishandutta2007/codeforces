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
int MOD = 998244353;
int gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	int res = 1;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	map<int, int> mp;
	map<int, int> num;
	vector<int> C;
	set<int> st;
	for (int i = 0; i < N; i++) {

		//Case 5
		int X = pow(A[i], 0.25);	
		X = max((int)0, X - 3);
		while (X*X*X*X < A[i]) X++;
		if (X*X*X*X == A[i]) {
			mp[X] += 4;
			st.insert(X);
			continue;
		}


		//Case 4
		X = pow(A[i], 1.0 / 3);
		X = max((int)0, X - 3);
		while (X*X*X < A[i]) X++;
		if (X*X*X == A[i]) {
			mp[X] += 3;
			st.insert(X);
			continue;
		}

		//Case 3
		X = sqrt(A[i]);
		X = max((int)0, X - 3);
		while (X*X < A[i]) X++;
		if (X*X == A[i]) {
			mp[X] += 2;
			st.insert(X);
			continue;
		}


		//Case 4
		num[A[i]]++;
		if (num[A[i]] == 1) {

			C.push_back(A[i]);
		}
	}
	vector<int> V(C.size(), 0);
	for (int i = 0; i < C.size(); i++) {
		for (int j = i + 1; j < C.size(); j++) {
			int a = gcd(C[i], C[j]);
			if (a != 1) {
				st.insert(a);
				st.insert(C[i] / a);
				st.insert(C[j] / a);
			}
		}
	}
	vector<int> sv;
	for (auto s : st) {
		sv.push_back(s);
	}
	for (int i = 0; i < C.size(); i++) {
		bool ok = true;
		for (int j = 0; j < sv.size(); j++) {
			if (C[i] % sv[j] == 0) {
				mp[sv[j]] += num[C[i]];
				mp[C[i] / sv[j]] += num[C[i]];
				ok = false;
				break;
			}
		}
		if (ok) {
			//cerr << C[i] << endl;
			int t = num[C[i]] + 1;
			res = (res * t*t) % MOD;
		}
	}
	for (auto m : mp) {
		//cerr << m.first << " " << m.second << endl;
		res = (res * (m.second + 1)) % MOD;
	}
	cout << res << endl;
}
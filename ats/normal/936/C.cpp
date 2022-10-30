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
void op1(int n, string &S) {
	string K;
	for (int i = 0; i < n; i++) {
		K.push_back(S[(int)S.size() - 1 - i]);
	}
	for (int i = 0; i < (int)S.size() - n; i++) {
		K.push_back(S[i]);
	}
	swap(S, K);
}
string T;
void solve(string S,vector<int> &res) {
	int N = S.size();
	int pos1 = (N / 2) - 1;
	int pos2 = pos1 + 1;
	//cerr << "st=" << S << endl;
	while(true) {
		int a1 = pos1;
		while (a1 >= 0 && S[a1] != T[pos1]) {
			a1--;
		}
		if (a1 == -1) {
			break;
		}
		int a2 = pos2;
		while (a2 < N && S[a2] != T[pos2]) {
			a2++;
		}
		if (a2 == N) {
			break;
		}
		res.push_back(N - a1 - 1);
		res.push_back(a2);
		res.push_back(N - pos1 - 1);
		res.push_back(pos2);
		op1(N - a1 - 1, S);
		op1(a2, S);
		op1(N - pos1 - 1, S);
		op1(pos2, S);
		pos1--;
		pos2++;
		//cerr << a1 << " " << a2 << endl;
		//cerr << S << endl;
	}
	res.push_back(N - pos2);
	op1(N - pos2, S);
	op1(N - pos2, T);
	pos1 += N - pos2;
	//cerr << pos1 << " " << pos2 << endl;
	//cerr << S << endl;

	while (true) {
		int a1 = pos1;
		while (a1 >= 0 && S[a1] != T[pos1]) {
			a1--;
		}
		if (a1 == -1) {
			break;
		}
		res.push_back(N - a1 - 1);
		res.push_back(N);
		res.push_back(N - pos1 - 1);
		res.push_back(N);
		op1(N - a1 - 1, S);
		op1(N, S);
		op1(N - pos1 - 1, S);
		op1(N, S);
		pos1--;
		//cerr << S << endl;
	}
	//cerr << S << endl;
	//cerr << T << endl;
	op1(pos2, S);
	op1(pos2, T);
	op1(N - pos2, S);
	op1(N - pos2, T);
	op1(pos2, S);
	op1(pos2, T);
	res.push_back(pos2);
	res.push_back(N - pos2);
	res.push_back(pos2);
	//cerr << S << endl;
	//cerr << T << endl;
	if (S != T)cerr << "ERROR" << endl;
	//cerr << endl;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;

	string S;
	cin >> S >> T;
	
	vector<vector<int> > ind(26);
	vector<int> C(26, 0);
	for (int i = 0; i < N; i++) {
		ind[S[i] - 'a'].push_back(i);
	}
	vector<int> order(N);
	vector<int> pos(N);
	bool ok = true;
	for (int i = 0; i < N; i++) {
		if ((int)ind[T[i] - 'a'].size() <= C[T[i] - 'a']) {
			ok = false;
			//cerr << "ng" << endl;
			break;
		}
		//cerr << i << " " << ind[T[i] - 'a'][C[T[i] - 'a']] << endl;
		pos[i] = ind[T[i] - 'a'][C[T[i] - 'a']];
		C[T[i] - 'a']++;
	}
	if (!ok) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> res;
	vector<int> res1;
	solve(S, res1);
	//reverse(S.begin(), S.end());
	vector<int> res2;
	res2.push_back(N);
	op1(N, S);
	solve(S, res2);
	
	if ((int)res1.size() > (int)res2.size()) {
		res = res2;
	}
	else {
		res = res1;
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		if (i > 0)cout << " ";
		cout << res[i];
	}
	cout << endl;




	//cout << res << endl;
}
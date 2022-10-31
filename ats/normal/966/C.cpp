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
int f(int a) {
	int res = 0;
	while (a > 0) {
		a /= 2;
		res++;
	}
	return res;
}
void ff(int a,vector<int>  &x) {
	int res = 0;
	x.clear();
	while (a > 0) {
		res++;
		if(a % 2 == 1)x.push_back(res);
		a /= 2;
	}
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	vector<int> res;
	int cur = 0;
	for (int i = 0; i < N; i++){
		cin >> A[i];
		cur ^= A[i];
	}
	for (int i = 0; i < N; i++) {
		B[i] = f(A[i]);
		//cerr << B[i] << endl;
	}
	vector<vector<int> > l(61);
	vector<int> p(61, 0);
	for (int i = 0; i < N; i++) {
		l[B[i]].push_back(A[i]);
	}
	for (int i = 0; i < l.size(); i++) {
		sort(l[i].begin(), l[i].end());
	}
	bool f2 = true;
	bool f3;
	vector<int> x;
	for (int i = 0; i < N; i++) {
		//cerr << cur << endl;
		ff(cur, x);
		f3 = false;
		for (int j = 0; j < x.size(); j++) {
			//cerr << x[j] << endl;
			if ((int)l[x[j]].size() <= p[x[j]]) {
				continue;
			}
			else {
				cur ^= l[x[j]][p[x[j]]];
				res.push_back(l[x[j]][p[x[j]]]);
				p[x[j]]++;
				f3 = true;
				break;
			}
		}
		if (!f3) {
			f2 = false; 
			break;
		}
	}
	reverse(res.begin(), res.end());
	/*int o = 0;
	for (int i = 0; i < res.size(); i++) {
		o^=res[i];
		cerr << o << " ";
	}
	cerr << endl;*/
	if (f2) {
		cout << "Yes" << endl;
		for (int i = 0; i < res.size(); i++) {
			if (i > 0)cout << " ";
			cout << res[i];
		}
		cout << endl;
	}
	else {
		cout << "No" << endl;
	}
	
}
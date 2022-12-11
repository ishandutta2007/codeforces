
// Problem : E. Guess the Root
// Contest : Codeforces - Educational Codeforces Round 63 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1155/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

//vector<int> in = {1000002, 0, 1};
vector<int> in;

long long mat[55][55];
long long ans[55];
const long long MOD = 1000003;

long long add(long long a, long long b) {
	return (a + b) % MOD;
}

long long mult(long long a, long long b) {
	return (a * b) % MOD;
}

long long qikpow(long long b, long long e) {
	if(!e) {
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret,ret);
	if(e&1) {
		ret = mult(ret, b);
	}
	return ret;
}

int query(int n) {
	if(in.empty()){ 
		cout << "? " << n << endl;
		cin >> n;
		return n;
	}
	else{
		int ret = 0;
		for(int k = 0; k < in.size(); k++) {
			int p = 1;
			for(int t = 0; t < k; t++) {
				p = mult(p, n);
			}
			ret = add(ret, mult(in[k], p));
		}
		return ret;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int t = 0; t < 50; t++) {
		ans[t] = query(t);
		mat[t][0] = 1;
		for(int k = 1; k < 50; k++) {
			mat[t][k] = mult(t, mat[t][k-1]);
		}
	}	
	for(int col = 0; col < 50; col++){
		bool found = 0;
		for(int row = col; row < 50; row++) {
			if(mat[row][col]) {
				for(int k = col; k < 50; k++) {
					swap(mat[row][k], mat[col][k]);
				}
				swap(ans[row], ans[col]);
				found = 1;
				break;
			}
		}
		assert(found);
		long long inv = qikpow(mat[col][col], MOD - 2);
		for(int k = col; k < 50; k++){
			mat[col][k] = mult(mat[col][k], inv);
		}
		ans[col] = mult(ans[col], inv);
		for(int row = 0; row < 50; row++) {
			if(col != row) {
				long long coe = MOD-mat[row][col];
				for(int k = col; k < 50; k++) {
					mat[row][k] = add(mat[row][k], mult(coe, mat[col][k]));
				}
				ans[row] = add(ans[row], mult(coe, ans[col]));
			}
		}
	}
	vector<int> poly;
	for(int i = 0; i < 50; i++) {
		poly.push_back(mat[i][i] * ans[i]);
	}
	reverse(poly.begin(), poly.end());
	for(int x = 0; x < MOD; x++) {
		int val = 0;
		for(int n : poly) {
			val = mult(x, val);
			val = add(val, n);
		}
		if(!val) {
			cout << "! " << x << endl;
			return 0;
		}
	}
	cout << "! " << -1 << endl;
}
#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

#define x first
#define y second

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int MOD = 1000 * 1000 + 3;

int norm(int a) {
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
	return a;
}
int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}
int binPow(int a, int k) {
	int ans = 1;
	while(k > 0) {
		if(k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}
int inv(int a) {
	return binPow(a, MOD - 2);
}

int k = 10;
vector<int> f;

int main() {
	f.resize(k + 1);
	fore(i, 0, sz(f)) {
		cout << "? " << i << endl;
		cout.flush();
		cin >> f[i];
	}
	
	vector< vector<int> > mat(sz(f), vector<int>(sz(f) + 1));
	fore(i, 0, sz(mat)) {
		mat[i][0] = 1;
		mat[i][sz(f)] = f[i];
		
		fore(j, 1, sz(mat[i]) - 1)
			mat[i][j] = mul(mat[i][j - 1], i);
	}
	
	/*
	fore(i, 0, sz(mat)) {
		fore(j, 0, sz(mat[i]))
			cerr << mat[i][j] << " ";
		cerr << endl;
	}
	*/
	
	fore(j, 0, sz(mat)) {
		int nid = -1;
		fore(i, j, sz(mat)) {
			if(mat[i][j] != 0) {
				nid = i;
				break;
			}
		}
		if(nid == -1)
			continue;
		
		swap(mat[j], mat[nid]);
		fore(i, 0, sz(mat)) {
			if(i == j) continue;
			int cf = mul(mat[i][j], inv(mat[j][j]));
			
			fore(cj, j, sz(mat[i]))
				mat[i][cj] = norm(mat[i][cj] - mul(cf, mat[j][cj]));
		}
	}
	
	vector<int> a(sz(f), 0);
	fore(i, 0, sz(a)) {
		if(mat[i][i] == 0)
			continue;
		a[i] = mul(mat[i][sz(a)], inv(mat[i][i]));
	}
	
	fore(x0, 0, MOD) {
		int val = 0;
		for(int i = sz(a) - 1; i >= 0; i--)
			val = norm(mul(val, x0) + a[i]);
			
		if(val == 0) {
			cout << "! " << x0 << endl;
			return 0;
		}
	}
	
	cout << "! -1" << endl;
	return 0;
}
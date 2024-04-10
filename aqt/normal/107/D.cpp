
// Problem : D. Crime Management
// Contest : Codeforces - Codeforces Beta Round #83 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/107/D
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long E, M, N;
const long long MOD = 12345;
int base[30];
set<int> st;
vector<int> lst[30];

struct Matrix{
	vector<vector<long long>> mat;
	int r, c;
	
	Matrix(){
		r = c = 0;
	}
	
	Matrix(int _r, int _c){
		r = _r, c = _c;
		mat.resize(_r);
		for(int i = 0; i<_r; i++){
			mat[i].resize(_c, 0);
		}
	}
	
	Matrix operator + (const Matrix & m){
		Matrix ret(r, c);
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				ret.mat[i][j] = mat[i][j] + m.mat[i][j];
				ret.mat[i][j] %= MOD; 
			}
		}
		return ret;
	}
	
	Matrix operator - (const Matrix & m){
		Matrix ret(r, c);
		for(int i = 0; i<r; i++){
			for(int j = 0; j<c; j++){
				ret.mat[i][j] = mat[i][j] - m.mat[i][j];
				ret.mat[i][j] %= MOD;
				ret.mat[i][j] += MOD;
				ret.mat[i][j] %= MOD;
			}
		}
		return ret;
	}
	
	Matrix operator * (const Matrix & m){
		Matrix ret(r, m.c);
		for(int i = 0; i<r; i++){
			for(int j = 0; j<m.c; j++){
				for(int k = 0; k<c; k++){
					ret.mat[i][j] += mat[i][k] * m.mat[k][j];
				}
				ret.mat[i][j] %= MOD;
			}
		}
		return ret;
	}
};

Matrix graph;

Matrix qikpow(long long e){
	if(!e){
		Matrix ret(N, N);
		for(int i = 0; i<N; i++){
			ret.mat[i][i] = 1;
		}
		return ret;
	}
	Matrix ret = qikpow(e/2);
	ret = ret*ret;
	if(e&1){
		ret = ret*graph;
	}
	/*
	cout << e << "\n";
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cout << ret.mat[i][j];
		}
		cout << "\n";
	}
	*/
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> E >> M;
	fill(base, base+26, 1);
	while(M--){
		char c;
		int m;
		cin >> c >> m;
		int k = c-'A';
		base[k] = base[k] * m / __gcd(base[k], m);
		lst[k].push_back(m);
		st.insert(k);
	}
	N = 1;
	for(int i = 0; i<26; i++){
		N *= base[i];
	}
	graph = Matrix(N, N);
	for(int i = 0; i<N; i++){
		for(int n : st){
			//cout << "bing: " << i << " " << n << "\n";
			int t = i;
			for(int b = 0; b<n; b++){
				t /= base[b];
			}
			int v = t%base[n];
			int w = v;
			v++;
			v %= base[n];
			//cout << n << " " << v << "\n";
			for(int b = 0; b<n; b++){
				v *= base[b];
				w *= base[b];
			}
			int j = i+v-w;
			//cout << i << " " << j << " " << N << "\n";
			graph.mat[i][j]++;
		}
	}
	/*
	for(int i = 0; i<N; i++){
		for(int j = 0; j<N; j++){
			cout << graph.mat[i][j];
		}
		cout << "\n";
	}
	*/
	Matrix ret = qikpow(E);
	long long ans = 0;
	for(int i = 0; i<N; i++){
		bool good = 1;
		for(int n : st){
			bool chk = 0;
			int t = i;
			for(int b = 0; b<n; b++){
				t /= base[b];
			}
			int v = t%base[n];
			for(int d : lst[n]){
				if(v%d == 0){
					chk = 1;
				}
			}
			good &= chk;
		}
		if(good){
			ans += ret.mat[0][i];
		}
	}
	cout << ans%MOD;
}
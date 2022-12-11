
// Problem : G. Lucky Tickets
// Contest : Codeforces - Educational Codeforces Round 57 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1096/G
// Memory Limit : 256 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, D;
vector<long long> base(10);
const long long MOD = 998244353;

void fft(vector<complex<double>>& a){
	int S = (int) (a.size());
	int L = 31 - __builtin_clz(S);
	static vector<complex<double>> R(2, 1);
	static vector<complex<double>> rt(2, 1);
	for(static int k = 2; k < S; k *= 2){
		R.resize(S);
		rt.resize(S);
		auto x = polar(1.0, acos(-1.0) / k);
		for(int i = k; i < 2 * k; i++){
			rt[i] = R[i] = (i&1 ? R[i / 2] * x : R[i / 2]); 
		}
	}
	vector<int> rev(S);
	for(int i = 0; i < S; i++){
		rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	}
	for(int i = 0; i < S; i++){
		if(i < rev[i]) {
			swap(a[i], a[rev[i]]);
		}
	}
	for(int k = 1; k < S; k *= 2){
		for(int i = 0; i < S; i += 2 * k){
			for(int j = 0; j < k; j++){
				complex<double> z = rt[j + k] * a[i + j + k];
				a[i + j + k] = a[i + j] - z;
				a[i + j] += z;
			}
		}
	}
}

vector<long long> convMod(const vector<long long> &a, const vector<long long> &b){
	if(a.empty() || b.empty()){
		return {};
	}
	int A = (int) a.size();
	int B = (int) b.size();
	vector<long long> ret(A + B - 1);
	int P = 32 - __builtin_clz(A + B - 1);
	int S = (1 << P);
	int cut = (int) sqrt(MOD);
	vector<complex<double>> L(S), R(S), outs(S), outl(S);
	for(int i = 0; i < A; i++){
		L[i] = complex<double>(a[i] / cut, a[i] % cut);
	}
	for(int i = 0; i < B; i++){
		R[i] = complex<double>(b[i] / cut, b[i] % cut);
	}
	fft(L);
	fft(R);
	for(int i = 0; i < S; i++){
		int j = (-i & (S - 1));
		outl[j] = (L[i] + conj(L[j])) * R[i] / (double) (2.0 * S);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (double) (2.0 * S) / complex<double> (1i);
	}
	fft(outl);
	fft(outs);
	for(int i = 0; i < A + B - 1; i++){
		long long av = (long long) (real(outl[i]) + .5);
		long long bv = (long long) (imag(outl[i]) + .5) + (long long) (real(outs[i]) + .5);
		long long cv = (long long) (imag(outs[i]) + .5);
		ret[i] = ((av % MOD * cut + bv) % MOD * cut + cv) % MOD;
	}
	return ret;
}

vector<long long> qikpow(long long e){
	if(!e){
		return {1LL};
	}
	auto ret = qikpow(e / 2);
	ret = convMod(ret, ret);
	if(e & 1){
		ret = convMod(ret, base);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> D;
	N /= 2;
	for(int d = 0; d < D; d++){
		int k;
		cin >> k;
		base[k] = 1;
	}
	auto genfunc = qikpow(N);
	long long out = 0;
	for(long long n : genfunc){
		out += n * n;
		out %= MOD;
	}
	cout << out;
}
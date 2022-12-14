#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int w[8];

struct Matrix{
	int a[128][128];
	int n, m;
	Matrix(int n_ = 0, int m_ = 0){
		for (int i = 0; i < 128; i++)
			for (int j = 0; j < 128; j++)
				a[i][j] = 0;
		n = n_, m = m_;
	}
	Matrix operator * (const Matrix & oth){
		assert(m == oth.n);
		Matrix ret = Matrix(n, oth.m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < oth.m; j++)
				for (int k = 0; k < m; k++)
					ret.a[i][j] = (ret.a[i][j] + 1ll * this->a[i][k] * oth.a[k][j]) % mod;
		return ret;
	}
};

Matrix power(Matrix a, int b){
	if (b == 1)
		return a;
	Matrix ret = power(a, b / 2);
	ret = ret * ret;
	if (b & 1)
		ret = a * ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 7; i++)
		cin >> w[i];
	Matrix A = Matrix(1, 1);
	A.a[0][0] = 1;
	for (int n = 1; n <= 7; n++){
		for (int mask = 0; mask < (1<<(n-1)); mask++)
			swap(A.a[0][mask], A.a[0][mask^(1<<(n-1))]);
		A.m *= 2;
		if (w[n] == 0)
			continue;
		Matrix X = Matrix((1<<n), (1<<n));
		for (int m1 = 0; m1 < (1<<n); m1++){
			for (int m2 = 0; m2 < (1<<n); m2++){
				int lastdp = 1, lastpd = 0;
				for (int j = 0; j < n; j++){
					int dp, pd;
					if ((m1 & (1<<j)) and (m2 & (1<<j))){
						dp = lastpd;
						pd = lastdp + lastpd;
					}
					else
						dp = pd = lastdp + lastpd;
					lastdp = dp, lastpd = pd;
				}
				X.a[m1][m2] = lastdp;
			}
		}
		A = A * power(X, w[n]);
	}
	cout << A.a[0][127] << '\n';
}
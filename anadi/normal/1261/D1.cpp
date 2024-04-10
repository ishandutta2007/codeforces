#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 998244353;
const LL INF = 1LL * MX * MX;

namespace NTT {
	#define SZ(x) (x).size()
	#define rep(i,a,b) for(int i = (a); i < (b); ++i)
	typedef unsigned long long ull;
	typedef unsigned long long T;//ma byc unsigned int albo ll albo ull
	//jak sie przekrecimy przez inta to zly wynik!

	const T P = 998244353;//2013265921; //15*2^27+1
	const T ROOT = 570984967;//440564289; //root
	const int MN=21; // musi by < 26
	T omega[1<<MN];


	T pw (T x, T n) {
		T res = 1;
		while(n) {
		    if (n&1) res = (ull)res*x%P;
		    x = (ull)x*x%P;
		    n>>=1;
		}
		return res;
	}

	void fft(vector<T> &a, int n, bool inverse=false) {
		int N = 1<<n;
		a.insert(a.end(), N-SZ(a), 0);
		T root = pw(ROOT, (1<<23)/N*(inverse?(N-1):1));
		omega[0] = 1;
		rep(i, 1, N) omega[i] = (ull)omega[i-1]*root%P;
		rep(i, 0, n) {
		    rep(j, 0, 1<<i) {
		        rep(k, 0, 1<<(n-i-1)) {
		            int s = (j<<(n-i))+k;
		            int t = s + (1<<(n-i-1));
		            T w = omega[k<<i];
		            T temp = a[s] + a[t];
		            if (temp >= P) temp -= P;
		            T t2 = a[s] - a[t] + P;
		            a[t] = (ull) w * t2 % P;
		            a[s] = temp;
		        }
		    }
		}
		rep(i, 0, N) {
		    int x=i,y=0;
		    rep(j, 0, n)  y=(y<<1)+(x&1), x>>=1;
		    if (i<y) swap(a[i],a[y]);
		}
		if (inverse) {
		    T inv = pw(N, P-2);
		    rep(i, 0, N) a[i] = (ull)a[i]*inv%P;
		}
	}
	vector<T> conv(vector<T> A, vector<T> B) {
		int n = 31-__builtin_clz(2*(SZ(A)+SZ(B))-1);
		fft(A, n);
		fft(B, n);
		rep(i, 0, (1<<n)) A[i] = (ull) A[i] * B[i] % P;
		fft(A, n, true);
		return A;
	}
	vector<T> square(vector<T> A) {
		int n = 32-__builtin_clz(2*SZ(A)-1);
		fft(A, n);
		rep(i, 0, (1<<n)) A[i] = (ull) A[i] * A[i] % P;
		fft(A, n, true);
		return A;
	}
}

int n, k;
int in[N];
int fac[N];
int facR[N];

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &in[i]);
	in[n + 1] = in[1];
	
	if(k == 1) {
		puts("0");
		exit(0);
	}
	
	int m = 0;
	for(int i = 1; i <= n; ++i)
		m += in[i] != in[i + 1];
	
	fac[0] = 1;
	for(int i = 1; i <= n; ++i)
		fac[i] = 1LL * fac[i - 1] * i % MX;
	
	facR[n] = NTT::pw(fac[n], MX - 2);
	for(int i = n; i >= 1; --i)
		facR[i - 1] = 1LL * facR[i] * i % MX;
	
	vector <unsigned long long> Left(m + 1), Right(m + 1);
	for(int i = 0; i <= m; ++i) {
		Left[i] = 1LL * fac[m] * facR[i] % MX;
		Right[i] = facR[i];
	}
	
	auto ans = NTT::conv(Left, Right);
/*	vector <LL> ans(m + 1, 0);
	for(int i = 0; i <= m; ++i)
		for(int j = 0; j <= i; ++j)
			ans[i] = (ans[i] + 1LL * Left[j] * Right[i - j]) % MX;
*/
	for(int i = 0; i <= m; i += 2)
		ans[i] = (ans[i] + MX - 1LL * fac[m] * facR[i / 2] % MX * facR[i / 2] % MX) % MX;
	
	LL result = 0;
	for(int i = 0; i <= m; ++i)
		result += 1LL * ans[i] * facR[2] % MX * facR[m - i] % MX * NTT::pw(k - 2, m - i) % MX;
	
	result %= MX;
	result = result * NTT::pw(k, n - m) % MX;
	result = (result + MX) % MX;
	printf("%lld\n", result);
	return 0;
}
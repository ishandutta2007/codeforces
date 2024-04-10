#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ckmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using VI=vector<int>;

namespace FFT
{
	struct complex { double real, imag; };
	complex operator+(const complex &x, const complex &y) { return { x.real + y.real, x.imag + y.imag }; }
	complex operator-(const complex &x, const complex &y) { return { x.real - y.real, x.imag - y.imag }; }
	complex operator*(const complex &x, const complex &y) { return { x.real * y.real - x.imag * y.imag, x.real * y.imag + x.imag * y.real }; }

	void FFT(vector<complex> &a, bool inv)
	{
		int n = a.size();
		int e = 0;
		for (; n != (1 << e); e++);
		vector<int> bitrev(n);
		bitrev[0] = 0;
		for (int i = 1; i < n; ++i)
		{
			bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (e - 1));
			if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
		}
		const double pi = acos(-1.0);
		vector<complex> c(n / 2);
		complex w = { cos(2.0 * pi / n), sin(2.0 * pi / n) * (inv ? -1 : 1) };
		c[0] = { 1.0, 0.0 };
		for (int i = 1; i < n / 2; ++i) c[i] = c[i - 1] * w;
		for (int t = 1; t < n; t *= 2) for (int d = n / 2 / t, i = 0; i < n; i += 2 * t)
		{
			complex* p = &c[0];
			complex* l = &a[i];
			complex* r = &a[i + t];
			for (int j = 0; j < t; ++j)
			{
				complex z = *r * *p;
				*r = *l - z;
				*l = *l + z;
				++l;
				++r;
				p += d;
			}
		}
		if (inv) for (int i = 0; i < n; ++i) { a[i].real = a[i].real / n; a[i].imag = a[i].imag / n; }
	}

	vector<double> convolution(const vector<double>& x, const vector<double>& y)
	{
		if (x.empty() || y.empty()) return {};
		int m = x.size() + y.size() - 1;
		int n = m;
		for (; n & (n - 1); ++n);
		vector<complex> a(n), b(n);
		for (int i = 0; i < n; ++i) a[i].real = a[i].imag = 0.0;
		for (int i = 0; i < static_cast<int>(x.size()); ++i) a[i].real = x[i];
		FFT(a, false);
		for (int i = 0; i < n; ++i) b[i].real = b[i].imag = 0.0;
		for (int i = 0; i < static_cast<int>(y.size()); ++i) b[i].real = y[i];
		FFT(b, false);
		for (int i = 0; i < n; ++i) a[i] = a[i] * b[i];
		FFT(a, true);
		vector<double> z(m);
		for (int i = 0; i < m; ++i) z[i] = a[i].real;
		return z;
	}

}  // FFT

const int MOD=(1<<19);

int calc(const VI& a,int s)
{
	int n=SIZE(a);
	int k=0;
	int ret=0;
	for (int i=n-1;i>=0;i--)
	{
		ckmin(k,i);
		for (;k<i && a[i]+a[k]<s;++k);
		ret^=k;
	}
	return ret%2;
}
int solve(VI a)
{
	int n=SIZE(a);
	VI c(MOD);
	for (int x:a) ++c[x%MOD];

	int ret=0;
	REP(i,MOD) if (c[i]>=2)
	{
		int64 e=(int64)c[i]*(c[i]-1)/2;
		if (e%2!=0) ret^=(i+i)%MOD;
		c[i]%=2;
	}
	vector<double> c1(MOD);
	REP(i,MOD) c1[i]=c[i];
	vector<double> c2=FFT::convolution(c1,c1);
	REP(i,MOD) if (c[i]) --c2[(i+i)%MOD];
	REP(i,SIZE(c2)) c2[i]/=2;
	REP(i,MOD) if ((int)(c2[i]+c2[i+MOD]+0.5)%2==1) ret^=i;

	sort(ALL(a));
	int last=0;
	for (int i=0;i<=20000000;i+=MOD)
	{
		int next=calc(a,i+MOD);
		if ((last+next)%2!=0) ret^=i;
		last=next;
	}
	return ret;
}
int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n;
	while (cin>>n)
	{
		VI a(n);
		REP(i,n) cin>>a[i];
		int ret=solve(a);
		printf("%d\n",ret);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}
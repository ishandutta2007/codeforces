#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;

namespace FFT
{
	struct complex { double real, imag; };
	complex operator+(const complex& x, const complex& y) { return { x.real + y.real, x.imag + y.imag }; }
	complex operator-(const complex& x, const complex& y) { return { x.real - y.real, x.imag - y.imag }; }
	complex operator*(const complex& x, const complex& y) { return { x.real * y.real - x.imag * y.imag, x.real * y.imag + x.imag * y.real }; }

	void FFT(vector<complex>& a, bool inv)
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

	vector<double> convolution_brute_force(const vector<double>& x, const vector<double>& y)
	{
		int n = static_cast<int>(x.size());
		int m = static_cast<int>(y.size());
		if (n == 0 || m == 0) return {};
		vector<double> z(n + m - 1);
		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) z[i + j] += x[i] * y[j];
		return z;
	}

	vector<double> convolution(const vector<double>& x, const vector<double>& y)
	{
		if (x.empty() || y.empty()) return {};
		if (x.size() <= 256 && y.size() <= 256 || x.size() <= 32 || y.size() <= 32) return convolution_brute_force(x, y);
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

int main()
{
#ifdef _MSC_VER
	freopen("input.txt","r",stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n,m,nq;
	while (cin>>n>>m>>nq)
	{
		VI a(n);
		REP(i,n) cin>>a[i];
		VI b(m);
		REP(i,m) cin>>b[i];
		VI q(nq);
		REP(i,nq) cin>>q[i];
		auto eval=[&](const VI& a,const VI& b) -> vector<int64>
		{
			vector<int64> ret(nq);
			if (SIZE(a)==0 || SIZE(b)==0) return ret;
			int ma=*max_element(ALL(a))+1;
			int mb=*max_element(ALL(b))+1;
			VD ca(ma);
			VD cb(mb);
			for (int x:a) ++ca[x];
			for (int x:b) ++cb[x];
			VD c=FFT::convolution(ca,cb);
			REP(i,SIZE(c)) c[i]=(int64)(c[i]+0.5);
			for (int i=SIZE(c)-2;i>=0;i--) c[i]+=c[i+1];
			REP(i,nq) if (q[i]<SIZE(c)) ret[i]+=(int64)(c[max(0,q[i])]+0.5);
			return ret;
		};
		auto calc=[&]() -> vector<int64> 
		{
			VI a2(n-1);
			REP(i,n-1) a2[i]=min(a[i],a[i+1]);
			VI b2(m-1);
			REP(i,m-1) b2[i]=min(b[i],b[i+1]);
			vector<int64> r1=eval(a,b);
			vector<int64> r2=eval(a,b2);
			vector<int64> r3=eval(a2,b);
			vector<int64> r4=eval(a2,b2);
			vector<int64> ret(nq);
			REP(i,nq) ret[i]=r1[i]-r2[i]-r3[i]+r4[i];
			return ret;
		};
		vector<int64> r1=calc();
		int ma=*max_element(ALL(a));
		REP(i,n) a[i]=ma+1-a[i];
		int mb=*max_element(ALL(b));
		REP(i,m) b[i]=mb+1-b[i];
		REP(i,nq) q[i]=ma+mb-q[i]+3;
		vector<int64> r2=calc();
		REP(i,nq) printf("%lld\n",r1[i]-r2[i]);
#ifndef _MSC_VER
		break;
#endif
	}
	return 0;
}
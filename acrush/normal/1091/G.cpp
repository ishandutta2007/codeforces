#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string.h>
#include <unordered_set>
#include <unordered_map>

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

class bigdecimal;
class bigint
{
public:
	bigint(int n = 0);
	bigint(int64_t n);
	bigint(const string &s);
	bigint(const char *s);
	virtual ~bigint() = default;

	int sign = 0;
	vector<int> a;
	int length() const { return static_cast<int>(a.size()); }

	bigint operator-() const;
	bigint& operator+=(const bigint &a);
	bigint& operator-=(const bigint &a);
	bigint& operator*=(const bigint &a);
	bigint& operator/=(const bigint &a);
	bigint& operator%=(const bigint &a);
	bigint& operator*=(int b);
	bigint& operator/=(int b);
	bigint& operator++();
	bigint operator++(int);
	bigint& operator--();
	bigint operator--(int);
	string to_string() const;
	int int_value() const;
	int64_t long_value() const;
	double double_value() const;
	bigint shift_left(int d) const;
	bigint shift_right(int d) const;

private:
	const static int BASE = 1000000000;
	const static int NUM_DIGITS = 9;

private:
	bigint(int sign, vector<int> a) : sign(sign), a(std::move(a)) { unify(); }

	void parse_from_long(int64_t m);
	void parse_from_string(const char *s);
	void allocate(int length);
	void unify();

	friend bool operator<(const bigint &a, const bigint &b);
	friend bool operator<=(const bigint &a, const bigint &b);
	friend bool operator>(const bigint &a, const bigint &b);
	friend bool operator>=(const bigint &a, const bigint &b);
	friend bool operator==(const bigint &a, const bigint &b);
	friend bool operator!=(const bigint &a, const bigint &b);
	friend bigint operator+(const bigint &a, const bigint &b);
	friend bigint operator-(const bigint &a, const bigint &b);
	friend bigint operator*(const bigint &a, const bigint &b);
	friend bigint operator*(const bigint &a, int b);
	friend bigint operator*(int b, const bigint &a);
	friend bigint multiply_brute_force(const bigint& a, const bigint& b);

	friend pair<bigint, bigint> div_and_mod(const bigint& a, const bigint& b);
	friend bigint operator/(const bigint &a, const bigint &b);
	friend bigint operator%(const bigint &a, const bigint &b);

	friend pair<bigint, int> div_and_mod(const bigint& a, int b);
	friend bigint operator/(const bigint &a, int b);
	friend int operator%(const bigint &a, int b);
	friend bigint abs(const bigint &m);
	friend istream& operator>>(istream &stream, bigint &a);
	friend ostream& operator<<(ostream &stream, const bigint &a);
	friend bigint sqrt(const bigint &m);
	friend bigint gcd(const bigint &a, const bigint &b);
	friend bigint lcm(const bigint &a, const bigint &b);
	friend bigint pow(const bigint &p, int64_t e);

	friend class bigdecimal;
};

void bigint::unify()
{
	for (; !a.empty() && a.back() == 0; a.pop_back());
	if (a.empty()) sign = 1;
}
bigint::bigint(int m)
{
	parse_from_long(m);
}
bigint::bigint(int64_t m)
{
	parse_from_long(m);
}
void bigint::parse_from_long(int64_t m)
{
	sign = (m >= 0) ? 1 : -1;
	m = abs(m);
	int length = 0;
	for (int64_t t = m; t > 0; t /= BASE) ++length;
	allocate(length);
	for (int i = 0; i < length; ++i, m /= BASE) a[i] = m % BASE;
	unify();
}
void bigint::allocate(int length)
{
	a.resize(length);
	fill(a.begin(), a.end(), 0);
}
bigint::bigint(const string &s)
{
	parse_from_string(s.c_str());
}
bigint::bigint(const char *s)
{
	parse_from_string(s);
}
void bigint::parse_from_string(const char *s)
{
	int p = 0;
	sign = 1;
	if (s[0] == '-' || s[0] == '+') { sign = ((s[0] == '-') ? -1 : 1); ++p; }
	int L = 0;
	while (s[p + L] >= '0' && s[p + L] <= '9') L++;
	allocate((L + NUM_DIGITS - 1) / NUM_DIGITS);
	for (int i = 0; i < L; ++i) a[(L - i - 1) / NUM_DIGITS] = a[(L - i - 1) / NUM_DIGITS] * 10 + (s[p + i] - '0');
	unify();
}
bigint bigint::shift_left(int d) const
{
	if (a.empty() || d <= 0) return *this;
	vector<int> b(d);
	b.insert(b.end(),a.begin(),a.end());
	return bigint(sign, b);
}
bigint bigint::shift_right(int d) const
{
	if (a.empty() || d <= 0) return *this;
	if (d >= static_cast<int>(a.size())) return bigint(0);
	return bigint(sign, vector<int>(a.begin() + d, a.end()));
}
bool operator<(const bigint &a, const bigint &b)
{
	if (a.sign != b.sign) return a.sign < b.sign;
	int s = a.sign;
	if (a.length() != b.length()) return s * a.length() < s * b.length();
	for (int i = a.length() - 1; i >= 0; i--) if (a.a[i] != b.a[i]) return s * a.a[i] < s*b.a[i];
	return false;
}
bool operator<=(const bigint &a, const bigint &b)
{
	return !(b < a);
}
bool operator>(const bigint &a, const bigint &b)
{
	return (b < a);
}
bool operator>=(const bigint &a, const bigint &b)
{
	return !(a < b);
}
bool operator==(const bigint &a, const bigint &b)
{
	return a.sign == b.sign && a.a == b.a;
}
bool operator!=(const bigint &a, const bigint &b)
{
	return !(a == b);
}
bigint bigint::operator-() const
{
	bigint c = *this;
	c.sign = -c.sign;
	c.unify();
	return c;
}

bigint abs(const bigint &m)
{
	bigint c = m;
	c.sign = abs(c.sign);
	c.unify();
	return c;
}

bigint operator+(const bigint &a, const bigint &b)
{
	if (a.length() == 0) return b;
	if (b.length() == 0) return a;
	if (a.sign == b.sign)
	{
		vector<int> r(max(a.length(), b.length()) + 1);		
		for (int t = 0, i = 0; i < static_cast<int>(r.size()); i++)
		{
			if (i < a.length()) t += a.a[i];
			if (i < b.length()) t += b.a[i];
			if (t >= bigint::BASE) r[i] = t - bigint::BASE, t = 1;
			else r[i] = t, t = 0;
		}
		return bigint(a.sign, r);
	}
	return a - (-b);
}

bigint operator-(const bigint &a, const bigint &b)
{
	if (a.length() == 0) return -b;
	if (b.length() == 0) return a;
	if (a.sign == b.sign)
		if (abs(a) >= abs(b))
		{
			vector<int> r(a.length());
			for (int t = 0, i = 0; i < static_cast<int>(r.size()); i++)
			{
				if (i < a.length()) t += a.a[i];
				if (i < b.length()) t -= b.a[i];
				if (t < 0) r[i] = t + bigint::BASE, t = -1;
				else r[i] = t, t = 0;
			}
			return bigint(a.sign, r);
		}
		else
			return -(b - a);
	return a + (-b);
}

bigint& bigint::operator++()
{
	*this += 1;
	return *this;
}

bigint bigint::operator++(int)
{
	auto t = *this;
	++(*this);
	return t;
}

bigint& bigint::operator--()
{
	*this -= 1;
	return *this;
}

bigint bigint::operator--(int)
{
	auto t = *this;
	--(*this);
	return t;
}

istream& operator>>(istream &stream, bigint &v)
{
	string s;
	stream >> s;
	v = bigint(s);
	return stream;
}

ostream& operator<<(ostream &stream, const bigint &v) 
{
	if (v.sign == -1) stream << '-';
	stream << (v.a.empty() ? 0 : v.a.back());
	for (int i = v.length() - 2; i >= 0; --i)
		stream << setw(bigint::NUM_DIGITS) << setfill('0') << v.a[i];
	return stream;
}

string bigint::to_string() const
{
	ostringstream sout;
	sout << *this;
	sout.flush();
	return sout.str();
}

int bigint::int_value() const
{
	int r = 0;
	for (int i = length() - 1; i >= 0; i--) r = r * BASE + a[i];
	r *= sign;
	return r;
}
int64_t bigint::long_value() const
{
	int64_t r = 0;
	for (int i = length() - 1; i >= 0; i--) r = r * BASE + a[i];
	r *= sign;
	return r;
}
double bigint::double_value() const
{
	double r = 0;
	for (int i = length() - 1; i >= 0; i--) r = r * BASE + a[i];
	r *= sign;
	return r;
}

pair<bigint, bigint> div_and_mod(const bigint& a1, const bigint& b1)
{
	if (a1.length() == 0 || b1.length() == 0) return make_pair(0, 0);
	int norm = bigint::BASE / (b1.a.back() + 1);
	bigint a = abs(a1) * norm;
	bigint b = abs(b1) * norm;
	bigint r = 0;
	vector<int> q(a.length());
	for (int i = a.length() - 1; i >= 0; i--)
	{
		r *= bigint::BASE;
		r += a.a[i];
		int s1 = (r.length() <= b.length() ? 0 : r.a[b.length()]);
		int s2 = (r.length() <= b.length() - 1 ? 0 : r.a[b.length() - 1]);
		int d = ((int64_t)bigint::BASE * s1 + s2) / b.a.back();
		r -= b * d;
		while (r < 0) r += b, --d;
		q[i] = d;
	}
	int sign = a1.sign * b1.sign;
	return make_pair(bigint(sign, q), r / (norm * a1.sign));
}

bigint multiply_brute_force(const bigint &a, const bigint &b)
{
	if (a.length() == 0 || b.length() == 0) return 0;
	if (a.length() > b.length()) return multiply_brute_force(b, a);
	vector<int> r(a.length() + b.length());
	for (int i = 0; i < a.length(); i++)
	{
		int64_t t = 0;
		int64_t m = a.a[i];
		int at = i;
		for (int j = 0; j < b.length(); ++j, ++at)
		{
			t += r[at] + m * b.a[j];
			r[at] = t % bigint::BASE;
			t /= bigint::BASE;
		}
		for (; t > 0; ++at)
		{
			t += r[at];
			r[at] = t % bigint::BASE;
			t /= bigint::BASE;
		}
	}
	return bigint(a.sign * b.sign, r);
}

vector<int64_t> split(const string& s, int L)
{
	int length = s.length();
	vector<int64_t> r((length + L - 1) / L);
	for (int i = length - 1; i >= 0; --i) r[i / L] = r[i / L] * 10 + (s[length - 1 - i] - '0');
	return r;
}

vector<int64_t> multiply_karatsuba(const vector<int64_t> &a, const vector<int64_t> &b)
{
	int n = a.size();
	vector<int64_t> res(n + n);
	if (n <= 16) 
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				res[i + j] += a[i] * b[j];
		return res;
	} 
	int k = (n >> 1);
	vector<int64_t> a1(a.begin(), a.begin() + k);
	vector<int64_t> a2(a.begin() + k, a.end());
	vector<int64_t> b1(b.begin(), b.begin() + k);
	vector<int64_t> b2(b.begin() + k, b.end()); 
	vector<int64_t> a1b1 = multiply_karatsuba(a1, b1);
	vector<int64_t> a2b2 = multiply_karatsuba(a2, b2);
	for (int i = 0; i < k; i++) a2[i] += a1[i];
	for (int i = 0; i < k; i++) b2[i] += b1[i];
	vector<int64_t> r = multiply_karatsuba(a2, b2);
	for (int i = 0; i < (int) a1b1.size(); i++) r[i] -= a1b1[i];
	for (int i = 0; i < (int) a2b2.size(); i++) r[i] -= a2b2[i];
	for (int i = 0; i < (int) r.size(); i++) res[i + k] += r[i];
	for (int i = 0; i < (int) a1b1.size(); i++) res[i] += a1b1[i];
	for (int i = 0; i < (int) a2b2.size(); i++) res[i + n] += a2b2[i];
	return res;
}

bigint operator*(const bigint &a, const bigint &b)
{
	if (a.length() == 0 || b.length() == 0) return 0;
	if (a.length() < 32 || b.length() < 32 || max(a.length(), b.length()) <= 256) return multiply_brute_force(a, b);
	int length = (a.length() + b.length()) * bigint::NUM_DIGITS;
	int L = 6;
	int p10 = 1000000;
	for (;L > 1 && (double)p10 * (double)p10 * (double)(length / L + 1) > pow(2.0, 60.0); --L, p10 /= 10);
	vector<int64_t> x = split(abs(a).to_string(), L);
	vector<int64_t> y = split(abs(b).to_string(), L);
	for (; x.size() < y.size(); ) x.push_back(0);
	for (; y.size() < x.size(); ) y.push_back(0);
	for (; x.size() & (x.size() - 1); ) x.push_back(0);
	for (; y.size() & (y.size() - 1); ) y.push_back(0);
	vector<int64_t> z = multiply_karatsuba(x, y);
	for (int i = 0; i < static_cast<int>(z.size()) - 1; ++i) z[i + 1] += z[i] / p10, z[i] %= p10;
	ostringstream sout;
	sout << static_cast<int>(z.back());
	for (int i = static_cast<int>(z.size()) - 2; i >= 0; --i) sout << setw(L) << setfill('0') << static_cast<int>(z[i]);
	sout.flush();
	return bigint(sout.str()) * (a.sign * b.sign);
}

bigint operator/(const bigint &a, const bigint &b)
{
	return div_and_mod(a, b).first;
}

bigint operator%(const bigint &a, const bigint &b)
{
	return div_and_mod(a, b).second;
}

bigint operator*(const bigint &a, int m)
{
	if (a.length() == 0 || m == 0) return 0;
	int sign = a.sign;
	if (m < 0) m = -m, sign = -sign;
	vector<int> r(a.length() + 2);
	int64_t t = 0;
	for (int i = 0; i < static_cast<int>(r.size()); i++)
	{
		if (i < a.length()) t += static_cast<int64_t>(a.a[i]) * m;
		r[i] = t % bigint::BASE;
		t /= bigint::BASE;
	}
	return bigint(sign, r);
}

bigint operator*(int m, const bigint &a)
{
	return a * m;
}

pair<bigint, int> div_and_mod(const bigint& a, int m)
{
	if (a.length() == 0 || m == 0) return make_pair(0, 0);
	int sign = a.sign;
	if (m < 0) m = -m, sign = -sign;
	vector<int> r(a.length());
	int64_t t = 0;
	for (int i = static_cast<int>(r.size()) - 1; i >= 0; i--)
	{
		t = t % m * bigint::BASE;
		if (i < a.length()) t += a.a[i];
		r[i] = static_cast<int>(t / m);
	}
	return make_pair(bigint(sign, r), a.sign * static_cast<int>(t % m));
}

bigint operator/(const bigint &a, int m)
{
	return div_and_mod(a, m).first;
}
int operator%(const bigint &a, int m)
{
	return div_and_mod(a, m).second;
}
bigint& bigint::operator+=(const bigint &m)
{
	return *this = (*this) + m;
}
bigint& bigint::operator-=(const bigint &m)
{
	return *this = (*this) - m;
}
bigint& bigint::operator*=(const bigint &m)
{
	return *this = (*this)*m;
}
bigint& bigint::operator/=(const bigint &m)
{
	return *this = (*this) / m;
}
bigint& bigint::operator%=(const bigint &m)
{
	return *this = (*this) % m;
}
bigint& bigint::operator*=(int m)
{
	return *this = (*this) * m;
}
bigint& bigint::operator/=(int m)
{
	return *this = (*this) / m;
}
bigint sqrt(const bigint &m)
{
	if (m.sign < 0) return 0;
	if (m.length() == 0) return 0;
	if (m.length() == 1) return static_cast<int>(sqrt(m.a[0] + 1e-2));
	vector<int> r((m.length() + 1) / 2);
	if (m.length() % 2 == 0)
		r.back() = max(1, static_cast<int>(sqrt(m.a.back() + 1e-2)));
	else
	{
		static const double HALF_POW = pow(10.0, bigint::NUM_DIGITS / 2);
		static const double BASE_POW = pow(10.0, bigint::NUM_DIGITS % 2);
		r.back() = max(1, static_cast<int>(sqrt(m.a.back() * BASE_POW + 1e-2) * HALF_POW));
	}
	bigint p(1, r);
	bigint q = p;
	while (1)
	{
		bigint y = (p + m / p) / 2;
		if (y == p || y == q) 
		{
			while (1)
			{
				bigint sqr_y = y * y;
				if (sqr_y > m) { --y; continue; }
				bigint sqr_y_plus_1 = sqr_y + y + y + 1;
				if (sqr_y_plus_1 <= m) { ++y; continue; }
				break;
			}
			return y;
		}
		q = p;
		p = y;
	}
	return m;
}
bigint gcd(const bigint &_a, const bigint &_b)
{
	bigint a = abs(_a);
	bigint b = abs(_b);
	while (b.length() > 0)
	{
		bigint d = a % b;
		a = b;
		b = d;
	}
	return a;
}
bigint lcm(const bigint &a, const bigint &b)
{
	return a * (b / gcd(a, b));
}
bigint pow(const bigint &p, int64_t e)
{
	if (e <= 0) return 1;
	bigint r = 1, t = p;
	while (e>0)
	{
		if (e & 1) r *= t;
		e /= 2;
		if (e > 0) t = t * t;
	}
	return r;
}

void read(bigint& m)
{
	string s;
	cin>>s;
	m=s;
}

void write(const bigint& m)
{
	printf("%s", m.to_string().c_str());
}

void writeln(const bigint& m)
{
	write(m);
	printf("\n");
}

void add(bigint p,vector<bigint>& a)
{
	if (p<=1) return;
	REP(i,SIZE(a)) if (a[i]==p) return;
	REP(i,SIZE(a))
	{
		bigint d=gcd(p,a[i]);
		if (d==1 || d==a[i]) continue;
		bigint t=a[i];
		a.push_back(a[i]/d);
		a[i]=d;
		p/=d;
	}
}

int main()
{
	double start_time=(double)clock()/CLOCKS_PER_SEC;
	bigint n;
	cin>>n;
	vector<bigint> a;
	a.push_back(n);
	REP(step,50)
	{
		double current_time=(double)clock()/CLOCKS_PER_SEC;
		if (current_time-start_time>5.5) break;
		string s=n.to_string();
		REP(i,LENGTH(s)) s[i]='0'+rand()%10;
		bigint x=bigint(s)%n;
		bigint sqr_x=x*x%n;
		printf("sqrt ");
		write(sqr_x);
		printf("\n");
		fflush(stdout);
		bigint y;
		cin>>y;
		if (x==y) continue;
		bigint z1=gcd((x+y)%n,n);
		bigint z2=gcd(abs(x-y),n);
		if (z1!=1 && z1!=n) add(z1,a);
		if (z2!=1 && z2!=n) add(z2,a);
	}
	printf("! %d",SIZE(a));
	for (const bigint& p:a) { printf(" "); write(p); }
	printf("\n");
	fflush(stdout);
	return 0;
}
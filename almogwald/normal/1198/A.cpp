#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <math.h> 
//#include <iomanip>
using namespace std;
#define M_PI 3.14159265358979323846  /* pi */
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define forrb(i,a,b,c) for(int i=a;i>b;i-=c)
#define fori(i,n) forr(i,0,n,1)
#define forib(i,n) forrb(i,n-1,-1,1)
#define forn(i,n) forr(i,1,n,1)
#define fornb(i,n) forrb(i,n-1,0,1)
#define fort(i,m,n) forr(i,m,n,1)
#define fortb(i,m,n) forrb(i,n-1,m-1,1)
#define forin(i,arr) fori(i,arr.size())
#define forinb(i,arr) forib(i,arr.size())
#define forrl(i,a,b,c) for(lol i=a;i<b;i+=c)
#define forrbl(i,a,b,c) for(lol i=a;i>b;i-=c)
#define foril(i,n) forrl(i,0,n,1)
#define foribl(i,n) forrbl(i,n-1,-1,1)
#define fornl(i,n) forrl(i,1,n,1)
#define fornbl(i,n) forrbl(i,n-1,0,1)
#define fortl(i,m,n) forrl(i,m,n,1)
#define fortbl(i,m,n) forrbl(i,n-1,m-1,1)
#define forinl(i,arr) foril(i,arr.size())
#define forinbl(i,arr) foribl(i,arr.size())
#define into(i) cin >> i;
#define def(i) lol i; into(i)
#define deft(t,i) t i; into(i)
#define defl(i) lol i; into(i)
#define defs(i) string i; into(i)
#define defn def(n)
#define defp def(p)
#define defm def(m)
#define defk def(k)
#define defa def(a)
#define defb def(b)
#define defc def(c)
#define defd def(d)
#define vec(a) vector<a>
#define co cout <<
#define out(a) cout << a <<' ';
#define el << endl;
#define ell << '\n';
#define outv(arr,n) fori(i,n){out(arr[i])} co "" el
#define cas(p) co "Case #" << p+1 <<": ";
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define maxi 1000000007
#define maxiu 4294967295
#define lmaxi 100000000000000007
#define mod %maxi
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
typedef vector<int> veci;
typedef long long lol;
typedef unsigned long long ulol;
typedef unsigned int uint;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, lol> point;
typedef pair<point, point> poin;
typedef pair<lol, point> poing;
typedef pair<point, lol> poinf;
typedef vector<point> vecp;
#define poi(x,y) make_pair(x,y)
#define sizer (lol) 1e9
#define digss (lol) 9
struct BigNum {
	vecl value;
	void set(lol x) { value = *(new vecl); value.push_back(x); }
	void duplicate(BigNum other) { value = other.value; }
	void add(BigNum other) {
		vecl o = other.value;
		if (o.size() > value.size()) {
			vecl t = value;
			value = o;
			o = t;
		}
		forin(i, o) {
			value[i] += o[i];
			if (i < value.size() - 1 && value[i] >= sizer) {
				value[i + 1] += value[i] / sizer;
				value[i] = value[i] % sizer;
			}
		}
		if (value.back() >= sizer) {
			value.push_back(value.back() / sizer);
			value[value.size() - 2] = value[value.size() - 2] % sizer;
		}
	}
	void mul(lol mul) {
		forin(i, value) {
			value[i] *= mul;
		}
		fori(i, value.size() - 1) {
			if (value[i] >= sizer) {
				value[i + 1] += value[i] / sizer;
				value[i] = value[i] % sizer;
			}
		}
		if (value.back() >= sizer) {
			value.push_back(value.back() / sizer);
			value[value.size() - 2] = value[value.size() - 2] % sizer;
		}
	}
	long double div(BigNum other1, BigNum other2) {
		int s = value.size();
		long double current = value.back();
		if (s >= 2) {
			current += ((long double)value[s - 2]) / sizer;
		}
		if (s >= 3) {
			current += ((long double)value[s - 3]) / (sizer * sizer);
		}
		int s1 = other1.value.size();
		int s2 = other2.value.size();
		long double other = 0;
		if (s1 + s2 - 1 == s) {
			other += other1.value.back() * other2.value.back();
			if (s1 >= 2) {
				other += ((long double)other1.value[s1 - 2] * other2.value.back()) / sizer;
			}
			if (s2 >= 2) {
				other += ((long double)other2.value[s2 - 2] * other1.value.back()) / sizer;
			}
			if (s1 >= 3) {
				other += ((long double)other1.value[s1 - 3] * other2.value.back()) / (sizer * sizer);
			}
			if (s2 >= 3) {
				other += ((long double)other2.value[s2 - 3] * other1.value.back()) / (sizer * sizer);
			}
		}
		if (s1 + s2 - 1 == s - 1) {
			other += other1.value.back() * other2.value.back();
			if (s1 >= 2) {
				other += ((long double)other1.value[s1 - 2] * other2.value.back()) / sizer;
			}
			if (s2 >= 2) {
				other += ((long double)other2.value[s2 - 2] * other1.value.back()) / sizer;
			}
			other /= sizer;
		}
		if (s1 + s2 - 1 == s - 2) {
			other += other1.value.back() * other2.value.back();
			other /= sizer * sizer;
		}
		return other / current;
	}
	string stringify() {
		string out = to_string(value.back());
		forib(i, value.size() - 1) {
			string cur = to_string(value[i] + sizer);
			out += cur.substr(1);
		}
		return out;
	}
};
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
lol triangle(lol x) {
	return (((lol)(x + 1)) * (x)) / 2;
}
lol modInverse(lol a)
{
	lol m = maxi;
	lol y = 0, x = 1;
	while (a > 1)
	{
		lol q = a / m;
		lol t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) {
		x += maxi;
	}
	return x;
}
lol modInverse(lol a,lol b)
{
	lol m = b;
	lol y = 0, x = 1;
	while (a > 1)
	{
		lol q = a / m;
		lol t = m;
		m = a % m, a = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) {
		x += b;
	}
	return x;
}
lol pow(lol a, lol b) {
	if (a <= 1) {
		return a;
	}
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		return pow((a * a)mod, b / 2)mod;
	}
	return (a * pow((a * a)mod, b / 2))mod;
}
vecl dev(vecp divisors) {
	if (divisors.size() == 0) {
		vecl cur;
		cur.push_back(1);
		return cur;
	}
	lol x = divisors.back().first;
	lol n = divisors.back().second;
	divisors.pop_back();
	vecl ans = dev(divisors);
	vecl cur;
	lol xi = 1;
	fori(i, n + 1) {
		forin(j, ans) {
			cur.push_back(ans[j] * xi);
		}
		xi *= x;
	}
	return cur;
}
void add(veci& x, veci& y) {
	forin(i, x) {
		x[i] += y[i];
	}
}
struct pt
{
	lol x, y;

	lol d() const // squared length
	{
		return x * x + y * y;
	}
};
typedef vector<pt> vecpp;
#define intopt(a) into(a.x) into(a.y)

#define defpt(a) pt a;intopt(a)
inline pt operator-(const pt& a) { return { -a.x, -a.y }; }
inline pt operator+(const pt& a, const pt& b) { return { a.x + b.x, a.y + b.y }; }
inline pt operator-(const pt& a, const pt& b) { return { a.x - b.x, a.y - b.y }; }
inline lol operator*(const pt& a, const pt& b) { return a.x* b.y - a.y * b.x; } // cross product
inline bool operator<(const pt& a, const pt& b) { return a*b<0; }
inline lol operator/(const pt& a, const pt& b) { return a.x* b.x + a.y * b.y; } // dot product
inline bool operator==(const pt& a, const pt& b) { return a.x == b.x && a.y == b.y; } // equal
inline bool operator!=(const pt& a, const pt& b) { return a.x != b.x || a.y != b.y; } // not equal

pt o;
lol mo;
bool comp(pt a, pt b) {
	return (a - o) * (b - o) < 0;
}
int n;
vecl mull(vecl& a, vecl& b) {
	vecl c(n);
	fori(i, n) {
		fori(j, n) {
			c[(i ^ j)] = (c[(i ^ j)] + a[i] * b[j])mod;
		}
	}
	return c;
}
#define logn 20
pt func(pt a, pt b) {
	if (a.x < b.x) {
		return a;
	}
	if (a.x > b.x) {
		return b;
	}
	return { a.x,(a.y + b.y)mod };
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	defn
		defk
		vecl a(n);
	fori(i, n) {
		into(a[i])
	}
	sort(all(a));
	int num = (k * 8) / n;
	lol dif = maxi;
	if (num < 29) {
		dif = 1 << num;
	}
	int j = 0;
	int ans = 1;
	veci d(1);
	d[0] = 1;
	int maxm = 1;
	forn(i, n) {
		ans++;
		if (a[i] == a[i - 1]) {
			d[j]++;
		}
		else {
			d.push_back(1);
			j++;
			if (j >= dif) {
				ans -= d[j - dif];
			}
		}
		maxm = max(ans, maxm);
	}
	co n - maxm el
		ex
}
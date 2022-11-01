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
#include <iomanip>
#include <fstream>
#include <bitset>
#include <sstream>      
using namespace std;
#define M_PI 3.14159265358979323846 // pi 
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define forrb(i,a,b,c) for(int i=a;i>b;i-=c)
#define fori(i,n) forr(i,0,n,1)
#define forit(it,arr) for(auto it=arr.begin();it != arr.end();it++)
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
#define forpm(i) forr(i,-1,2,2)
#define into(i) cin >> i;
#define intov(arr,n) fori(kkkk,n){into(arr[kkkk])}
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
//#define vec(a) vector<a>
#define co cout <<
#define out(a) cout << (a) <<' ';
#define el << endl;
#define ell << '\n';
#define outv(arr,n) fori(i,n){out(arr[i])} co "" ell
#define outvv(arr,n,m) fori(j,n){outv(arr[j],m)}
#define cas(p) co "Case #" << p+1 <<": ";
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define seti set<int>
#define con continue;
#define br break;
#define maxi 1000000007
#define maxiu 4294967295
#define lmaxi 1000000000000000007
#define mod %maxi
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
#define getv(arr,n) fori(i,n) {into(arr[i])}
#define defv(arr,n) veci arr(n); fori(i,n) {into(arr[i])}
#define min2(a,b) a=min(a,b);
#define max2(a,b) a=max(a,b);
#define vec vector
#define ff first
#define ss second
typedef vector<int> veci;
typedef long long lol;
typedef unsigned long long ulol;
typedef unsigned int uint;
typedef vector<lol> vecl;
typedef vector<uint> vecui;
typedef vector<ulol> vecul;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, lol> point;
#define setp set<point>
#define bmod %99999999999899999
typedef pair<point, point> poin;
typedef pair<long double, long double> pointd;
typedef pair<lol, point> poing;
typedef pair<point, lol> poinf;
typedef vector<point> vecp;
#define poi(x,y) make_pair(x,y)
struct BigNum {
#define sizer (lol) 1e9
#define digss (lol) 9
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
	return ((x + 1) * x) / 2;
}
lol antitriangle(lol x) {
	lol low = 0, high = maxi;
	while (low < high) {
		lol mid = (low + high) / 2;
		if (triangle(mid) < x) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	return low;
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
lol modInverse(lol a, lol b)
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
bool isprime(lol a) {
	if (a == 1) {
		return false;
	}
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}
void add(veci & x, veci & y) {
	forin(i, x) {
		x[i] += y[i];
	}
}
vecl mul(vecl x, lol a) {
	forin(i, x) {
		x[i] = (x[i] * a)mod;
	}
	return x;
}
vecl add(vecl x, vecl & y) {
	forin(i, x) {
		x[i] = (x[i] + y[i])mod;
	}
	return x;
}
#define logn 22
int lca(vector<veci>& f, veci& depth, int a, int b) {
	if (depth[a] < depth[b]) {
		swap(a, b);
	}
	fori(k, logn) {
		if ((depth[a] - depth[b])&(1<<k)) {
			a = f[k][a];
		}
	}
	if (a == b) {
		return a;
	}
	forib(k, logn) {
		if (f[k][a] != f[k][b]) {
			a = f[k][a];
			b = f[k][b];
		}
	}
	return f[0][a];
}
struct pt
{
#define intopt(a) into(a.x) into(a.y)
#define defpt(a) pt a;intopt(a)
	lol x, y;
	lol d() const // squared length
	{
		return x * x + y * y;
	}
};
typedef vector<pt> vecpp;
inline pt operator-(const pt & a) { return { -a.x, -a.y }; }
inline pt operator+(const pt & a, const pt & b) { return { a.x + b.x, a.y + b.y }; }
inline pt operator-(const pt & a, const pt & b) { return { a.x - b.x, a.y - b.y }; }
inline lol operator*(const pt & a, const pt & b) { return a.x* b.y - a.y * b.x; } // cross product
inline bool operator<(const pt & a, const pt & b) { return a * b < 0; }
bool llll(const pt & a, const pt & b) { return a * b > 0; }
inline bool operator<=(const pt & a, const pt & b) { return a * b <= 0; }
inline lol operator/(const pt & a, const pt & b) { return a.x* b.x + a.y * b.y; } // dot product
inline bool operator==(const pt & a, const pt & b) { return a.x == b.x && a.y == b.y; } // equal
inline bool operator!=(const pt & a, const pt & b) { return a.x != b.x || a.y != b.y; } // not equal
pt o = { 0 ,0 };
bool comp(pt a, pt b) {
	return (a - o) * (b - o) < 0;
}
bool decreasing(int a, int b) {
	return a>b;
}
#define digits 30
struct booleantree
{
	booleantree* left = NULL;
	booleantree* right = NULL;
	void add(int val) {
		booleantree* cur = this;
		forib(i, digits) {
			if ((val & (1 << i))) {
				if (cur->right == NULL) {
					cur->right = new booleantree();
				}
				cur = cur->right;
			}
			else {
				if (cur->left == NULL) {
					cur->left = new booleantree();
				}
				cur = cur->left;
			}
		}
	}
	int find(int val) {
		booleantree* cur = this;
		int ans = 0;
		forib(i, digits) {
			if ((val & (1 << i))) {
				if (cur->left == NULL) {
					cur = cur->right;
				}
				else {
					cur = cur->left;
					ans += (1 << i);
				}
			}
			else {
				if (cur->right == NULL) {
					cur = cur->left;
				}
				else {
					cur = cur->right;
					ans += (1 << i);
				}
			}
		}
		return ans;
	}
};
veci dummy;
#define maxs 300*300+1
lol funcc(veci x,int k) {
	veci l;
	forin(i, x) {
		if (x[i]) {
			l.push_back(i);
		}
	}
	lol ans = 0;
	veci a(k);
	while (a[0] < l.size()) {
		int all = 0;
		fori(i, k) {
			all |= l[a[i]];
		}
		if (all == (1 << k) - 1) {
			lol sum = 1;
			int num = 1;
			fori(i, k) {
				sum *= x[l[a[i]]];
				x[l[a[i]]]--;
				if (i > 0 && a[i] == a[i - 1]) {
					num++;
					sum /= num;
				}
				else {
					num = 1;
				}
			}
			ans += sum;
			fori(i, k) {
				x[l[a[i]]]++;
			}
		}
		int i = k - 1;
		while (i > 0 && a[i] == l.size() - 1) {
			i--;
		}
		a[i++]++;
		while (i < k) {
			a[i] = a[i - 1];
			i++;
		}
	}
	return ans;
}
int main() {
	//ofstream cout("deleg.out");
	//ifstream cin("deleg.in");
	//
	ios::sync_with_stdio(0);
	cin.tie(0);
	defm
		fori(i, m) {
		defn
			if (n == 1) {
				co -1 el
			}
			else {
				co 8;
					forn(i, n) {
						co 9;
				}
					co "" el
			}
	}
	ex
}
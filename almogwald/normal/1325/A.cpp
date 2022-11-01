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
typedef vector<int> veci;
typedef long long lol;
typedef unsigned long long ulol;
typedef unsigned int uint;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, lol> point;
#define setp set<point>
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
#define logn 20
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
int n,k;
vecp remeber;
point test(veci restt, int me, int pos) {
	if (remeber[pos].first=-1) {
		veci x = restt;
		x.resize(pos * 2);
		x.push_back(me);
		fort(i, pos * 2,2*n-1) {
			x.push_back(restt[i]);
		}
		if (me > n + 1) {
			veci emptyes(n);
			veci last(n);
			veci nekt(n);
			emptyes[0] = 1;
			forn(i, n) {
				last[i] = i - 1;
				nekt[i] = i + 1;
			}
			last[1] = n - 1;
			nekt[n - 1] = 1;
			int toerase = (x[0] > me) + (x[1] > me);
			fort(i, n - toerase,n) {
				nekt[last[i]] = nekt[i];
				last[nekt[i]] = last[i];
				emptyes[i] = 1;
			}
			forn(i, n) {
				int toerase = (x[2*i] > me) + (x[2*i+1] > me);
				if (toerase > 1) {
					int cur = last[i];
					nekt[last[cur]] = nekt[cur];
					last[nekt[cur]] = last[cur];
					emptyes[cur] = 1;
				}
				if (toerase > 0) {
					nekt[last[i]] = nekt[i];
					last[nekt[i]] = last[i];
					emptyes[i] = 1;
				}
			}
			int cur = pos;
			while (emptyes[(n+cur)%n]) {
				cur--;
			}
			remeber[pos] = { (n + cur) % n , cur < 0 };
		}
		else {//1=me 0<me 2 >me
			int curmax = (x[0] > me) + (x[0] >= me);
			vec<queue<int>> qq(3);
			forn(i, 2 * n) {
				int cur = (x[i] > me) + (x[i] >= me);
				qq[cur].push(i / 2);
			}
			int ones_show = curmax==1;
			int turn = 0;
			while (ones_show < 2) {
				int competitor = 3;
				fori(i, 3) {
					if (!qq[i].empty() && qq[i].front() <= turn) {
						competitor = i;
						qq[i].pop();
						br
					}
				}
				if (competitor == 1) {
					ones_show++;
				}
				if (curmax > competitor) {
					swap(curmax, competitor);
				}
				qq[competitor].push(turn + n);
				turn++;
			}
			remeber[pos] = { (n-1 -k+turn + (k/n)*n) % n , ((k- turn) / n) };
		}
	}
	return remeber[pos];
}
point binaryserch(veci& restt, int me, int low, int high) {
	point a	= test(restt, me, low);
	point b = test(restt, me, high);
	if (a.second == b.second) {
		while (low < high) {
			int mid = (low + high+1) / 2;
			point b = test(restt, me, mid);
			if (b.first == a.first) {
				low = mid;
			}
			else {
				high = mid - 1;
			}
		}
		return { a.first,low };
	}
	int curlow = low,curhigh=high-1;
	while (curlow < curhigh) {
		int mid = (curlow + curhigh + 1) / 2;
		point b = test(restt, me, mid);
		if (b.second == a.second) {
			curlow = mid;
		}
		else {
			curhigh = mid-1;
		}
	}
	int mid = curlow;
	a = binaryserch(restt, me, low, mid);
	b = binaryserch(restt, me, mid+1 , high);
	if (a.first >= b.first) {
		swap(a, b);
	}
	return a;
}
int main() {
	//ofstream cout("deleg.out");
	//ifstream cin("deleg.in");
	//
	ios::sync_with_stdio(0);
	def(t)
		fori(i, t) {
		defa
		out(1) co a-1 el
	}
	ex
}
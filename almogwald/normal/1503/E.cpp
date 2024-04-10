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
//#define M_PI (ldb)3.14159265358979323846 // pi 
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
#define outv(arr,n) fori(iii,n){out(arr[iii])} co "" el
#define outvv(arr,n,m) fori(jjj,n){outv(arr[jjj],m)}
#define cas(p) co "Case #" << p+1 <<": ";
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define seti set<int>
#define con continue;
#define br break;
#define maxi 998244353 
//1000000007 
#define maxiu 4294967295
#define lmaxi 2000000000000000007
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
#define pow2(x) (x)*(x)
#define pow3(x) (x)*(x)*(x)
#define getgraph(m,cons) fori(i,m){defa defb a--; b--; cons[a].push_back(b);cons[b].push_back(a);}
#define getdirectedgraph(m,cons) fori(i,m){defa defb a--; b--; cons[a].push_back(b);}
#define getwightedgraph(m,cons) fori(i,m){defa defb defc a--; b--; cons[a].push_back({b,c});cons[b].push_back({a,c});}
#define getwighteddirectedgraph(m,cons) fori(i,m){defa defb defc a--; b--; cons[a].push_back({b,c});}
typedef vector<int> veci;
typedef long long lol;
typedef unsigned long long ulol;
typedef unsigned int uint;
typedef long double ldb;
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
	return ((x - 1) * x) / 2;
}
lol antitriangle(lol x) {
	lol low = 0, high = 2 * maxi;
	while (low < high) {
		lol mid = (low + high + 1) / 2;
		if (triangle(mid) <= x) {
			low = mid;
		}
		else {
			high = mid - 1;
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
lol poww(lol a, lol b) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		return poww((a * a)mod, b / 2)mod;
	}
	return (a * poww((a * a)mod, b / 2))mod;
}
lol pow(lol a, lol b, lol m) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		return pow((a * a) % m, b / 2, m) % m;
	}
	return (a * pow((a * a) % m, b / 2, m)) % m;
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
#define logn 20
int lca(vector<veci> & f, veci & depth, int a, int b) {
	if (depth[a] < depth[b]) {
		swap(a, b);
	}
	fori(k, logn) {
		if ((depth[a] - depth[b]) & (1 << k)) {
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
int tredist(vector<veci>& f, veci& depth, int a, int b) {
	return depth[a]+ depth[b]- 2*depth[lca(f,depth,a,b)];
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
inline bool operator<(const pt& a, const pt& b) { if (a * b != 0) return a * b < 0; return a.d() < b.d(); }
bool llll(const pt & a, const pt & b) { return a * b > 0; }
inline bool operator<=(const pt & a, const pt & b) { return a * b <= 0; }
inline lol operator/(const pt & a, const pt & b) { return a.x* b.x + a.y * b.y; } // dot product
inline bool operator==(const pt & a, const pt & b) { return a.x == b.x && a.y == b.y; } // equal
inline bool operator!=(const pt & a, const pt & b) { return a.x != b.x || a.y != b.y; } // not equal
pt o = { 0 ,0 };
bool comp(pt a, pt b) {
	if ((a - o) * (b - o) != 0)
		return (a - o) * (b - o) < 0;
	return (a - o).d() < (b - o).d();
}
bool decreasing(int a, int b) {
	return a > b;
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
struct segtremin {
	vector<vecl> arr;
	int n;
	int curlogn;
	segtremin(int size, int logni) {
		n = size;
		curlogn = logni;
		arr.resize(curlogn);
		fori(i, curlogn) {
			arr[i].resize(size + 1);
		}
	}
	inline lol val(int start, int end) {
		if (end >= n) {
			end = n - 1;
		}
		if (start < 0) {
			start = 0;
		}
		lol mini = lmaxi;
		fori(i, curlogn) {
			if (start > end) {
				br
			}
			if ((end & 1) == 0) {
				min2(mini, arr[i][end]);
				end--;
				if (end < 0) {
					br
				}
			}
			if ((start & 1)) {
				min2(mini, arr[i][start])
					start++;
			}
			start /= 2;
			end /= 2;
		}
		return mini;
	}
	inline void add(int start, lol num) {
		arr[0][start] = num;
		forn(i, curlogn) {
			arr[i][start >> i] = min(arr[i - 1][(start >> i) * 2], arr[i - 1][(start >> i) * 2 + 1]);
		}
	}
};
struct segtreminplus {
	vecl arr;
	vector<vecl> arr2;
	vector<vecl> arr3;
	vector<vecl> arr4;
	int n;
	int curlogn;
	segtreminplus(int size, int logni) {
		n = size;
		curlogn = logni;
		arr.resize(size + 1);
		arr2.resize(curlogn);
		fori(i, curlogn) {
			arr2[i].resize(size + 1);
		}
		arr3.resize(curlogn);
		fori(i, curlogn) {
			arr3[i].resize(size + 1);
		}
		arr4.resize(curlogn);
		fori(i, curlogn) {
			arr4[i].resize(size + 1);
		}
	}
	inline void fixcate(int i, int j) {
		if (j < 0) {
			return;
		}
		if (i == 0) {
			arr2[i][j] = 1;
			arr3[i][j] = 1;
			arr4[i][j] = 1;
			return;
		}
		arr2[i][j] = max(arr2[i-1][2*j], arr2[i - 1][2 * j+1]);
		arr3[i][j] = arr3[i - 1][2 * j];
		arr4[i][j] = arr4[i - 1][2 * j+1];
		if (((2 * j + 1) << (i - 1)) < n && arr[((2 * j + 1) << (i - 1))] > arr[((2 * j + 1) << (i - 1)) - 1]) {
			arr2[i][j] = max(arr2[i][j], arr4[i - 1][2 * j]+ arr3[i - 1][2 * j+1]);
			if (arr2[i - 1][2 * j+1] == (1 << (i - 1))) {
				arr4[i][j] = arr4[i - 1][2 * j + 1] + arr4[i - 1][2 * j];
			}
			if (arr2[i - 1][2 * j] == (1 << (i - 1))) {
				arr3[i][j] = arr3[i - 1][2 * j + 1] + arr3[i - 1][2 * j];
			}
		}
	}
	inline lol val(int start) {
		if (start > 0) {
			return arr[start];
		}
		return arr2[curlogn-1][0];
	}
	inline void change(int start, lol num) {
		arr[start] = num;
		fori(i, curlogn) {
			fixcate(i, start >> i);
		}
	}
};
struct segtresum {
	vector<vecl> arr;
	int n;
	int curlogn;
	segtresum(int size, int logni) {
		n = size;
		curlogn = logni;
		arr.resize(curlogn);
		fori(i, curlogn) {
			arr[i].resize(size + 1);
		}
	}
	inline lol val(int start, int end) {
		/*if (end >= n) {
			end = n - 1;
		}
		if (start < 0) {
			start = 0;
		}*/
		lol mini = 0;
		fori(i, curlogn) {
			if (start > end) {
				br
			}
			if ((end & 1) == 0) {
				mini += arr[i][end];
				end--;
				if (end < 0) {
					br
				}
			}
			if ((start & 1)) {
				mini += arr[i][start];
				start++;
			}
			start /= 2;
			end /= 2;
		}
		return mini;
	}
	inline void add(int start, lol num) {
		arr[0][start] = num;
		forn(i, curlogn) {
			arr[i][start >> i] = arr[i - 1][(start >> i) * 2] + arr[i - 1][(start >> i) * 2 + 1];
		}
	}
	inline void radd(int start, lol num) {
		arr[0][start] += num;
		forn(i, curlogn) {
			arr[i][start >> i] = arr[i - 1][(start >> i) * 2] + arr[i - 1][(start >> i) * 2 + 1];
		}
	}
};
struct segtresumplus {
	vector<vecl> arr;
	vector<vecl> arrplus;
	vector<vecl> truearrplus;
	int n;
	int curlogn;
	segtresumplus(int size, int logni) {
		n = size;
		curlogn = logni;
		arr.resize(curlogn);
		fori(i, curlogn) {
			arr[i].resize(size + 1);
		}
		arrplus.resize(curlogn);
		fori(i, curlogn) {
			arrplus[i].resize(size + 1);
		}
		truearrplus.resize(curlogn);
		fori(i, curlogn) {
			truearrplus[i].resize(size + 1);
		}
	}
	inline void fix(int h, int s) {
		/*if (arrplus[h][s] == 0) {
			return;
		}
		arr[h][s] += arrplus[h][s] << h;
		if (h > 0) {
			arrplus[h - 1][2 * s] += arrplus[h][s];
			arrplus[h - 1][2 * s+ 1] += arrplus[h][s];
		}
		arrplus[h][s] = 0;*/
	}
	inline lol val(int start, int end) {
		/*if (end >= n) {
			end = n - 1;
		}
		if (start < 0) {
			start = 0;
		}*/
		forib(i, curlogn) {
			fix(i, start >> i);
			fix(i, end >> i);
		}
		lol mini = 0;
		fori(i, curlogn) {
			if (start > end) {
				br
			}
			if ((end & 1) == 0) {
				fix(i, end);
				mini += arr[i][end];
				mini += arrplus[i][end];
				fort(j, i + 1, curlogn) {
					mini += truearrplus[j][end >> (j-i)]<< i;
				}
				end--;
				if (end < 0) {
					br
				}
			}
			if ((start & 1)) {
				fix(i, start);
				mini += arr[i][start];
				mini += arrplus[i][start];
				fort(j, i + 1, curlogn) {
					mini += truearrplus[j][start >> (j - i)] << i;
				}
				start++;
			}
			start /= 2;
			end /= 2;
		}
		return mini;
	}
	inline void add(int start, lol num) {
		arr[0][start] = num;
		forn(i, curlogn) {
			arr[i][start >> i] = arr[i - 1][(start >> i) * 2] + arr[i - 1][(start >> i) * 2 + 1];
		}
	}
	inline void radd(int start,int end, lol num) {
		fori(i, curlogn) {
			if (start > end) {
				br
			}
			if ((end & 1) == 0) {
				truearrplus[i][end]+=num;
				fort(j,i, curlogn) {
					arrplus[j][end >> (j-i)] += num << i;
				}
				end--;
				if (end < 0) {
					br
				}
			}
			if ((start & 1)) {
				truearrplus[i][start] += num;
				fort(j, i, curlogn) {
					arrplus[j][start >> (j - i)] += num << i;
				}
				start++;
			}
			start /= 2;
			end /= 2;
		}
	}
};
struct unionfind{
	veci arr;
veci arr2;
int num;
unionfind(int size) {
	arr.resize(size);
	arr2.resize(size);
	num = size;
	fori(i, size) {
		arr[i] = i;
		arr2[i] = 1;
	}
}
int find(int a) {
	if (arr[a] == a) {
		return a;
	}
	return arr[a] = find(arr[a]);
}
inline void unioner(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		num--;
		if (arr2[a] > arr2[b]) {
			swap(a, b);
		}
		arr[a] = b;
		arr2[b] += arr2[a];
	}
}
};
string op(string s) {
	string ans;
	forinb(i, s) {
		ans.push_back(s[i]);
	}
	return ans;
}
void merge(veci& color, vector<veci>& allcolor, int l, int r) {
	if (color[l] == color[r]) {
		return;
	}
	l = color[l];
	r = color[r];
	if (allcolor[l].size() < allcolor[r].size()) {
		swap(l, r);
	}
	forin(j, allcolor[r]) {
		color[allcolor[r][j]] = l;
		allcolor[l].push_back(allcolor[r][j]);
	}
	allcolor[r].resize(0);
}
vecpp conv(vecpp a) {
	pt left = { 99999999999999,999999999999999 };
	forin(i, a) {
		if (a[i].x < left.x || a[i].x == left.x && a[i].y > left.y) {
			left = a[i];
		}
	}
	o = left;
	forin(i, a) {
		if (a[i] == left) {
			a[i] = a.back();
			a.pop_back();
			br
		}
	}
	sort(all(a), comp);
	vecpp conv(1, left);
	forin(i, a) {
		while (conv.size() > 1) {
			if ((a[i] - conv.back()) * (conv.back() - conv[conv.size() - 2]) <= 0) {
				conv.pop_back();
			}
			else {
				br
			}
		}
		conv.push_back(a[i]);
	}
	while (conv.size() > 1) {
		if ((left - conv.back()) * (conv.back() - conv[conv.size() - 2]) <= 0) {
			conv.pop_back();
		}
		else {
			br
		}
	}
	return conv;
}

vecl x(10000);
vecl y(10000);
lol choose(int n, int m) {
	lol sum = (x[n]*y[m])mod;
	sum= (sum* y[n-m])mod;
	return sum;
}
lol choose2(int n, int m) {
	return choose(n + m, m);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	x[0] = 1;
	forn(i, 10000) {
		x[i] = (x[i - 1] * i)mod;
	}
	fori(i, 10000) {
		y[i] = modInverse(x[i])mod;
	}
	defn defm
		lol sum = 0;
	fori(i, m-1) {
		lol cursum = 0;
		forib(j, n - 1) {
			lol cur = (choose2(m - i - 1, n - j - 2) * choose2(m - i - 2, j + 1))mod;
			cursum = (cursum + cur)mod;
			cur = (choose2(i + 1, j)* choose2(i,n-1-j))mod;
			sum = (sum + cursum * cur)mod;
			
		}

	}
	swap(n, m);
	fori(i, m - 1) {
		lol cursum = 0;
		forib(j, n - 1) {
			lol cur=0;
			if (j < n - 2) {
				j++;
				cur = (choose2(m - i - 1, n - j - 2) * choose2(m - i - 2, j + 1))mod;
				j--;
			}
			cursum = (cursum + cur)mod;
			cur = (choose2(i + 1, j) * choose2(i, n - 1 - j))mod;
			sum = (sum + cursum * cur)mod;
			
		}
	}
	co (sum*2 )mod el
	ex
}
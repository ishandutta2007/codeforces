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
using namespace std;
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
#define def(i) int i; into(i)
#define deft(t,i) t i; into(i)
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
#define outv(arr,n) fori(i,n){out(arr[i])} co "" el
#define cas(p) co "Case #" << p+1 <<": ";
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define maxi 1000000007
#define mod %1000000007;
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
#define _230 1073741824
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, lol> point;
typedef pair<point, point> poin;
typedef pair<lol, point> poing;
typedef vector<point> vecp;
#define poi(x,y) make_pair(x,y)
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
lol triangle(lol x) {
	return (((lol)(x - 1))*(x)) / 2;
}

point add(point x, point y) {
	return make_pair(x.first + y.first, x.second + y.second);
}
lol modInverse(lol a)
{
	lol m = 998244353;
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
		x += 998244353;
	}
	return x;
}
vector<vector<veci>> segtree(20);
veci merge(veci a, veci b) {
	veci c;
	a.push_back(99999999);
	b.push_back(99999999);
	int i = 0, j = 0;
	while (i + j < a.size() + b.size() - 2) {
		if (a[i] < b[j]) {
			c.push_back(a[i++]);
		}
		else {
			c.push_back(b[j++]);
		}
	}
	return c;
}
int serch(veci a, int b) {
	int min = 0,max=a.size();
	while (min < max) {
		int mid = (min + max) / 2;
		if (a[mid] >= b) {
			max = mid;
		}
		else {
			min = mid + 1;
		}
	}
	return min;
}
int myserch(int l, int r , int lv ,int max) {
	if (l > r) {
		return 0;
	}
	int a = (l - 1) >> lv;
	int b = (r + 1) >> lv;
	if (a + 1 >= b) {
		return myserch(l, r, lv - 1, max);
	}
	int x = ((a + 1) << lv) -1;
	int y = (a + 2) << lv;
	return myserch(l, x, lv - 1, max) + myserch(y, r, lv, max) + serch(segtree[lv][a+1],max);
}
int myserch(int l, int r) {
	return myserch(l, r, 19, l);
}

int main() {
	ios::sync_with_stdio(false);
	defn defk
		segtree[0].resize(n);
		map<int, veci> mapit;
	fori(i, n) {
		defa
			auto it = mapit.find(a);
		if (it == mapit.end()) {
			segtree[0][i].push_back(-1);
			mapit[a] = *(new veci);
		}
		else {
			if (mapit[a].size() < k) {
				segtree[0][i].push_back(-1);
			}
			else {
				segtree[0][i].push_back(mapit[a][mapit[a].size() - k]);
			}
		}
		mapit[a].push_back(i);
	}
	int j = 1;
	int nn = n;
	while (nn > 1) {
		nn /= 2;
		segtree[j].resize(nn);
		segtree = segtree;
		fori(i, nn) {
			segtree[j][i] = merge(segtree[j - 1][2 * i], segtree[j - 1][2 * i + 1]);
		}
		j++;
	}
	int last = 0;
	defm
	fori(i, m) {
		defa defb
		a = (a + last) % n;
		b = (b + last) % n;
		if (a > b) {
			int t = a;
			a = b;
			b = t;
		}
		last = myserch(a, b);
		co last el
	}
	
	ex
}
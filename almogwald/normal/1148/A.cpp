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
#define outv(arr,n) fori(i,n){out(arr[i])} co "" el
#define cas(p) co "Case #" << p+1 <<": ";
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define maxi 998244353
#define mod %998244353
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
typedef vector<int> veci;
typedef long long lol;
typedef unsigned long long ulol;
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
	return gcd(b, a % b);
}
lol triangle(lol x) {
	return (((lol)(x + 1)) * (x)) / 2;
}
point add(point x, point y) {
	return make_pair(x.first + y.first, x.second + y.second);
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
vector<vector<map<int,int>>> segtree(19);
int findsum(int l, int r, int p, int lv) {
	if (l >= r) {
		ex
	}
	if (lv == 0) {
		lol sum = 0;
		if (segtree[lv][l].find(p) != segtree[lv][l].end()) {
			sum+=segtree[lv][l][p];
		}
		return sum + findsum(l + 1, r, p, lv);
	}
	if (r - l < (1 << lv)) {
		return findsum(l, r, p, lv-4);
	}
	int ll = (l + (1 << lv) - 1) >> lv;
	int rr = r >> lv;
	if (ll >= rr) {
		return findsum(l, r, p, lv - 4);
	}
	lol sum = 0;
	if (segtree[lv][ll].find(p) != segtree[lv][ll].end()) {
		sum += segtree[lv][ll][p];
	}
	sum += findsum(l, ll<<lv, p, lv-4);
	sum += findsum((ll+1) << lv,r , p, lv);
	return sum;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	deft(lol,n) deft(lol,m) deft(lol,k)
		if (n > m) {
			n = m + 1;
	}
	if (m > n) {
		m = n + 1;
	}
	co 2*k+n+m el
		ex
}
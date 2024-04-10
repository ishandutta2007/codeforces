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
typedef pair<point, lol> poinf;
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
point sub(point x, point y) {
	return make_pair(x.first - y.first, x.second - y.second);
}
bool left(point x, point y) {
	return (x.second* y.first)- (x.first * y.second) > 0;
}
bool left(poinf x, poinf y) {
	return left(x.first, y.first);
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
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	defn
		vector<int> ansi;
	vector<poinf> alli;
	poinf best;
	into(best.first.first) into(best.first.second)
	best.second = 1;
	forn(i, n) {
		poinf cur;
		into(cur.first.first) into(cur.first.second)
			cur.second = i+1;
		if (cur.first < best.first) {
			alli.push_back(best);
			best = cur;
		}
		else {
			alli.push_back(cur);
		}
	}
	ansi.push_back(best.second);
	defs(line)
	fori(i, n - 2) {
		poinf nbest=alli[0];
		vector<poinf> nalli;
		if (line[i] == 'R') {
			forn(j, n - 1 - i) {
				poinf cur = alli[j];
				if (left(sub(cur.first,best.first), sub(nbest.first, best.first))) {
					nalli.push_back(nbest);
					nbest = cur;
				}
				else {
					nalli.push_back(cur);
				}
			}
		}else{
			forn(j, n - 1 - i) {
				poinf cur = alli[j];
				if (!left(sub(cur.first, best.first), sub(nbest.first, best.first))) {
					nalli.push_back(nbest);
					nbest = cur;
				}
				else {
					nalli.push_back(cur);
				}
			}
		}
		alli = nalli;
		best = nbest;
		ansi.push_back(best.second);
	}
	ansi.push_back(alli[0].second);
	outv(ansi,n)
	ex
}
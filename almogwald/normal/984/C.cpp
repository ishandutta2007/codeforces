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
#include <time.h>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define forb(i,a,b,c) for(int i=a;i>b;i-=c)
#define fori(i,n) forr(i,0,n,1)
#define forib(i,n) forb(i,n-1,-1,1)
#define forn(i,n) forr(i,1,n,1)
#define fornb(i,n) forb(i,n-1,0,1)
#define fort(i,m,n) forr(i,m,n,1)
#define fortb(i,m,n) forb(i,n,m,1)
#define forin(i,arr) fori(i,arr.size())
#define forinb(i,arr) forib(i,arr.size())
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
#define cas(p) co "Case #" << p+1 <<": ";
#define el << endl;
#define debug(xe,x) co xe <<": " << x el
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define out(i) co i <<' ';
#define outv(a,n) fori(iere,n){out(a[iere])} co "" el;
#define maxi 1000000013
#define mod %1000000009;
#define char1 '_'
#define char2 'a'
typedef vector<int> veci;
typedef long long lol;
#define lmaxi (lol)maxi * maxi
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<int, int> point;
typedef pair<point, point> poin;
typedef pair<vector<string>, int> postring;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
bool funccomp(point i, point j) {
	return (i.second < j.second) || (i.second == j.second && (i.first > j.first));
}
int main() {
	ios::sync_with_stdio(false);
	defn
	fori(i, n) {
		deft(lol,a) deft(lol, b) deft(lol, c)
		if (a == 0) {
			co "Finite" el
			con
		}
		lol gr = gcd(a, b);
		b /= gr;
		lol div = 2;
		while (div != 1) {
			div = gcd(b, c);
			b /= div;
			c= div;
		}
		if (b == 1) {
			co "Finite" el
		}
		else {
			co "Infinite" el
		}
	}
	ex
}
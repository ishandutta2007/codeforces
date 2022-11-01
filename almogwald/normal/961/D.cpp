#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define fori(i,n) forr(i,0,n,1)
#define forn(i,n) forr(i,1,n,1)
#define fort(i,m,n) forr(i,m,n,1)
#define forin(i,arr) fori(i,arr.size())
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
#define end cout el
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define out(i) co i <<' ';
#define outv(a,n) fori(iere,n){out(a[iere])} co "" el;
#define maxi 1000000013
#define mod %1000000007;
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, lol> point;
typedef pair<int, long long> poin;
lol gcd(lol a, lol b) { 
	if (b==0) {
		return a;
	}
	return gcd(b, a%b);
}
bool equals(point a, point b) {
	return a.first == b.first&&a.second == b.second;
}
bool online(point a, point b, point c) {
	return ((b.first - a.first)*(c.second - b.second)) == ((b.second - a.second)*(c.first - b.first));
}
point newpoint() {
	deft(lol, a) deft(lol, b)
	return make_pair(a, b);
}
int main() {
	ios::sync_with_stdio(false);
	defn
	int i = 1;
	point a= newpoint(),b,c,d,e;
	bool s = true,ab_cd = true, ac_bd = true,ad_bc = true;
	vector<point>v(n);
	v[0] = a;
	bool ab = false, ac = false, bc = false;
	while (i < n) {
		b = newpoint();
		v[i] = b;
		i++;
		if (!equals(a, b)) {
			br
		}
	}
	if (i == n) {
		co "YES" el
		ex
	}
	while (i < n) {
		c = newpoint();
		v[i] = c;
		i++;
		if (equals(a, c)) {
			con
		}
		if (equals(b, c)) {
			con
		}
		if (online(a,b, c)) {
			ab = true;
			con
		}
		br
	}
	if (i == n) {
		co "YES" el
		ex
	}
	while (i < n) {
		d = newpoint();
		v[i] = d;
		i++;
		if (equals(a, d)) {
			con
		}
		if (equals(b, d)) {
			con
		}
		if (equals(c, d)) {
			con
		}
		if (online(a, b, d)) {
			ab = true;
			con
		}
		if (online(a, c, d)) {
			ac = true;
			con
		}
		if (online(b, c, d)) {
			bc = true;
			con
		}
		s = false;
		br
	}
	if (ab && ac && bc) {
		co "NO" el
		ex
	}
	if (s) {
		co "YES" el
		ex
	}
	while (i < n) {
		e = newpoint();
		v[i] = e;
		i++;
	}
	fori(j, n) {
		e = v[j];
		if (!online(a, b, e) && !online(c, d, e)) {
			ab_cd = false;
		}
		if (!online(a, c, e) && !online(b, d, e)) {
			ac_bd = false;
		}
		if (!online(a, d, e) && !online(b, c, e)) {
			ad_bc = false;
		}
	}
	if (ab_cd || ac_bd || ad_bc) {
		co "YES" el
	}
	else {
		co "NO" el
	}
	
	ex
}
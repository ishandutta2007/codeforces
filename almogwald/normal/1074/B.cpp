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
#define maxi 1000000013
#define mod %998244353;
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
#define _230 1073741824
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<int, int> point;
typedef pair<point, int> poin;
#define poi(x,y) make_pair(x,y)
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
lol triangle(int x) {
	return (((lol)(x+2))*(x + 1)*(x + 3))/6;
}
int main() {
	ios::sync_with_stdio(false);
	def(t)
	fori(p, t) {
		defn
		vector<veci> cons(n+1);
		fori(i, n - 1) {
			defa defb
			cons[a].push_back(b);
			cons[b].push_back(a);
		}
		veci color(n+1);
		queue<point> q;
		def(k1)
		fori(i, k1) {
			defa
			q.push(poi(a, a));
		}
		def(k2)
			veci t2;
		fori(i, k2) {
			defa
			t2.push_back(a);
		}
		wne(q) {
			int me = q.front().first;
			int c = q.front().second;
			q.pop();
			if (color[me] != 0) {
				con
			}
			color[me] = c;
			forin(i, cons[me]) {
				q.push(poi(cons[me][i], c));
			}
		}
		co "B " << t2[0] el
			def(a1);
		co "A " << color[a1] el
		def(a2)
		auto it = find(all(t2), a2);
		if (it != t2.end()) {
			co "C " << color[a1] el
		}
		else {
			co "C " << -1 el
		}
	}
	ex
}
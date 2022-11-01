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
#define cas(p) co "Case #" << p+1 <<": ";
#define el << endl;
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
#define wne(a) while(!a.empty())
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, int> point;
typedef pair<point, point> poin;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
bool operator < (point i, point j) {
	return i.first<j.first || (i.first == j.first && i.second<j.second);
}
bool operator == (point i, point j) {
	return (i.first == j.first && i.second == j.second);
}
bool operator < (poin ii, poin jj) {
	point i = ii.first;
	point j = jj.first;
	point ie = ii.second;
	point je = jj.second;
	return i < j || (i == j && ie < je);
}
int main() {
	ios::sync_with_stdio(false);
	defn defk def(l);
	int m = n*k;
	veci h(m);
	fori(i, m) {
		into(h[i]);
	}
	sort(h.begin(), h.end());
	if (h[n - 1]-h[0]>l) {
		co 0 el
		ex
	}
	int end = m;
	fori(i, m) {
		if (h[i] - h[0]>l) {
			end = i;
			br
		}
	}
	int bonous = 0,down=n;
	lol sum = 0;
	fori(i, end) {
		if (end - i == down) {
			sum += h[i];
			down--;
			con
		}
		if (bonous == 0) {
			sum += h[i];
			down--;
			bonous += k - 1;
			con
		}
		bonous--;
	}
	co sum el
	ex
}
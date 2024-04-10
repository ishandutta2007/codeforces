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
typedef pair<int, int> point;
typedef pair<point, int> poin;
#define poi(x,y) make_pair(x,y)
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
lol triangle(lol x) {
	return (((lol)(x + 1))*(x)) / 2;
}

point add(point x, point y) {
	return make_pair(x.first + y.first, x.second + y.second);
}
bool check(veci a, int sum) {
	if (a.empty()) {
		return sum % 360 == 0;
	}
	int me = a.back();
	a.pop_back();
	return check(a, sum + me) || check(a, sum - me);
}
int upbond = 510000;
lol opl(int x) {
	vecl r;
	vecl s = { 0,1 };
	r.push_back(maxi);
	r.push_back(x);
	while (r.back() != 1) {
		int k = r.size() - 1;
		lol q = r[k - 1] / r[k];
		r.push_back(r[k - 1] - q* r[k]);
		s.push_back((s[k - 1] - q* s[k] + maxi) % maxi);
	}
	return s.back();
}
int main() {
	ios::sync_with_stdio(false);
	deft(lol, n) defk
		if (k == 0) {
			co n%maxi el
				ex
		}
	lol ans = 1;
	vecl op(71);
	fort(i, 2, 70) {
		op[i] = opl(i);
	}
	fort(i, 2, 40000000) {
		int p = 0;
		while (n%i == 0) {
			p++;
			n /= i;
		}
		if (p == 0) {
			con
		}
		vecl a(p + 1);
		a[p] = 1;
		fori(t, k) {
			fori(j, p) {
				lol cur = (a[j + 1] * op[j + 2] + maxi) mod
					a[j + 1] = cur;
				fori(q, j + 1) {
					a[q] = (a[q] + cur + maxi) mod
				}
			}
		}
		lol ansi = 0;
		lol curi = 1;
		fori(j, p + 1) {
			ansi = (ansi + curi*a[j] + maxi)mod
				curi = (curi * i + maxi)mod
		}
		ans = (ans * ansi + maxi*(lol)10000000)mod
	}
	if (n != 1) {
		lol i = n;
		int p = 1;
		vecl a(p + 1);
		a[p] = 1;
		fori(t, k) {
			fori(j, p) {
				lol cur = (a[j + 1] * op[j + 2] + maxi) mod
					a[j + 1] = cur;
				fori(q, j + 1) {
					a[q] = (a[q] + cur + maxi) mod
				}
			}
		}
		lol ansi = 0;
		lol curi = 1;
		fori(j, p + 1) {
			ansi = (ansi + curi*a[j] + maxi)mod
				curi = (curi * i + maxi)mod
		}
		ans = (ans * ansi+ maxi*(lol)10000000)mod
	}
	co ans el
	ex
}
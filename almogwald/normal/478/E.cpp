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
bool isweavy2(lol n) {
	lol lastdig = n % 10;
	n /= 10;
	lol curdig = n % 10;
	n /= 10;
	if (curdig == lastdig) {
		return false;
	}
	while (n > 1) {
		lol newdig = n % 10;
		n /= 10;
		if (curdig >= lastdig && curdig <= newdig) {
			return false;
		}
		if (curdig <= lastdig && curdig >= newdig) {
			return false;
		}
		lastdig = curdig;
		curdig = newdig;
	}
	return true;
}
bool isweavy(lol n) {
	lol lastdig = n % 10;
	n /= 10;
	lol curdig = n % 10;
	n /= 10;
	if (curdig == lastdig) {
		return false;
	}
	while (n > 0) {
		lol newdig = n % 10;
		n /= 10;
		if (curdig >= lastdig && curdig <= newdig) {
			return false;
		}
		if (curdig <= lastdig && curdig >= newdig) {
			return false;
		}
		lastdig = curdig;
		curdig = newdig;
	}
	return true;
}
lol nextwavey(lol i) {
	veci a;
	while (i > 0) {
		a.push_back(i % 10);
		i /= 10;
	}
	bool s = false;
	int n = a.size();
	if (a[n - 1] == a[n - 2]) {
		a[n - 2]++;
		if (a[n - 2] == 10) {
			a[n - 2] = 0;
			a[n - 1]++;
			if (a[n - 1] == 10) {
				a[n - 2] = 1;
				a[n - 1] = 0;
				a.push_back(1);
			}
		}
		s = true;
	}
	fornb(i, n - 1) {
		if (s) {
			if (a[i] <= a[i + 1]) {
				a[i - 1] = a[i] + 1;
			}
			else {
				a[i - 1] = 0;
			}
		}
		else {
			if (a[i] <= a[i + 1] && a[i - 1] <= a[i]) {
				a[i - 1] = a[i] + 1;
				s = true;
			}
			if (a[i] >= a[i + 1] && a[i - 1] >= a[i]) {
				a[i]++;
				a[i - 1] = 0;
				s = true;
			}
		}
	}
	while (!a.empty()) {
		i *= 10;
		i += a.back();
		a.pop_back();
	}
	return i;
}
int main() {
	ios::sync_with_stdio(false);
	deft(lol, n)
		deft(lol, k)
		lol dif = 10000000;
	if (n > dif / 5) {
		lol j = 1;
		while (j*n < dif*dif) {
			if (isweavy(j*n)) {
				k--;
				if (k == 0) {
					co(j)*n el
						ex
				}
			}
			j++;
		}
		co - 1 el
			ex
	}
	lol j = 1;
	while (j*n < dif) {
		if (isweavy(j*n)) {
			k--;
			if (k == 0) {
				co(j)*n el
					ex
			}
			j++;
		}
		else {
			lol newj = (nextwavey(j*n) + n - 1) / n;
			j = max(newj, j + 1);
		}

	}
	tablel(name, n, 20)
		fort(i, dif / 100, dif) {
		if (isweavy2(i + dif)) {
			lol sec = i / (dif / 10);
			if (sec < (i / (dif / 100)) % 10) {
				sec += 10;
			}
			name[i%n][sec]++;
		}
		else {
			int newi = nextwavey(i);
			if (i < newi) {
				i = newi - 1;
			}
		}
	}
	forn(i, dif) {
		if (!isweavy(i)) {
			int newi = nextwavey(i);
			if (i < newi) {
				i = newi - 1;
			}
			con
		}
		lol intrested = (n - (i*dif) % n) % n;
		lol lastk = k;
		lol a = i % 10;
		lol b = (i / 10) % 10;
		if (i<10 || b>a) {
			forn(j, 10) {
				if (a < j) {
					k -= name[intrested][j];
				}
			}
		}
		if (i < 10 || b < a) {
			fori(j, 9) {
				if (a > j) {
					k -= name[intrested][10 + j];
				}
			}
		}
		if (k <= 0) {
			k = lastk;
			lol j = (i*dif + n - 1) / n;
			while (j*n < dif*dif) {
				if (isweavy(j*n)) {
					k--;
					if (k == 0) {
						co(j)*n el
							ex
					}
					j++;
				}
				else {
					lol newj = (nextwavey(j*n)+n-1)/n;
					j = max(newj, j + 1);
				}
				
			}
		}
	}
	co - 1 el
		ex
}
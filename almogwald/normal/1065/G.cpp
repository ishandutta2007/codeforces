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
#define forinb(i,m,n) forib(i,arr.size())
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
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<int, int> point;
typedef pair<point, int> poin;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
bool myfunc(poin ii, poin jj) {
	point i = ii.first;
	point j = jj.first;
	return i.first<j.first || (i.first == j.first && i.second<j.second);
}
lol modinverse(lol x, lol xa, lol m, lol ma) {
	if (x == 1) {
		return xa;
	}
	lol b = m / x;
	return modinverse(m - x * b,ma - xa * b, x, xa);
}
lol modinverse(lol x, lol m) {
	lol ans = modinverse(x, 1, m, 0);
	ans = (ans + 10 * m) % m;
	return ans;
}
bool issuffix(string big, string smol) {
	int i = smol.size() - 1;
	int j = big.size() - 1;
	while (i >= 0) {
		if (big[j--] != smol[i--]) {
			return false;
		}
	}
	return true;
}
int count(string big, string smol) {
	int ans = 0;
	if (big.size() < smol.size()) {
		return ans;
	}
	fori(i, big.size() - smol.size() + 1) {
		if (big.substr(i, smol.size()) == smol) {
			ans++;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	defn deft(lol, k) defm
		//k++;
	string line = "";
	vector<string> fib;
	fib.push_back("0");
	fib.push_back("1");
	while (fib.back().size() < 4 * m || fib.size()<4) {
		fib.push_back(fib[fib.size()-2] + fib.back());
	}
	int len = fib.size();
	fori(i, m) {
		if (issuffix(fib.back(), line)) {
			if (k == 0) {
				co line el
					ex
			}
			k--;
		}
		line = line + "0";
		lol num = 0;
		if (n < fib.size()) {
			num = count(fib[n], line);
		}
		else {
			lol d= count(fib[len-4], line);
			lol c = count(fib[len - 3], line);
			lol b = count(fib[len - 2], line);
			lol a = count(fib[len - 1], line);
			lol mod1 = 0;
			lol mod2 = 0;
			if (len % 2 == 0) {
				mod2 = b - c - d;
				mod1 = a - c - b;
			}
			else {
				mod1 = b - c - d;
				mod2 = a - c - b;
			}
			int p = len;
			while (p <= n && a<=k) {
				lol cur = a + b;
				if (p % 2 == 0) {
					cur += mod2;
				}
				else {
					cur += mod1;
				}
				b = a;
				a = cur;
				p++;
			}
			num = a;
		}
		if (num <= k) {
			k -= num;
			line[i] = '1';
		}
	}
	co line el
	ex
}
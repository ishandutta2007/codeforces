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
int m;
lol ans(veci arr) {
	int n = arr.size();
	fori(i, n - 1) {
		if (arr[i] != -1 && arr[i] == arr[i + 1]) {
			return 0;
		}
	}
	lol curans=1;
	int last = 0;
	bool in = false;
	lol diffthenlast = 0;
	lol eqlast = 0;
	fori(i, n) {
		if (arr[i] == -1) {
			if (last == 0) {
				if (in) {
					diffthenlast = ((m - 1)*diffthenlast) % 998244353;
				}
				else {
					in = true;
					diffthenlast = m;
				}
			}
			else {
				if (in) {
					lol leqlast = eqlast;
					eqlast = diffthenlast;
					diffthenlast = (leqlast*(m-1) +((m - 2)*diffthenlast)) % 998244353;
				}
				else {
					in = true;
					diffthenlast = m - 1;
				}
			}
		}
		else {
			if (in) {
				in = false;
				lol cans=1;
				if (last == 0) {
					cans = (((diffthenlast*modInverse(m)) % 998244353)*(m-1)) % 998244353;
				}
				else if(last== arr[i]){
					cans = diffthenlast;
				}
				else {
					cans = (eqlast + (((diffthenlast*modInverse(m-1)) % 998244353)*(m - 2))) % 998244353;
				}
				eqlast = 0;
				diffthenlast = 0;
				curans = (cans*curans) % 998244353;
			}
			last = arr[i];
		}
	}
	if (in) {
		curans = ((eqlast + diffthenlast)*curans) % 998244353;
	}
	return curans;
}
int main() {
	ios::sync_with_stdio(false);
	defn into(m)
		veci odd, even;
	fori(i, n) {
		defa
		if (i % 2 == 0) {
			even.push_back(a);
		}
		else {
			odd.push_back(a);
		}
	}
	co (ans(even)*ans(odd))% 998244353 el
	ex
}
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
#define mod %998244353;
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
#define _230 1073741824
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
	return gcd(b, a%b);
}
lol triangle(lol x) {
	return (((lol)(x + 1))*(x)) / 2;
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
int serch(vecp &x, int num) {
	int l = 0, h = x.size()-1;
	while (l < h) {
		int m = (l + h+1) / 2;
		if (x[m].first < num) {
			h = m-1;
		}
		else {
			l = m;
		}
	}
	return l;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	def(t)
	fori(k, t) {
		defn
		if(n==1){
			out('A') out(1) out(0) co 0 el
			co 1 el
			co "" el
			co "" el
				con
		}
			out('Q')
			out(n/2)
		fort(i, 1, (n-(n%2))+1) {
			out(i)
		}
		co "" el
			deft(string, line)
			if (n == 2 && line[0]=='1') {
				out('A') out(2) out(0) co 0 el
					co "1 2" el
					co "" el
					co "" el
					con
			}
		if (n == 2 && line[0] == '0') {
			out('A') out(1) out(1) co 0 el
				co "1" el
				co "2" el
				co "" el
				con
		}
			veci a;
		a.push_back(n);
		forin(i, line) {
			if (line[i] == '0') {
				a.push_back(2 * i + 1);
			}
		}
		out('Q')
		out((n-1) / 2)
		fort(i, 2, n + (n % 2)) {
			out(i)
		}
		co "" el
		into(line)
		forin(i, line) {
			if (line[i] == '0') {
				a.push_back(2 * i + 2);
			}
		}
		sort(all(a));
		veci color(a.size() + 2);
		color[0] = 1;
		color[1] = 2;
		if (a.size() > 1) {
			veci quest;
			fori(i, a.size() - 2) {
				if (i % 4 >= 2) {
					con
				}
				quest.push_back(a[i]);
				quest.push_back(a[i + 2]);
			}
			if (quest.size() > 0) {
				out('Q')
					out(quest.size() / 2)
					forin(i, quest) {
					out(quest[i])
				}
				co "" el
					into(line)
			}
			veci lock(a.size() - 2);
			int j = 0;
			fori(i, a.size() - 2) {
				if (i % 4 >= 2) {
					con
				}
				lock[i] = line[j++] - '0';
			}
			quest.resize(0);
			fori(i, a.size() - 2) {
				if (i % 4 <= 1) {
					con
				}
				quest.push_back(a[i]);
				quest.push_back(a[i + 2]);
			}
			if (quest.size() > 0) {
				out('Q')
					out(quest.size() / 2)
					forin(i, quest) {
					out(quest[i])
				}
				co "" el
					into(line)
			}
			j = 0;
			fori(i, a.size() - 2) {
				if (i % 4 <= 1) {
					con
				}
				lock[i] = line[j++] - '0';
			}

			fori(i, a.size() - 2) {
				if (lock[i] == 1) {
					color[i + 2] = color[i];
				}
				else {
					color[i + 2] = 6 - color[i] - color[i + 1];
				}
			}
		}
		int j = 0;
		veci c1, c2, c3;
		forn(i, n+1) {
			if (a[j] < i) {
				j++;
			}
			if (color[j] == 1) {
				c1.push_back(i);
			}else if(color[j] == 2) {
				c2.push_back(i);
			}
			else {
				c3.push_back(i);
			}
		}
		out('A') out(c1.size()) out(c2.size()) co c3.size() el
			forin(i, c1) {
			out(c1[i])
		}
		co "" el
			forin(i, c2) {
			out(c2[i])
		}
		co "" el
			forin(i, c3) {
			out(c3[i])
		}
		co "" el
	}
	ex
}
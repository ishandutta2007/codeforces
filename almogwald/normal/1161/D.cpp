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
#define el << "\n";
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

	deft(string, line)
	int n = line.size();
	lol sum = 0;
	int midn = ((n + 1) / 2);
	forn(i, n) {
		bool work = false;
		int midi = ((i + 1) / 2);
		veci color(midn + midi);
		int s = color.size();
		forin(i, color) {
			color[i] = -1;
		}
		color[0] = 1;
		color[midn] = 1;
		vector<veci> cons(s);
		vector<veci> opcons(s);
		fori(j, n - i) {
			if (line[j] == '1') {
				int a = j;
				if (a >= n / 2) {
					a = n - 1 - a;
				}
				if (color[a] == 0) {
					work = true;
				}
				color[a] = 1;
			}
			if (line[j] == '0') {
				int a = j;
				if (a >= n / 2) {
					a = n - 1 - a;
				}
				if (color[a] == 1) {
					work = true;
				}
				color[a] = 0;
			}
		}
		if (work) {
			con
		}
		fort(j, n - i, n) {
			if (line[j] == '0') {
				int a = j;
				int b = j+i-n;
				if (a >= n / 2) {
					a = n-1 - a;
				}
				if (b >= i / 2) {
					b = i-1-b;
				}
				b += midn;
				cons[a].push_back(b);
				cons[b].push_back(a);
			}
			if (line[j] == '1') {
				int a = j;
				int b = j + i - n;
				if (a >= n / 2) {
					a = n - 1 - a;
				}
				if (b >= i / 2) {
					b = i - 1 - b;
				}
				b += midn;
				opcons[a].push_back(b);
				opcons[b].push_back(a);
			}
		}
		queue<point> bfs;
		fori(i, s) {
			if (work) {
				br
			}
			if (color[i] == -1) {
				con
			}
			bfs.push({ i,color[i] });
			color[i] = -1;
			wne(bfs) {
				int c = bfs.front().second;
				int p= bfs.front().first;
				bfs.pop();
				if (color[p] == 1 - c) {
					work = true;
					br
				}
				if (color[p] == c) {
					con
				}
				color[p] = c;
				forin(j, cons[p]) {
					bfs.push({ cons[p][j],c });
				}
				forin(j, opcons[p]) {
					bfs.push({ opcons[p][j],1-c });
				}
			}
		}
		if (work) {
			con
		}
		lol cur = 1;
		work = false;
		fori(i, s) {
			if (work) {
				br
			}
			if (color[i] != -1) {
				con
			}
			cur= (cur*2)mod
			bfs.push({ i,0 });
			wne(bfs) {
				int c = bfs.front().second;
				int p = bfs.front().first;
				bfs.pop();
				if (color[p] == 1 - c) {
					work = true;
					br
				}
				if (color[p] == c) {
					con
				}
				color[p] = c;
				forin(j, cons[p]) {
					bfs.push({ cons[p][j],c });
				}
				forin(j, opcons[p]) {
					bfs.push({ opcons[p][j],1 - c });
				}
			}
		}
		if (work) {
			con
		}
		sum = (sum+cur)mod
	}
	co sum el
	ex
}
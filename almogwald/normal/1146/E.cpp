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
int serch(vecp &x,int num) {
	int l = 0, h = x.size();
	while (l < h) {
		int m = (l + h) / 2;
		if (x[m].first < num) {
			l = m + 1;
		}
		else {
			h = m;
		}
	}
	return l;
}
vector<veci> segtre(20);
void putone(int d, int p, int num) {
	if (num == 3) {
		segtre[d][p] = 3 - segtre[d][p];
	}
	else if(num!=0){
		segtre[d][p] = num;
	}
}
void fix(int x, int y, int num ,int depth) {
	if (x > y) {
		return;
	}
	if (depth == 0) {
		if (x<y) {
			fort(i, x, y + 1) {
				fix(i, i, num, 0);
			}
			return;
		}
		putone(0, x, num);
		return;
	}
	int cur = 1 << depth;
	int x1 = x / cur;
	int x2 = (x+cur-1) / cur;
	int y1 = (y - cur - 1) / cur;
	if ((y - cur - 1) < 0) {
		y1 = -1;
	}
	int y2 = (y) / cur;
	if (x2 <= y1) {
		putone(depth, x2, num);
		fix(x, x2*cur-1, num, depth);
		fix((x2 + 1)*cur, y, num, depth);
		return;
	}
	putone(depth - 1, x1 * 2, segtre[depth][x1]);
	putone(depth - 1, x1 * 2 + 1, segtre[depth][x1]);
	segtre[depth][x1] = 0;
	putone(depth - 1, y2 * 2, segtre[depth][y2]);
	putone(depth - 1, y2 * 2 + 1, segtre[depth][y2]);
	segtre[depth][y2] = 0;
	fix(x, y, num, depth - 1);
}
void fix(int x, int y, int num) {
	fix(x, y, num, 19);
}
int main() {
	ios::sync_with_stdio(0);
	defn defm
	vecp plus;
	vecp minus;
	fori(i, n) {
		defa
			if (a > 0) {
				plus.push_back({ a,i });
			}
			else if(a<0) {
				minus.push_back({ -a,i });
			}
	}
	
	sort(all(plus));
	sort(all(minus));
	int nn = plus.size() + minus.size();
	vecp add(nn);
	fori(i, 20) {
		segtre[i].resize(n);
	}
	int x = 0, y = 0;
	int k = 0;
	while (x < plus.size() && y < minus.size()) {
		if (plus[x] < minus[y]) {
			add[k] = (plus[x++]);
			segtre[0][k] = 1;
		}
		else {
			add[k] = (minus[y++]);
			segtre[0][k] = 2;
		}
		k++;
	}
	while (x < plus.size()) {
		add[k] = (plus[x++]);
		segtre[0][k] = 1;
		k++;
	}
	while (y < minus.size()) {
		add[k] = (minus[y++]);
		segtre[0][k] = 2;
		k++;
	}
	fori(i, m) {
		deft(char, c)
			defa
			if (c == '<') {
				if (a <= 0) {
					int x = serch(add, -a + 1);
					fix(x, nn - 1, 1);
				}
				else {
					int x = serch(add, a);
					fix(x, nn - 1, 1);
					fix(0, x - 1, 3);
				}
			}
			else {
				if (a >= 0) {
					int x = serch(add, a + 1);
					fix(x, nn - 1, 2);
				}
				else {
					int x = serch(add, -a);
					fix(x, nn - 1, 2);
					fix(0, x - 1, 3);
				}
			}
		}//
		veci ans(n);
		fori(i, nn) {
			int numc = 0;
			forib(j, 20) {
				if (segtre[j][i >> j] == 3) {
					numc = 3 - numc;
				}
				else
					if (segtre[j][i >> j] != 0) {
						numc = numc ^ segtre[j][i >> j];
						br
					}
			}
			ans[add[i].second] = -add[i].first * (2 * numc - 3);
		}
		fori(i, n) {
			out(ans[i])
		}
		co "" el
	//}
	
		ex
}
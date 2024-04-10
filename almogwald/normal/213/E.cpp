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
int n, m;
vector<veci> sorterarr(20);
vector<veci> sorterarrsum(20);
void construt(veci a, int lv, int l, int r, int low, int high) {
	if (r <= l || low == high) {
		return;
	}
	veci b, c;
	int mid = (low + high) / 2;
	int sum = 0;
	forin(i, a) {
		if (a[i] <= mid) {
			sum++;
			b.push_back(a[i]);
		}
		else {
			sorterarr[lv][l + i] = 1;
			c.push_back(a[i]);
		}
	}
	construt(b, lv + 1, l, l + sum, low, mid);
	construt(c, lv + 1, l + sum , r , mid+1, high);
}
int place(int lv, int arrl, int l, int r, int arrr, int x, int low, int high) {
	l += arrl;
	r += l;
	arrr += r;
	if (x <= low || r < l) {
		ex
	}
	if (x > high) {
		return r - l + 1;
	}
	int mid = (low + high) / 2;
	int onesarrltol = (sorterarrsum[lv][l] - sorterarrsum[lv][arrl]);
	int zerosarrltol = l - arrl - onesarrltol;
	int onesltor = (sorterarrsum[lv][r + 1] - sorterarrsum[lv][l]);
	int zerosltor = r + 1 - l - onesltor;
	int onesrtoarrr = (sorterarrsum[lv][arrr + 1] - sorterarrsum[lv][r+ 1]);
	int zerosrtoarrr = arrr - r - onesrtoarrr;
	int sumzero = zerosrtoarrr + zerosltor + zerosarrltol;
	return place(lv + 1, arrl, zerosarrltol, zerosltor - 1, zerosrtoarrr, x, low, mid) +
		place(lv + 1, arrl + sumzero, onesarrltol, onesltor - 1, onesrtoarrr, x, mid + 1, high);
}
int place(int l, int r, int x) {
	return place(0, 0, l, r-l, n + m - 1 -r, x, 0, m - 1);
}
int main() {
	ios::sync_with_stdio(0);
	into(n) into(m)
		if (n == 1) {
			co m el
				ex
		}
		veci a(n);
	veci b(m);
	for (int i = 0, x; i < n; i++)
		cin >> x, a[x - 1] = i;
	for (int i = 0, x; i < m; i++)
		cin >> x, b[x - 1] = i;
	veci c;
	c.reserve(n + m);
	for (auto &i : a) c.push_back(i);
	for (auto &i : b) c.push_back(i);
	fori(i, 20) {
		sorterarr[i].resize(n + m);
		
	}
	construt(c,0,0,n+m-1,0,m-1);
	fori(i, 20) {
		sorterarrsum[i].resize(n + m+1);
		fori(j, n + m) {
			sorterarrsum[i][j+1] = sorterarrsum[i][j] + sorterarr[i][j];
		}
	}
	veci places(n);
	forn(i, n) {
		places[i] = place(0, i - 1, a[i]);
	}
	veci returni(n);
	forn(i, n) {
		int cur = returni[i - 1];
		while (cur > 0 && places[cur] != place(i - cur, i - 1, a[i])) {
			cur = returni[cur - 1];
		}
		returni[i] = cur + 1;
	}
	int ans = 0;
	int cur = 1;
	forn(i,m) {
		while (cur == n || (cur > 0 && places[cur] != place(n+i - cur, n + i - 1, b[i]))) {
			cur = returni[cur - 1];
		}
		cur++;
		if (cur == n) {
			ans++;
		}
	}
	co (ans) el
	ex
}
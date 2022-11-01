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
#define maxi 1000000013
#define mod %1000000009;
#define wne(arr) while(!arr.empty())
#define _230 1073741824
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, lol> point;
typedef pair<point, point> poin;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
struct poing {
	int x;
	int y;
};
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	poing real[4];
	int minx = maxi;
	int miny = maxi;
	int maxx = -maxi;
	int maxy = -maxi;
	fori(i, 4) {
		into(real[i].x)
		minx = min(real[i].x, minx);
		maxx = max(real[i].x, maxx);
		into(real[i].y)
		miny = min(real[i].y, miny);
		maxy = max(real[i].y, maxy);
	}
	poing fake[4];
	int minsum = maxi;
	int mindif = maxi;
	int maxsum = -maxi;
	int maxdif = -maxi;
	fori(i, 4) {
		into(fake[i].x)
		into(fake[i].y)
		int sum = fake[i].x + fake[i].y;
		int dif = fake[i].x - fake[i].y;
		minsum = min(sum, minsum);
		maxsum = max(sum, maxsum);
		mindif = min(dif, mindif);
		maxdif = max(dif, maxdif);
	}
	forr(i, -101, 101, 1) {
		forr(j, -101, 101, 1) {
			int sum = i + j;
			int dif = i - j;
			if (sum <= maxsum && sum >= minsum && dif <= maxdif && dif >= mindif&&i <= maxx && i >= minx && j <= maxy && j >= miny) {
				co "YES" el
				ex
			}
		}
	}
	co "NO" el
	ex
}
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
	int comp(poing a) {
		if (x == a.x) {
			if (y == a.y) {
				return -1;
			}
			return x;
		}
		if (x == a.y) {
			if (y == a.x) {
				return -1;
			}
			return x;
		}
		if (y == a.x || y == a.y) {
			return y;
		}
		return -1;
	}
};
int main() {
	ios::sync_with_stdio(false);
	defn defk
	deft(string, line)
	veci ch(26);
	veci del(26);
	fori(i, n) {
		ch[line[i] - 'a']++;
	}
	fori(i, 26) {
		del[i] = min(k, ch[i]);
		k-= min(k, ch[i]);
	}
	string out;
	fori(i, n) {
		if (del[line[i] - 'a'] == 0) {
			out.push_back(line[i]);
		}
		else {
			del[line[i] - 'a']--;
		}
	}
	co out el
	ex
}
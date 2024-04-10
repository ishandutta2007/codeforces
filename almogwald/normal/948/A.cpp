#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define fori(i,n) forr(i,0,n,1)
#define forn(i,n) forr(i,1,n,1)
#define forin(i,arr) fori(i,arr.size())
#define into(i) cin >> i;
#define def(i) int i; into(i)
#define defn def(n)
#define defm def(m)
#define defk def(k)
#define defa def(a)
#define defb def(b)
#define defc def(c)
#define vec(a) vector<a>
#define co cout <<
#define cas(p) co "Case #" << p+1 <<": ";
#define el << endl;
#define end cout el
#define ex return 0; 
#define out(i) co i <<' ';
#define maxi 1000000013
typedef vector<int> veci;
typedef pair<int, int> point;
typedef pair<veci, int> vecip;
//typedef pair<point, point> testcase;
/*struct classcomp {
bool operator() (const vecip & i, const vecip & j) {
const veci & a = i.first;
const veci & b = j.first;
fori(i, min(a.size(), b.size())) {
int c = a[a.size() - 1 - i];
int d = b[b.size() - 1 - i];
if (c < d) {
return true;
}
if (c > d) {
return false;
}
}
if (a.size() > b.size()) {
return true;
}
if (a.size() < b.size()) {
return false;
}
return i.second < j.second;
}
};*/
int main() {
	defn defm
		vector<string> lines(n);
	fori(i, n) {
		into(lines[i]);
	}
	bool ok = false;
	forn(i, n) {
		fori(j, m) {
			if (lines[i][j] == 'S'&&lines[i - 1][j] == 'W') {
				ok = true;
			}
			if (lines[i][j] == 'W'&&lines[i - 1][j] == 'S') {
				ok = true;
			}
		}
	}
	fori(i, n) {
		forn(j, m) {
			if (lines[i][j - 1] == 'S'&&lines[i][j] == 'W') {
				ok = true;
			}
			if (lines[i][j - 1] == 'W'&&lines[i][j] == 'S') {
				ok = true;
			}
		}
	}
	if (ok) {
		co "No" el
		ex
	}
	co "Yes" el
	fori(i, n) {
		fori(j, m) {
			if (lines[i][j] == '.') {
				lines[i][j] = 'D';
			}
		}
	}
	fori(i, n) {
		co lines[i] el
	}
	ex
}
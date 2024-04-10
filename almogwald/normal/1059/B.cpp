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
#define maxi 1000000013
#define mod %998244353;
#define wne(arr) while(!arr.empty())
#define all(arr) arr.begin(),arr.end()
#define _230 1073741824
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
vector<veci> t;
int n, m;
bool check(int x, int y) {
	if (x <= 0 || x >= n - 1 || y <= 0 || y >= m - 1) {
		return true;
	}
	if (t[x - 1][y + 1] + t[x - 1][y] + t[x - 1][y - 1] + t[x + 1][y + 1] + t[x + 1][y] + t[x + 1][y-1]+ t[x][y + 1] + t[x][y - 1]==8) {
		return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	into(n) into(m)
	fori(i, n) {
		veci dummy;
		t.push_back(dummy);
		deft(string,a);
		fori(j, m) {
			if (a[j] == '.') {
				t.back().push_back(0);
			}
			else {
				t.back().push_back(1);
			}
		}
	}
	fori(i, n) {
		fori(j, m) {
			if (t[i][j] == 1 && check(i+1,j) && check(i + 1, j + 1) && check(i + 1, j - 1) && check(i - 1, j) && check(i - 1, j + 1) && check(i - 1, j - 1) && check(i, j + 1) && check(i, j - 1)) {
				co "NO" el
				ex
			}
		}
	}
	co "YES" el
	ex
}
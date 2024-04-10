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
typedef pair<point, lol> poin;
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
bool sortenve(poin a, poin b) {
	return a.first.first > b.first.first || (a.first.first == b.first.first && a.first.second > b.first.second) ;
}
bool palindrom(string a) {
	forin(i, a) {
		if (a[i] != a[a.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
int anser(string line,int d) {
	if (!palindrom(line)) {
		return 1;
	}
	int n = line.size();
	lol sum = 0;
	fori(i, n-1) {
		if (line[i] - line[i + 1] != 0) {
			sum++;
		}
	}
	if (sum == 0) {
			return -2;
	}
	if (n%2==1) {
		if (d==0&&anser(line.substr(0, n / 2),1) == -2) {
			return -2;
		}
		return 2;
	}
	return (anser(line.substr(0, n / 2),1));
}
int main() {
	ios::sync_with_stdio(false);
	deft(string, line)
		int ans = anser(line,0);
	if (ans == -2) {
		co "Impossible" el
	}
	else {
		co ans el
	}
	
	ex
}
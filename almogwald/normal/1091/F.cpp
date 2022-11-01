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
int main() {
	ios::sync_with_stdio(false);
	defn
	vecl a(n);
	
	fori(i, n) {
		into(a[i])
		
	}
	deft(string, line)
	lol canretrive = 0;
	lol stamina = 0;
	lol time = 0;
	bool visitedwater = false;
	fori(i, n) {
		n = n+1-1;
		if (line[i] == 'W') {
			visitedwater = true;
			time += 3 * a[i];
			stamina += a[i];
		}
		else if (line[i] == 'G') {
			if (stamina >= a[i]) {
				stamina -= a[i];
				time += a[i];
				canretrive += a[i]*2;
			}
			else {
				lol left = a[i] - stamina;
				time += stamina;
				canretrive += stamina*2;
				stamina = 0;
				canretrive += left;
				time += 3 * left;
			}
		}
		else {
			if (stamina > a[i]) {
				stamina -= a[i];
				time += a[i];
			}
			else {
				lol left = a[i] - stamina;
				time += stamina;
				stamina = 0;
				if (canretrive > left) {
					canretrive -= left;
					time += 3 * left;
				}
				else {
					time += 3 * canretrive;
					left -= canretrive;
					canretrive = 0;
					if (visitedwater) {
						time += 4 * left;
					}
					else {
						time += 6 * left;
					}
				}
			}
		}
	}
	co time - stamina el
	ex
}
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
#define out(i) co i <<' ';
#define outv(a,n) fori(iere,n){out(a[iere])} co "" el;
#define maxi 1000000013
#define mod %1000000009;
#define wne(a) while(!a.empty())
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<lol, int> point;
typedef pair<point, point> poin;
lol gcd(lol a, lol b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
bool myfunc(poin ii, poin jj) {
	point i = ii.first;
	point j = jj.first;
	return i.first>j.first || (i.first == j.first && i.second<j.second);
}
bool myfunc2(point i, point j) {
	return i.first<j.first || (i.first == j.first && i.second<j.second);
}
bool touch(poin ii, poin jj) {
	lol ri = ii.first.first;
	lol rj = jj.first.first;
	lol xi = ii.second.first;
	lol xj = jj.second.first;
	lol yi = ii.second.second;
	lol yj = jj.second.second;
	return (ri + rj)*(ri + rj) >= (xi - xj)*(xi - xj) + (yi - yj)*(yi - yj);
}
map<int, int> arg;
void erase(int x) {
	arg[x]--;
	if (arg[x] == 0) {
		auto it =arg.find(x);
		arg.erase(it);
	}
}
void insert(int x) {
	if (arg.find(x) == arg.end()) {
		arg[x] = 0;
	}
	arg[x]++;
}
int one() {
	if (arg.empty()) {
		//co "?" el
		ex
	}
	auto it = arg.begin();
	it++;
	if (it == arg.end()) {
		auto it = arg.begin();
		return (*it).second;
	}
	else {
		return -1;
	}
}
int main() {
	ios::sync_with_stdio(false);
	defn
	vector<point> pos(n);
	fori(i, n) {
		defa
			pos[i] = make_pair(a, i);
	}
	sort(pos.begin(), pos.end(), myfunc2);
	multiset<int> good;
	good.insert(-1);
	good.insert(n);
	arg.insert(make_pair(n+1,1));
	int min = 0, place = pos[n - 1].first + 1;
	fornb(i, n) {
		//co i el
		int posi = pos[i-1].first+1;
		int placi = pos[i].second;
		auto it = good.insert(placi);
		auto itp = it; itp++;
		auto itm = it; itm--;
		erase(*itp - *itm);
		if (*itp - *it > 1) {
			insert(*itp - *it);
		}
		if (*it - *itm > 1) {
			insert(*it - *itm);
		}
		int me = one();
		if (me >= min) {
			min = me;
			place = posi;
		}
	}
	co place el
	ex
}
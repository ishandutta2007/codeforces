#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>
#include <deque>
#include <stack>
using namespace std;
#define forr(i,a,b,c) for(int i=a;i<b;i+=c)
#define fori(i,n) forr(i,0,n,1)
#define forn(i,n) forr(i,1,n,1)
#define fort(i,m,n) forr(i,m,n,1)
#define forin(i,arr) fori(i,arr.size())
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
#define end cout el
#define ex return 0; 
#define qii queue<int>
#define sti stack<int>
#define dei deque<int>
#define con continue;
#define br break;
#define out(i) co i <<' ';
#define outv(a,n) fori(iere,n){out(a[iere])} co "" el;
#define maxi 1000000013
#define mod %1000000007;
typedef vector<int> veci;
typedef long long lol;
typedef vector<lol> vecl;
#define table(name,n,m) vector<veci> name(n,veci (m));
#define tablel(name,n,m) vector<vecl> name(n,vecl (m));
typedef pair<int, int> point;
typedef pair<int, long long> poin;
lol gcd(lol a, lol b) { 
	if (b==0) {
		return a;
	}
	return gcd(b, a%b);
}
int main() {
	ios::sync_with_stdio(false);
	defn defk
	veci h(n);
	veci a(n);
	fori(i, n) {
		into(h[i])
	}
	fori(i, n) {
		into(a[i])
	}
	int max = 0;
	int cur = 0;
	int sum = 0;
	fori(i, n) {
		if (a[i] == 1) {
			sum += h[i];
		}
		else {
			cur+= h[i];
		}
		if (i >= k && a[i-k]==0) {
			cur -= h[i - k];
		}
		if (cur > max) {
			max = cur;
		}
	}
	co sum+max el
	ex
}
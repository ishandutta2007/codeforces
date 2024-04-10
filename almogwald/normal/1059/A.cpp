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
int pow(int a, int p) {
	int ans=1;
	fori(i, p) {
		ans *= a;
	}
	return ans;
}
int * synonym(int *a) {
	int *ans = (int *)malloc(24);
	for (int i = 0; i < 6; i++) {
		ans[i] = 0;
		fori(j, 10) {
			ans[i] += pow(j + 1, i)*a[j];
		}
		ans[i] %= 13;
		//co ans[i] el
	}
	return ans;
}
int *ansi;
int * synonym(veci &a) {
	int *ans = (int *)malloc(24);
	for (int i = 0; i < 6; i++) {
		ans[i] = 0;
		fori(j, 10) {
			ans[i] += pow(j + 1, i)*a[j];
		}
		ans[i] %= 13;
		//co ans[i] el
	}
	
	return ans;
}
int dub(veci &a,int sum, int has) {
	if (sum < 0) {
		ex
	}
	if (has==10) {
		int *newansi = synonym(a);
		bool me = true;
		fori(i, 6) {
			if (newansi[i] != ansi[i]) {
				me = false;
			}
		}
		if (me) {
			outv(a, 10);
		}
		ex
	}
	a.push_back(0);
	has++;
	dub(a, sum, has);
	a.pop_back();
	sum--;
	forn(i, 13) {
		a.push_back(i);
		dub(a, sum, has);
		a.pop_back();
	}
	ex
}
int main() {
	ios::sync_with_stdio(false);
	defn defa defb
	int last = 0,sum=0;
	fori(i, n) {
		defc defd
			sum += (c - last)/b;
		last = c + d;
	}
	sum += (a - last) / b;
	co sum el
	ex
}
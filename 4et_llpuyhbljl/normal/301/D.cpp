#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <functional>
#include <bitset>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long
 
struct Fen {
	int fen[200002];
	inline void upd(int x, int val) {
		for (; x >= 0; x = (x & (x + 1)) - 1) fen[x] += val;
	}
	inline int sum(int x) {
		int ans = 0;
		for (; x <= 200000; x |= x + 1) ans += fen[x];
		return ans;
	}
};
 
int a,b,c,d,n,m,k;
int mas[200002], inv[200002];
int ans[200002];
Fen rt;
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	scanf("%d%d", &n, &m);
	rept(i, n) {
		scanf("%d", &mas[i]);
		inv[mas[i]] = i;
	}
	
	vector<pii> tot;
	rep(i, n) {
		for (int j = i; j <= n; j += i) {
			a = inv[i];
			b = inv[j];
			if (a > b) swap(a, b);
			tot.pb(mp(a, b));
		}
	}
 
	SORT(tot);
	vector<pair<pii, int> > quer;
	rept(i, m) {
		scanf("%d%d", &a, &b); --a; --b;
		quer.pb(mp(mp(a, b), i));
	}
	SORT(quer);
 
	a = L(tot) - 1; b = 0;
	FORD(i, L(quer) - 1, 0) {
		while (a >= 0 && tot[a].x >= quer[i].x.x) {
			rt.upd(tot[a].y, 1);
			--a;
			++b;
		}
		int res = b - rt.sum(quer[i].x.y + 1);
		ans[quer[i].y] = res;
	}
	rept(i, m) {
		printf("%d\n", ans[i]);
	}
}
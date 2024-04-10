#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

int t[200200];

int main () {
	int n,k,x;
	scanf("%d%d%d", &n, &k, &x);
	FOR(i,n) scanf("%d", &t[i]);
	long long mult = 1;
	FOR(i,k) mult *= x;
	long long base = 0;
	FOR(i,n) base |= t[i];
	long long one = 0, two = 0;
	FOR(i,n) {
		two |= one&t[i];
		one |= t[i];
	}
	one = base - two;
	long long res = 0;
	FOR(i,n) {
		long long cur = base - (one&t[i]);
		cur |= mult * t[i];
		res = max(cur, res);
	}
	cout << res << endl;
}
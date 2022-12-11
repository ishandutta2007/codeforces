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

int a[156789];

int flo(int x) {
	if (x > 0) return x/2;
	return (x-1) / 2;
}

int main() {
	int n, q=0;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,n) {
		if (a[i] % 2 == 0) {
			a[i] /= 2;
		} else {
			a[i] = flo(a[i]);
			a[i] += q;
			q = 1-q;
		}
	}
	FOR(i,n) printf("%d\n", a[i]);
	return 0;
}
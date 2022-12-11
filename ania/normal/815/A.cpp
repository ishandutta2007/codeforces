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

const int N = 111;

int n,m;
int a[N][N];
int c[N], r[N];

int gen(int r0) {
	FOR(j,m) {
		c[j] = a[0][j] - r0;
		if (c[j] < 0) return -1;
	}
	FOR(i,n) {
		r[i] = a[i][0] - c[0];
		if (r[i] < 0) return -1;
		FOR(j,m) {
			int rt = a[i][j] - c[j];
			if (rt != r[i]) return -1;
		}
	}
	int res=0;
	FOR(i,n) res += r[i];
	FOR(j,m) res += c[j];
	return res;
}

void test() {
	scanf("%d%d", &n, &m);
	FOR(i,n) FOR(j,m) scanf("%d", &a[i][j]);
	int best = -1, who = -1;
	for (int r0 = 0; r0 <= a[0][0]; r0++) {
		int ok = gen(r0);
		if (ok == -1) continue;
		if (who == -1 || ok < best) {
			best = ok;
			who = r0;
		}
	}
	if (who == -1) {
		printf("-1\n");
		return;
	}
	gen(who);
	printf("%d\n", best);
	FOR(i,n) {
		while (r[i]--) printf("row %d\n", i+1);
	}
	FOR(j,m) {
		while (c[j]--) printf("col %d\n", j+1);
	}
}

int main() {
	int ttn=1;
	while (ttn--) test();
	return 0;
}
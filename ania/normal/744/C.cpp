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

const int N = 1<<16;
int r[N], b[N];
char c[N][10];
vector<pii> v[N], sol[N];
int p[N];

void test() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%s %d%d", c[i], &r[i], &b[i]);
	v[0].push_back(mp(0,0));
	int nn=1<<n;
	FOR(mask, nn) {
		sort(v[mask].begin(), v[mask].end());
		sol[mask].push_back(v[mask][0]);
		FORI(i,SZ(v[mask])-1) {
			if (v[mask][i].fi>=sol[mask].back().fi && v[mask][i].se>=sol[mask].back().se) continue;
			sol[mask].push_back(v[mask][i]);
		}
		//printf("mask = %d, sol = ", mask);
		//FOR(i,SZ(sol[mask])) printf("(%d %d), ", sol[mask][i].fi, sol[mask][i].se);
		//printf("\n");
		int R=0, B=0;
		FOR(i,n) if (mask&(1<<i)) {
			if (c[i][0]=='R') R++;
			else B++;
		}
		FOR(i,n) if ((mask&(1<<i))==0) {
			int cr = max(r[i]-R, 0), cb = max(b[i]-B, 0);
			FOR(j,SZ(sol[mask])) {
				v[mask | (1<<i)].push_back(mp(sol[mask][j].fi+cr, sol[mask][j].se+cb));
			}
		}
	}
	int res = 1e9;
	FOR(i,SZ(sol[nn-1])) {
		res = min(res, max(sol[nn-1][i].fi,sol[nn-1][i].se));
	}
	printf("%d\n", res+n);
}

int main() {
	int ttn=1;
	//scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}
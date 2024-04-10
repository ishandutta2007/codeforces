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

const int N = 200200;
int n,m,s;
pii a[N];
pair<pii,int> t[N];
int res[N];

bool ok(int days) {
	int pos = 0, used = 0;
	priority_queue<pii> cand;
	for (int i = 0; i < m; i += days) {
		while (pos < n && t[pos].fi.fi >= a[i].fi) {
			cand.push(mp(-t[pos].fi.se, t[pos].se));
			pos++;
		}
		if (cand.empty()) return false;
		//printf("days = %d: using student %d for bugs %d (%d) and next\n", days, cand.top().se, i, a[i].fi);
		used += -cand.top().fi;
		if (used > s) return false;
		int cur = cand.top().se;
		cand.pop();
		FOR(j,days) if (i+j < m) res[a[i+j].se] = cur+1;
	}
	return true;
}

int main() {
	scanf("%d%d%d", &n, &m, &s);
	FOR(i,m) scanf("%d", &a[i].fi);
	FOR(i,m) a[i].se = i;
	sort(a,a+m);
	reverse(a,a+m);
	FOR(i,n) scanf("%d", &t[i].fi.fi);
	FOR(i,n) scanf("%d", &t[i].fi.se);
	FOR(i,n) t[i].se = i;
	sort(t,t+n);
	reverse(t,t+n);
	bool fnd = 0;
	FOR(i,n) {
		if (t[i].fi.fi < a[0].fi) {
			break;
		}
		if (t[i].fi.se <= s) {
			fnd = 1;
			break;
		}
	}
	if (!fnd) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int lo = 0, hi = m;
	while (lo+1 < hi) {
		int mi = (lo+hi) / 2;
		if (ok(mi)) hi = mi;
		else lo = mi;
	}
	ok(hi);
	FOR(i,m) printf("%d ", res[i]);
	printf("\n");
	return 0;
}
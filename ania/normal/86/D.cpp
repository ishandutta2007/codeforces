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

const int N = 1000200;

int n,q;
int a[N], cnt[N];
ll cur;
ll res[N];
pair<pii,pii> t[N];

void add(int p) {
	int v = a[p];
	//printf("adding t[%d]=%d\n", p, v);
	cur += 1LL * (2*cnt[v]+1) * v;
	cnt[v]++;
}

void rmv(int p) {
	int v = a[p];
	//printf("removing t[%d]=%d\n", p, v);
	cur -= 1LL * (2*cnt[v]-1) * v;
	cnt[v]--;
}

int main() {
	scanf("%d%d", &n, &q);
	FOR(i,n) scanf("%d", &a[i]);
	int m = sqrt(n)+1;
	FOR(i,q) {
		int x,y;
		scanf("%d%d", &x, &y);
		x--;
		t[i] = mp(mp(x/m, y), mp(x, i));
	}
	sort(t,t+q);
	int le = 0, ri = 0;
	FOR(i,q) {
		int x = t[i].se.fi, y = t[i].fi.se;
		//printf("query = %d %d\n", x, y);
		if (x < le) {
			for (int p = le-1; p >= x; p--) {
				add(p);
			}
		} else {
			for (int p = le; p < x; p++) {
				rmv(p);
			}
		}
		if (y < ri) {
			for (int p = ri-1; p >= y; p--) {
				rmv(p);
			}
		} else {
			for (int p = ri; p < y; p++) {
				add(p);
			}
		}
		le = x;
		ri = y;
		res[t[i].se.se] = cur;
	}
	FOR(i,q) printf("%I64d\n", res[i]);
	return 0;
}
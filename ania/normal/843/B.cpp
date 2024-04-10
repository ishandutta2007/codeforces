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

const int limit = 2000;
const int N = 500500;

int n, st, x;
int nxt[N], val[N];
int rval[N], rnxt[N];
pii tt[N];
int que;

void ask(int pos) {
	assert(pos > 0);
	assert(pos <= n);
	if (nxt[pos] != 0) return;
	que++;
	assert(que < limit);
	//val[pos] = rval[pos];
	//nxt[pos] = rnxt[pos];
	//return;
	printf("? %d\n", pos);
	fflush(stdout);
	scanf("%d%d", &val[pos], &nxt[pos]);
	assert(val[pos]>=0);
}

void ans(int v) {
	if (v != -1 && v < x) return;
	printf("! %d -- >%d\n", v, que);
	fflush(stdout);
	exit(0);
}

int myrand() {
	ll rr = 1LL * rand() * rand() % n;
	return rr+1;
}

void init() {
	FORI(i,n) {
		rval[i]=1LL*rand()%rand()%1000000001;
		tt[i]=mp(rval[i], i);
	}
	sort(tt+1,tt+n+1);
	tt[n+1].se=-1;
	FORI(i,n) rnxt[tt[i].se] = tt[i+1].se;
	st=tt[1].se;
}

int main() {
	srand(time(0));
	scanf("%d%d%d", &n, &st, &x);
	//init();
	int lo = st;
	ask(lo);
	ans(val[lo]);
	FOR(iii,limit/2) {
		int c = myrand();
		ask(c);
		if (val[c] < x) {
			if (val[c] > val[lo]) {
				lo = c;
			}
		}
	}
	while (nxt[lo] != -1) {
		int c = nxt[lo];
		ask(c);
		ans(val[c]);
		lo = c;
	}
	ans(-1);
	return 0;
}
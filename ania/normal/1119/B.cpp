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

const int N = 1010;

int h;
int a[N], b[N];

bool ok(int n) {
	FOR(i,n) b[i] = a[i];
	sort(b,b+n);
	reverse(b,b+n);
	b[n] = 0;
	int tot = 0;
	for (int i = 0; i < n; i += 2) {
		tot += b[i];
		if (tot > h) return false;
	}
	return true;
}

void test() {
	int n;
	scanf("%d%d", &n, &h);
	FOR(i,n) scanf("%d", &a[i]);
	int lo = 1, hi = n+1;
	while (lo+1 < hi) {
		int mi = (lo+hi) / 2;
		if (ok(mi)) lo = mi;
		else hi = mi;
	}
	printf("%d\n", lo);
}

int main() {
	int ttn=1;
	//scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}
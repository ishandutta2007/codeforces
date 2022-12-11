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

const int N = 100100;

ll a[N], b[N], suf[N];

void test() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%lld", &a[i]);
	sort(a,a+n);
	FOR(i,n-1) b[i] = a[i+1] - a[i];
	sort(b,b+n-1);
	suf[n-1] = b[n-1];
	for (int i = n-2; i >= 0; i--) suf[i] = suf[i+1] + b[i];
	int q;
	scanf("%d", &q);
	FOR(ii,q) {
		ll le, ri;
		scanf("%lld%lld", &le, &ri);
		ll L = ri - le + 1;
		ll res = a[n-1] - a[0] + L;
		int pos = lower_bound(b, b+n-1, L) - b;
		res -= suf[pos];
		res += L * (n-1-pos);
		printf("%lld\n", res);
	}
}

int main() {
	int ttn=1;
	//scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}
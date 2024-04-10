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

int n,m;
int prv[100100], nxt[100100], a[100100];

int main() {
	scanf("%d%d", &n, &m);
	FORI(i,n) nxt[i] = prv[i] = -1;
	FOR(i,m) {
		FOR(j,n) scanf("%d", &a[j]);
		a[n] = -2;
		for (int j = 1; j <= n; j++) {
			if (nxt[a[j-1]] != -1 && nxt[a[j-1]] != a[j]) {
				nxt[a[j-1]] = -2;
			} else {
				nxt[a[j-1]] = a[j];
			}
		}
	}
	FORI(i,n) {
		if (nxt[i] > 0) prv[nxt[i]] = i;
	}
	ll res = 0;
	FORI(i,n) {
		if (nxt[i] < 0) {
			int x = i, cnt = 0;
			while (x != -1) {
				cnt++;
				x = prv[x];
			}
			res += 1LL * cnt * (cnt+1) / 2;
		}
	}
	printf("%lld\n", res);
	return 0;
}
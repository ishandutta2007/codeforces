#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 200200;

int n,m,p;
int a[2*maxn], b[maxn];

int main() {
	scanf("%d%d%d", &n, &m, &p);
	if (1LL*p*(m-1)+1 > n) {
		printf("0\n");
		return 0;
	}
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,m) scanf("%d", &b[i]);

	vi res;

	for (int q0=0; q0<p; q0++) {
		multiset<int> onlyA, onlyB, both;

		FOR(i,m) onlyB.insert(b[i]);
		FOR(j,m) {
			int i=q0+j*p;
			if (i>=n) {
				q0=n+p+4;
				break;
			}
			if (onlyB.find(a[i]) == onlyB.end()) {
				onlyA.insert(a[i]);
			} else {
				onlyB.erase(onlyB.find(a[i]));
				both.insert(a[i]);
			}
		}
		for (int q=q0; q+p*(m-1) < n; q+=p) {
			if (onlyB.empty()) res.pb(q+1);

			if (q+p*m >= n) break;

			if (onlyA.find(a[q]) != onlyA.end()) {
				onlyA.erase(onlyA.find(a[q]));
			} else {
				both.erase(both.find(a[q]));
				onlyB.insert(a[q]);
			}

			if (onlyB.find(a[q+p*m]) == onlyB.end()) {
				onlyA.insert(a[q+p*m]);
			} else {
				onlyB.erase(onlyB.find(a[q+p*m]));
				both.insert(a[q+p*m]);
			}
		}
	}

	sort(res.begin(), res.end());
	printf("%d\n", SZ(res));
	FOR(i,SZ(res)) printf("%d ", res[i]);
	printf("\n");
	return 0;
}
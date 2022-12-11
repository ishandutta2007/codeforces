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

int a[N], le[N], ri[N];
vi who[2*N];

int main() {
	int n;
	scanf("%d", &n);
	FORI(i,n) scanf("%d", &le[i]);
	FORI(i,n) scanf("%d", &ri[i]);
	FORI(i,n) who[le[i]+ri[i]].pb(i);
	int cur = 1;
	for (int i = n; i >= 0; i--) {
		if (SZ(who[i]) > 0) {
			FOR(j, SZ(who[i])) a[who[i][j]] = cur;
			cur++;
		}
	}
	bool fnd = false;
	FORI(i,n) {
		for (int j = 1; j < i; j++) if (a[j] > a[i]) le[i]--;
		for (int j = i+1; j <= n; j++) if (a[j] > a[i]) ri[i]--;
		if (le[i] != 0 || ri[i] != 0) fnd = true;
	}
	if (fnd) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	FORI(i,n) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
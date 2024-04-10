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

const int N = 2222;

int a[N], b[N];
int useda[N], usedb[N];
int best[N], mini[N];
int hi[N], high[N];
int mata[N], matb[N];
int ta[N], tb[N], qa, qb;

int main() {
	int n,k;
	scanf("%d%d", &n, &k);
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,n) scanf("%d", &b[i]);
	for (int i=n-1; i>=0; i--) {
		mini[i] = i;
		if (i+1 < n && b[mini[i+1]] < b[i]) mini[i] = mini[i+1];
	}
	FOR(i,n) best[i] = mini[i];
	ll score = 0;
	FOR(ii,k) {
		/*FOR(i,n) printf("%d ", best[i]);
		printf("\n");
		FOR(i,n) printf("%d ", useda[i]);
		printf("\n");
		FOR(i,n) printf("%d ", usedb[i]);
		printf("\n");*/
		int who = -1;
		FOR(i,n) if (!useda[i]) {
			if (who==-1) who=i;
			else if (a[i]+b[best[i]] < a[who]+b[best[who]]) {
				who = i;
			}
		}
		score += a[who] + b[best[who]];
		//printf("adding %d and %d (%d and %d)\n", who, best[who], a[who], b[best[who]]);
		useda[who] = 1;
		usedb[best[who]] = 1;
		qa=qb=0;
		FOR(i,n) {
			if (useda[i]) ta[qa++] = i;
			if (usedb[i]) tb[qb++] = i;
		}
		FOR(i,n) mata[i] = matb[i] = -1;
		FOR(i,qa) {
			mata[ta[i]] = tb[i];
			matb[tb[i]] = ta[i];
			assert(ta[i] <= tb[i]);
			if (i>0 && ta[i] <= tb[i-1]) {
				high[tb[i]] = high[tb[i-1]];
			} else {
				high[tb[i]] = ta[i];
			}
		}
		for (int i=n-1; i>=0; i--) {
			mini[i] = -1;
			if (!usedb[i]) mini[i] = i;
			if (i+1 < n) {
				if (mini[i] == -1) mini[i] = mini[i+1];
				else if (mini[i+1] != -1 && b[mini[i+1]] < b[i]) mini[i] = mini[i+1];
			}
		}
		for (int i=n-1; i>=0; i--) {
			hi[i] = -1;
			if (!usedb[i]) hi[i] = i;
			else hi[i] = high[i];
			if (i+1 < n && hi[i+1] < hi[i]) hi[i] = hi[i+1];
		}
		FOR(i,n) {
			best[i] = -1;
			if (!useda[i]) best[i] = mini[hi[i]];
		}
	}
	cout << score << "\n";
	return 0;
}
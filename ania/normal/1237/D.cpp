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

int n;
int a[N], b[2*N], rg[2*N];
pii cmins[2*N];

int main() {
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	int mna = a[0], mxa = a[0];
	FOR(i,n) {
		mxa = max(mxa,a[i]);
		mna = min(mna,a[i]);
	}
	if (mna*2 >= mxa) {
		FOR(i,n) printf("-1 ");
		printf("\n");
		return 0;
	}
	int shift = -1;
	FOR(i,n) if (a[i] == mxa) {
		FOR(j,2*n) b[j] = a[(i+j)%n];
		shift = i;
		break;
	}
	FOR(j,n) if (b[j]*2 < b[0]) {
		rg[n] = n+j;
		break;
	}
	cmins[0] = mp(b[n-1], n-1);
	int cpos = 0;
	for (int j = n-1; j >= 0; j--) {
		while (cpos >= 0 && b[j] <= cmins[cpos].fi) cpos--;
		cpos++;
		cmins[cpos] = mp(b[j], j);
		int pos = lower_bound(cmins, cmins+cpos+1, mp((b[j]+1)/2, -1)) - cmins;
		rg[j] = rg[j+1];
		if (pos > 0) {
			pos--;
			rg[j] = min(rg[j], cmins[pos].se);
		}
		//printf("j=%d, s=%d, rg=%d, cm= ", j, shift, rg[j]);
		//FOR(i,cpos+1) printf("(%d %d) ", cmins[i].fi, cmins[i].se);
		//printf("\n");
	}
	for (int i = n-shift; i < n; i++) printf("%d ", rg[i]-i);
	for (int i = 0; i < n-shift; i++) printf("%d ", rg[i]-i);
	printf("\n");
	return 0;
}
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

int n, m;
vi v[200*200];

int main() {
	scanf("%d", &n);
	m = n*(n-1)/2;
	FOR(i,m) {
		int k;
		scanf("%d", &k);
		v[i].resize(k);
		FOR(j,k) scanf("%d", &v[i][j]);
		sort(v[i].begin(), v[i].end());
	}
	if (n==2) {
		printf("1 %d\n%d ", v[0][0], SZ(v[0])-1);
		for (int i=1; i<SZ(v[0]); i++) printf("%d ", v[0][i]);
		printf("\n");
		return 0;
	}
	int x = v[0][0];
	vi vx;
	for (int i=1; i<m; i++) {
		bool fnd = 0;
		FOR(j,SZ(v[i])) if (v[i][j]==x) {
			fnd = 1;
			break;
		}
		if (!fnd) continue;
		for (int a = 0, b = 0; a < SZ(v[0]) && b < SZ(v[i]); ) {
			if (v[0][a] == v[i][b]) {
				vx.pb(v[0][a]);
				a++;
				b++;
			} else if (v[0][a] < v[i][b]) {
				a++;
			} else {
				b++;
			}
		}
		break;
	}
	printf("%d ", SZ(vx));
	FOR(i,SZ(vx)) printf("%d ", vx[i]);
	printf("\n");
	FOR(i,m) {
		bool fnd = 0;
		FOR(j,SZ(v[i])) if (v[i][j]==x) {
			fnd = 1;
			break;
		}
		if (!fnd) continue;
		vi vc;
		for (int a=0, b=0; b < SZ(v[i]); ) {
			if (a==SZ(vx) || vx[a] > v[i][b]) {
				vc.pb(v[i][b]);
				b++;
			} else {
				a++;
				b++;
			}
		}
		printf("%d ", SZ(vc));
		FOR(j,SZ(vc)) printf("%d ", vc[j]);
		printf("\n");
	}
	return 0;
}
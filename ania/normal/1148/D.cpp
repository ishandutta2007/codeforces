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

const int N = 300300;
pair<pii, int> t[2][N];

int main() {
	int n, n0 = 0, n1 = 0;
	scanf("%d", &n);
	FORI(i,n) {
		int a,b;
		scanf("%d%d", &a, &b);
		if (a < b) {
			t[0][n0] = mp(mp(a, b), i);
			n0++;
		} else {
			t[1][n1] = mp(mp(b, a), i);
			n1++;
		}
	}
	if (n0 > n1) {
		sort(t[0], t[0]+n0);
		printf("%d\n", n0);
		for (int i = n0-1; i >= 0; i--) printf("%d ", t[0][i].se);
		printf("\n");
	} else {
		sort(t[1], t[1]+n1);
		printf("%d\n", n1);
		for (int i = 0; i < n1; i++) printf("%d ", t[1][i].se);
		printf("\n");
	}
	return 0;
}
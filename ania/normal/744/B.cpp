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
const int inf = 1000000007;

int t[22][N], m[22][N];
int r[N], l[22];

void test() {
	int n,q;
	scanf("%d", &n);
	FOR(i,10) {
		q=0;
		FOR(j,n) if (j&(1<<i)) t[i][q++] = j;
		if (q==0) {
			FOR(j,n) m[i][j]=inf;
			continue;
		}
		printf("%d\n", q);
		//printf("%d: %d\n", i, q);
		FOR(j,q) printf("%d ", t[i][j]+1);
		printf("\n");
		l[i]=q;
		fflush(stdout);
		FOR(j,n) scanf("%d", &m[i][j]);
	}
	for (int i=10;i<20;i++) {
		q=0;
		FOR(j,n) if ((j&(1<<(i-10)))==0) t[i][q++] = j;
		if (q==0) {
			FOR(j,n) m[i][j]=inf;
			continue;
		}
		printf("%d\n", q);
		//printf("%d: %d\n", i, q);
		FOR(j,q) printf("%d ", t[i][j]+1);
		l[i]=q;
		printf("\n");
		fflush(stdout);
		FOR(j,n) scanf("%d", &m[i][j]);
	}
	FOR(i,n) r[i]=inf;
	printf("-1\n");
	FOR(i,n) {
		//printf("%d -- ", i);
		FOR(j,20) {
			bool f=0;
			FOR(k,l[j]) if (t[j][k]==i) {
				f=1;
				break;
			}
			if (l[j]==0) f=1;
			if (!f) {
				//printf("%d ", j);
				r[i] = min(r[i], m[j][i]);
			}
		}
		printf("%d ", r[i]);
	}
	fflush(stdout);
}

int main() {
	int ttn=1;
	//scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}
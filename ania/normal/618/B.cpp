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

int p[55], t[55][55], used[55];

void test() {
	int n;
	scanf("%d", &n);
	FOR(i,n) FOR(j,n) scanf("%d", &t[i][j]);
	FORI(a,n) {
		FOR(i,n) if (!used[i]) {
			bool ok=1;
			FOR(j,n) if (!used[j] && i!=j) if (t[i][j] != a) ok=0;
			if (ok) {
				used[i]=1;
				p[i]=a;
				break;
			}
		}
	}
	FOR(i,n) printf("%d ", p[i]);
	printf("\n");
}

int main() {
	test();
	return 0;
}
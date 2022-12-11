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
pii a[N];
int used[N];
vector<vi> res;

int main() {
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d", &a[i].fi);
		a[i].se = i;
	}
	sort(a,a+n);
	FOR(i,n) if (!used[i]) {
		int x = i;
		vi cur;
		while (!used[x]) {
			cur.pb(x);
			used[x] = 1;
			x = a[x].se;
		}
		res.pb(cur);
	}
	printf("%d\n", SZ(res));
	FOR(i,SZ(res)) {
		printf("%d ", SZ(res[i]));
		FOR(j,SZ(res[i])) printf("%d ", res[i][j]+1);
		printf("\n");
	}
	return 0;
}
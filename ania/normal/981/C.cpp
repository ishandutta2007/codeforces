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

int n;
vi g[100100];
vi v1,v2;

int main() {
	scanf("%d", &n);
	FOR(i,n-1) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	FOR(i,n) {
		if (SZ(g[i]) == 1) v1.pb(i);
		else {
			if (SZ(g[i]) != 2) v2.pb(i);
		}
	}
	if (SZ(v2) > 1) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	if (SZ(v2) == 0) {
		printf("1\n%d %d\n", v1[0]+1, v1[1]+1);
		return 0;
	}
	printf("%d\n", SZ(v1));
	FOR(i,SZ(v1)) {
		printf("%d %d\n", v2[0]+1, v1[i]+1);
	}
	return 0;
}
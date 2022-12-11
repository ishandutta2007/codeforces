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
int a[N], pos[N];
vector<pii> swp;

void make_swap(int i, int j) {
	if (i > j) swap(i,j);
	swp.pb(mp(i, j));
	swap(a[i], a[j]);
	pos[a[i]] = i;
	pos[a[j]] = j;
}

int main() {
	int n;
	scanf("%d", &n);
	FORI(i,n) {
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	FORI(i,n) {
		int p = pos[i];
		if (p == i) continue;
		if (abs(p-i) * 2 >= n) {
			make_swap(i,p);
		} else {
			if (i <= n/2 && p <= n/2) {
				make_swap(p, n);
				make_swap(n, i);
			} else if (i > n/2 && p > n/2) {
				make_swap(p, 1);
				make_swap(1, i);
				make_swap(p, 1);
			} else {
				make_swap(p, 1);
				make_swap(1, n);
				make_swap(n, i);
				make_swap(p, 1);
			}
		}
	}
	printf("%d\n", SZ(swp));
	FOR(i,SZ(swp)) printf("%d %d\n", swp[i].fi, swp[i].se);
	return 0;
}
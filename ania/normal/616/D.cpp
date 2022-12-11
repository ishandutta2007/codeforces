#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int a[500500];
int occ[1000100];

int main() {
	int n,k;
	scanf("%d%d", &n, &k);
	FOR(i,n) scanf("%d", &a[i]);
	int le = 0, ri = 0;
	int best = -5, bestl = -1;
	set<int> S;
	while (le < n) {
		while (ri < n && (S.size() < k || (S.size() == k && S.find(a[ri]) != S.end()))) {
			S.insert(a[ri]);
			occ[a[ri]]++;
			ri++;
		}
		if (ri-le > best) {
			best = ri-le;
			bestl = le;
		}
		if (occ[a[le]]==1) S.erase(a[le]);
		occ[a[le]]--;
		le++;
	}
	printf("%d %d\n", bestl+1, bestl+best);
	return 0;
}
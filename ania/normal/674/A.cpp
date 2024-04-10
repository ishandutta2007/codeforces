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

const int maxn = 5050;

int res[maxn], occ[maxn], t[maxn];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &t[i]);
	FOR(i,n) {
		priority_queue<pii> q;
		int best = 0, who = 1;
		FORI(j,n) occ[j]=0;
		for (int j = i; j < n; j++) {
			occ[t[j]]++;
			if (occ[t[j]] > best || (occ[t[j]] == best && t[j]<who)) {
				best = occ[t[j]];
				who = t[j];
			}
			res[who]++;
		}
	}
	FORI(i,n) printf("%d ", res[i]);
	printf("\n");
	return 0;
}
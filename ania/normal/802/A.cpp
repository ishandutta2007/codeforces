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

const int N = 400400;

int n,k;
int a[N], have[N], nxt[N], prv[N];
int pos[N];

int main() {
	scanf("%d%d", &n, &k);
	FOR(i,n) scanf("%d", &a[i]);
	FORI(i,n) nxt[i] = n+1;
	for (int i=n-1; i>=0; i--) {
		prv[i] = nxt[a[i]];
		nxt[a[i]] = i;
	}
	//FOR(i,n) printf("prv %d (%d) = %d\n", i, a[i], prv[i]);
	set<pii> q;
	int num=0, res=0;
	FOR(i,n) {
		if (have[a[i]]) {
			q.erase(q.find(mp(pos[a[i]], a[i])));
			q.insert(mp(prv[i], a[i]));
			pos[a[i]] = prv[i];
			continue;
		}
		if (num < k) {
			have[a[i]] = 1;
			pos[a[i]] = prv[i];
			q.insert(mp(prv[i], a[i]));
			res++;
			num++;
			//printf("just adding %d\n", a[i]);
		} else {
			pii who = *q.rbegin();
			q.erase(q.find(who));
			have[who.se] = 0;
			q.insert(mp(prv[i], a[i]));
			res++;
			have[a[i]] = 1;
			pos[a[i]] = prv[i];
			//printf("removing %d, adding %d\n", who.se, a[i]);
		}
	}
	printf("%d\n", res);
	return 0;
}
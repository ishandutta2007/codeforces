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

const int maxn = 200200;

int n,q;
int p[maxn], l[maxn], need[maxn], pref[maxn], suff[maxn];
pair<pii,int> t[maxn];
int res[maxn];

int main() {
	scanf("%d",&n);
	vi gap;
	FOR(i,n) scanf("%d%d", &p[i], &l[i]);
	scanf("%d", &q);
	FOR(i,q) {
		scanf("%d%d", &t[i].fi.fi, &t[i].fi.se);
		t[i].fi.fi--; t[i].fi.se--;
		t[i].se=i;
	}
	sort(t,t+q);
	int pos=q-1;
	gap.pb(n);
	p[n] = p[n-1]+1000000009;
	for (int i=n-1; i>=0; i--) {
		if (p[i]+l[i] < p[i+1]) {
			need[i+1] = p[i+1] - p[i] - l[i];
			suff[i+1] = suff[gap.back()] + need[i+1];
			gap.pb(i+1);
		}
		while (p[i]+l[i] >= p[gap.back()]) gap.pop_back();
		int u=gap.back();
		need[u] = min(need[u], p[u]-p[i]-l[i]);
		suff[u] = suff[gap[SZ(gap)-2]] + need[u];
		//FOR(j,SZ(gap)) printf("[%d %d %d], ", gap[j], need[gap[j]], suff[gap[j]]); printf("\n");

		while (pos >= 0 && t[pos].fi.fi == i) {
			//printf("%d : %d %d %d\n", pos, t[pos].fi.fi, t[pos].fi.se, t[pos].se);
			int all = suff[gap.back()];
			int endpos = lower_bound(gap.begin(), gap.end(), t[pos].fi.se, greater<int>()) - gap.begin() - 1;
			int sufv = suff[gap[endpos]];
			//printf("all = %d, endpos = %d %d\n", all, endpos, sufv);
			res[t[pos].se] = all-sufv;
			pos--;
		}
	}
	FOR(i,q) printf("%d\n", res[i]);
	return 0;
}
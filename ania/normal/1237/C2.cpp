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

const int N = 50500;
const int inf = 1000000007;

int n;
int done;
int used[N];
pair<pii,pii> t[N];

void snap(int idx, int idy) {
	printf("%d %d\n", t[idx].se.se+1, t[idy].se.se+1);
	used[idx] = used[idy] = 1;
	done += 2;
}

int main() {
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d%d%d", &t[i].fi.fi, &t[i].fi.se, &t[i].se.fi);
		t[i].se.se = i;
	}
	int nn = n;
	while(done < n) {
		sort(t,t+nn);
		FOR(i,nn) used[i] = 0;
		t[nn] = mp(mp(inf,inf), mp(inf,n));
		FOR(i,nn-1) {
			if (t[i+2].fi.fi != t[i+1].fi.fi) {
				snap(i,i+1);
				i++;
			} else if (t[i].fi.fi == t[i+1].fi.fi) {
				if (t[i+2].fi.se != t[i+1].fi.se) {
					snap(i,i+1);
					i++;
				} else if (t[i].fi.se == t[i+1].fi.se) {
					snap(i,i+1);
					i++;
				}
			}
		}
		int m = 0;
		FOR(i,nn) if (!used[i]) t[m++] = t[i];
		nn = m;
		//printf("nn = %d\n", nn);
	}
	return 0;
}
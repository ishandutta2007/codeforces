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

#define ANS_NO { printf("NO\n"); return 0; }

int n;
pii s[N];
int t[N];

vector<pair<pii,int> > mvs;
void move_stone(int pl, int pr, int d) {
	//printf("moving %d (%d) and %d (%d) by %d\n", s[pl].se, s[pl].fi, s[pr].se, s[pr].fi, d);
	s[pl].fi += d;
	s[pr].fi -= d;
	mvs.pb(mp(mp(s[pl].se, s[pr].se), d));
}

int main() {
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d", &s[i].fi);
		s[i].se = i+1;
	}
	FOR(i,n) scanf("%d", &t[i]);
	ll sum = 0;
	FOR(i,n) {
		sum += s[i].fi;
		sum -= t[i];
	}
	if (sum != 0) {
		ANS_NO;
	}
	sort(s,s+n);
	sort(t,t+n);
	ll cur = 0;
	FOR(i,n) {
		cur += t[i] - s[i].fi;
		if (cur < 0) {
			ANS_NO;
		}
	}
	vi have;
	FOR(i,n) {
		if (t[i] > s[i].fi) {
			have.pb(i);
		} else {
			int need = s[i].fi - t[i];
			while (need > 0) {
				int p = have.back();
				int d = min(need, t[p] - s[p].fi);
				move_stone(p, i, d);
				need -= d;
				if (t[p] == s[p].fi) have.pop_back();
			}
		}
	}
	printf("YES\n");
	printf("%d\n", SZ(mvs));
	FOR(i,SZ(mvs)) printf("%d %d %d\n", mvs[i].fi.fi, mvs[i].fi.se, mvs[i].se);
	return 0;
}
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

const int N = 100100;

int n, k, kt;
ll a[N], b[N], v[N];
int cnt[55], tcnt[55];

bool can(int mxm) {
	int m=0;
	while (cnt[0] && m<mxm) {
		int p = 0;
		while (cnt[p]) {
			cnt[p]--;
			p++;
		}
		v[m++] =  p;
	}
	FOR(i,40) while (cnt[i]) {
		cnt[i]--;
		a[k++] = 1LL<<i;
	}
	if (k > m) return false;
	sort(a,a+k);
	sort(v, v+m);
	FOR(i,k) if (a[i] > 1LL<<v[m-k+i]) return false;
	return true;
}

bool ok(int m) {
	FOR(i,n) a[i] = b[i];
	FOR(i,40) cnt[i] = tcnt[i];
	k = kt;
	bool ret= can(m);
	//printf("ok %d = %d\n", m, ret);
	return ret;
}

int main() {
	cin>>n;
	FOR(i,n) cin>>a[i];
	FOR(p,40) {
		FOR(i,n) if (a[i] == 1LL<<p) {
			cnt[p]++;
			tcnt[p]++;
			a[i] = -1;
		}
	}
	FOR(i,n) if (a[i] != -1) {
		b[k++] = a[i];
	}
	kt=k;
	FOR(i,k) a[i] = b[i];
	
	if (!ok(n)) {
		printf("-1\n");
		return 0;
	}
	int lo = 0, hi = tcnt[0];
	while (lo+1 < hi) {
		int mi = (lo+hi)/2;
		if (ok(mi)) hi=mi;
		else lo=mi;
	}
	REP(i,hi,tcnt[0]) printf("%d ", i);
	printf("\n");
	return 0;
}
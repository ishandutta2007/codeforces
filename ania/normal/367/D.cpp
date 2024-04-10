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

int t[100100];
bool bad[1<<20];
int cur[22];

int main() {
	int n,m,d,k,a;
	scanf("%d%d%d", &n, &m, &d);
	FOR(i,m) {
		scanf("%d", &k);
		FOR(j,k) {
			scanf("%d", &a);
			t[a-1] = i;
		}
	}
	int mask=0;
	FOR(i,d) {
		mask |= 1<<t[i];
		cur[t[i]]++;
		//printf("add %d\n", t[i]);
	}
	for (int i = 0; i+d <= n; i++) {
		bad[mask] = 1;
		//printf("bad %d\n", mask);
		if (i+d >= n) break;
		//printf("add %d, rem %d\n", t[i+d], t[i]);
		cur[t[i]]--;
		if (cur[t[i]] == 0) mask ^= 1<<t[i];
		if (cur[t[i+d]] == 0) mask ^= 1<<t[i+d];
		cur[t[i+d]]++;
	}
	FOR(_,20) {
		int fnd=false;
		FOR(x,1<<m) if (bad[x]) FOR(i,20) {
			if (x & (1<<i)) continue;
			if (bad[x^(1<<i)]) continue;
			bad[x^(1<<i)]=1;
			fnd=true;
		}
		if (!fnd) break;
	}
	int res=0;
	FOR(i,1<<m) if (!bad[i]) res = max(res, __builtin_popcount(i));
	printf("%d\n", m-res);
	return 0;
}
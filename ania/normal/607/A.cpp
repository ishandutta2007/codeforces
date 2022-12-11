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

const int maxn = 100100;

int n;
int a[maxn], b[maxn], d[maxn];
pii t[maxn];

int main() {
	scanf("%d", &n);
	FOR(i,n) scanf("%d%d", &t[i].fi, &t[i].se);
	sort(t,t+n);
	FOR(i,n) {
		a[i]=t[i].fi;
		b[i]=t[i].se;
	}
	int res = n;
	FOR(i,n) {
		int p = lower_bound(a, a+n, a[i]-b[i]) - a;
		d[i] = (p==0?0:d[p-1]) + i-p;
		res = min(res, d[i] + n - i - 1);
		//printf("d[%d] = %d\n", i, d[i]);
	}
	printf("%d\n", res);
	return 0;
}
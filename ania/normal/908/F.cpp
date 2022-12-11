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

int lo[3], hi[3];
int p[N], c[N];
char tmp[6];

int main() {
	int n;
	scanf("%d", &n);
	lo[0]=lo[1]=lo[2]=-1;
	hi[0]=hi[1]=hi[2]=-1;
	FOR(i,n) {
		scanf("%d%s", &p[i], tmp);
		c[i] = tmp[0]=='G' ? 0 : tmp[0]=='R' ? 1 : 2;
		if (lo[c[i]]==-1) lo[c[i]]=i;
		hi[c[i]]=i;
	}
	if (lo[0]==-1) {
		int res=0;
		if (lo[1]!=-1) res += p[hi[1]]-p[lo[1]];
		if (lo[2]!=-1) res += p[hi[2]]-p[lo[2]];
		printf("%d\n", res);
		return 0;
	}
	int res = 0;
	FORI(i,2) {
		if (lo[i]!=-1 && lo[i]<lo[0]) res += p[lo[0]]-p[lo[i]];
		if (hi[i]!=-1 && hi[i]>hi[0]) res += p[hi[i]]-p[hi[0]];
	}
	//printf("initial res = %d\n", res);
	int la = lo[0];
	for (int i = lo[0]+1; i <= hi[0]; i++) {
		if (c[i] == 0) {
			int xle = p[la], xri = p[i];
			int l[3] = {0, xle, xle}, mx[3] = {0,0,0}, f[3] = {0,0,0};
			for (int j = la+1; j < i; j++) {
				f[c[j]] = 1;
				mx[c[j]] = max(mx[c[j]], p[j]-l[c[j]]);
				l[c[j]] = p[j];
			}
			FORI(j,2) mx[j] = max(mx[j], p[i]-l[j]);
			//printf("segment %d %d -- l = %d %d, mx = %d %d, f = %d %d\n", xle, xri, l[1], l[2], mx[1], mx[2], f[1], f[2]);
			if (f[1] && f[2] && 2*(xri-xle) < 3*(xri-xle) - mx[1] - mx[2]) {
				res += 2*(xri-xle);
			} else {
				res += 3*(xri-xle) - mx[1] - mx[2];
			}
			la = i;
		}
	}
	printf("%d\n", res);
	return 0;
}
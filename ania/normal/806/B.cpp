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

int bnds[6][2] = {{2,1}, {4,2}, {8,4}, {16,8}, {32,16}, {1073741824,32}};
int a[222][5], sc[5], c[5], sum[2];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) FOR(j,5) {
		scanf("%d", &a[i][j]);
		if (a[i][j] != -1) c[j]++;
	}
	int res = 1000000008;
	FOR(mask, 7776) {
		int mtt=mask;
		FOR(i,5) {
			sc[i] = mtt%6;
			mtt /= 6;
		}
		sum[0]=sum[1]=0;
		FOR(j,2) FOR(i,5) {
			if (a[j][i] != -1) sum[j] += (sc[i]+1) * (500 - 2*a[j][i]);
		}
		if (sum[0] <= sum[1]) continue;
		int kmin = 0, kmax = 1000000007;
		FOR(i,5) if (c[i]>0) {
			int b0 = bnds[sc[i]][0], b1 = bnds[sc[i]][1];
			kmin = max(kmin, c[i]*b1 - n);
			kmin = max(kmin, int((n-1LL*b0*c[i]) / (b0-1) + 1));
			if (a[0][i] == -1) {
				int tmp = min(1000000008LL, 1LL*b0*c[i]-n-1);
				kmax = min(kmax, tmp);
			}
		}
		//if (kmin == 1) printf("%d %d %d %d %d\n", sc[0], sc[1], sc[2], sc[3], sc[4]);
		//if (kmin == 1) printf("%d %d -- %d\n", sum[0], sum[1], kmax);
		if (kmin > kmax) continue;
		res = min(res, kmin);
	}
	if (res > 1000000007) printf("-1\n");
	else printf("%d\n", res);
	return 0;
}
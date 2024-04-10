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

int t[1010];
int main() {
	int n,m,h,s=0;
	scanf("%d%d%d", &n, &m, &h);
	h--;
	FOR(i,m) {
		scanf("%d", &t[i]);
		s += t[i];
	}
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	if (s < n) {
		printf("-1\n");
		return 0;
	}
	n--;
	s--;
	t[h]--;
	double res = 1;
	for (int i = n; i >= 1; i--) {
		res *= 1.0 * (s-t[h]-n+i) / (s-n+i);
	}
	printf("%.10lf\n", 1.0-res);
	return 0;
}
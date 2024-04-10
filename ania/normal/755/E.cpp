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

int main() {
	int n,k;
	scanf("%d%d", &n, &k);
	if (k<2 || k>=4 || n<=3) {
		printf("-1\n");
		return 0;
	}
	if (n==4) {
		if (k==3) printf("3\n1 2\n2 3\n3 4\n");
		else printf("-1\n");
		return 0;
	}
	if (k==2) {
		printf("%d\n", n-1);
		FOR(i,n-1) printf("%d %d\n", i+1, i+2);
		return 0;
	}
	n -= 4;
	int m=2*n + n*(n-1)/2 + 3;
	printf("%d\n", m);
	FORI(i,n) FORI(j,i-1) printf("%d %d\n", j, i);
	FORI(i,n) for (int j=n+2;j<n+4;j++) printf("%d %d\n", i,j);
	printf("%d %d\n%d %d\n%d %d\n", n+1, n+2, n+2, n+3, n+3, n+4);
	return 0;
}
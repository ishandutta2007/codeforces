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

int n;
int a[11111];

int main() {
	scanf("%d", &n);
	FORI(i,n) scanf("%d", &a[i]);
	int tot = a[1], coal = a[1], cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i]*2 <= a[1]) {
			coal += a[i];
			cnt++;
		}
		tot += a[i];
	}
	if (coal*2 > tot) {
		printf("%d\n1 ", cnt);
		for (int i = 2; i <= n; i++) if (a[i]*2 <= a[1]) printf("%d ", i);
		printf("\n");
	} else {
		printf("0\n");
	}
	return 0;
}
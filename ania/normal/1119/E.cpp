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

int a[300300];
int dp[300300];

void test() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	dp[0] = a[0] % 3;
	int sum = a[0] % 3;
	ll tot = a[0];
	for (int i = 1; i < n; i++) {
		tot += a[i];
		sum = (a[i] + sum) % 3;
		if (a[i] == 1) {
			dp[i] = dp[i-1] + 1;
		} else {
			int need = a[i] / 2;
			if (a[i] % 2 == 1) need = (a[i]-3) / 2;
			if (dp[i-1] >= need) dp[i] = dp[i-1]-need;
			else dp[i] = sum % 3;
		}
	}
	printf("%lld\n", (tot-dp[n-1]) / 3);
}

int main() {
	int ttn=1;
	//scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}
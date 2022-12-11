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

const int N = 100100;

int dp[N], t[N];

void test() {
	int n;
	scanf("%d", &n);
	FORI(i,n) scanf("%d", &t[i]);
	int j = 1, k = 1;
	FORI(i,n) {
		dp[i] = dp[i-1] + 20;
		while (j<i && t[j]+90<=t[i]) j++;
		while (k<i && t[k]+1440<=t[i]) k++;
		dp[i] = min(dp[i], dp[j-1] + 50);
		dp[i] = min(dp[i], dp[k-1] + 120);
		printf("%d\n", dp[i]-dp[i-1]);
	}
}

int main() {
	test();
	return 0;
}
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

const int N = 200200;
int a[N], b[N];

int main() {
	int n,m,k,ta,tb;
	scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,m) scanf("%d", &b[i]);
	if (n <= k || m <= k) {
		printf("-1\n");
		return 0;
	}
	int j = 0;
	int res = -1;
	FOR(i,n+1) { // delete all before a[i]
		if (i > k) break;
		int b_arr = a[i] + ta;
		while (j < m && b[j] < b_arr) j++;
		int pos = j + (k-i);
		if (pos >= m) {
			printf("-1\n");
			return 0;
		}
		res = max(res, b[pos]+tb);
	}
	printf("%d\n", res);
	return 0;
}
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

int c[33];

ll rec(int tot, int pos) {
	int cnt = tot >> pos;
	if (pos == 0) return 1LL * cnt * c[pos];
	return min(1LL * (cnt+1) * c[pos], 1LL * cnt * c[pos] + rec(tot-cnt*(1<<pos), pos-1));
}

int main() {
	int n,tot;
	scanf("%d%d", &n, &tot);
	FOR(i,n) scanf("%d", &c[i]);
	for (int i = 1; i < n; i++) c[i] = min(c[i], c[i-1]*2);
	for (int i = n-2; i >= 0; i--) c[i] = min(c[i], c[i+1]);
	cout << rec(tot,n-1) << "\n";
	return 0;
}
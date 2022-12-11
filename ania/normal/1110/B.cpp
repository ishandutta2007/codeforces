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

int b[100100], d[100100];
int main() {
	int n,m,k;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i,n) scanf("%d", &b[i]);
	FORI(i,n-1) d[i] = b[i]-b[i-1]-1;
	sort(d+1,d+n);
	int res = n;
	for (int i = 1; i <= n-k; i++) res += d[i];
	printf("%d\n", res);
	return 0;
}
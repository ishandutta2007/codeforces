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

int a[N], b[N], r[N];
pii t[N];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,n) scanf("%d", &b[i]);
	sort(a,a+n);
	FOR(i,n) t[i] = mp(b[i], i);
	sort(t,t+n);
	FOR(i,n) r[t[i].se] = a[n-i-1];
	FOR(i,n) printf("%d ", r[i]);
	printf("\n");
	return 0;
}
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

int a[100100], b[100100];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,n) scanf("%d", &b[i]);
	for (int i = n-1; i > 0; i--) {
		a[i] -= a[i-1];
		b[i] -= b[i-1];
	}
	sort(a+1,a+n);
	sort(b+1,b+n);
	FOR(i,n) if (a[i] != b[i]) {
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}
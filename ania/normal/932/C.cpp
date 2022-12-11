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

void per(int st, int len) {
	for (int i = st+1; i < st+len; i++) printf("%d ", i);
	printf("%d ", st);
}

int main() {
	int n,a,b;
	scanf("%d%d%d", &n, &a, &b);
	for (int x = 0; x*a <= n; x++) if ((n-x*a)%b == 0) {
		FOR(i,x) {
			per(i*a+1, a);
		}
		for (int i = x*a; i < n; i+=b) {
			per(i+1, b);
		}
		printf("\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}
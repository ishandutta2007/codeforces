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

int t[22];

int main() {
	FOR(i,11) scanf("%d", &t[i]);
	REPD(i,10,0) {
		double res = 5.0 * t[i] * t[i] * t[i] + sqrt(1.0 * abs(t[i]));
		if (res < 400) printf("f(%d) = %.2lf\n", t[i], res);
		else printf("f(%d) = MAGNA NIMIS!\n", t[i]);
	}
	return 0;
}
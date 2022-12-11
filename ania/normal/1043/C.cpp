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

char s[1010];
int re[1010];
int n;

int main() {
	scanf("%s", s);
	for (n=0; s[n]; n++) ;
	bool incr = 1;
	for (int k = n-1; k >= 0; k--) {
		if ((s[k] == 'a') == incr) {
			re[k] = 1;
			incr = !incr;
		}
	}
	FOR(i,n) printf("%d ", re[i]);
	printf("\n");
	return 0;
}
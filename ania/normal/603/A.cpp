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

const int maxn = 100100;

int n;
char s[maxn];
int best[2][5], tmp[2][5];

int main () {
	scanf("%d %s", &n, s);
	FOR(i,n) {
		FOR(a,2) FOR(b,3) {
			if (a==s[i]-'0') {
				tmp[a][b+1] = max(tmp[a][b+1], best[a][b]+1);
			} else {
				tmp[a][b] = max(tmp[a][b], best[1-a][b]+1);
			}
		}
		FOR(a,2) FOR(b,3) best[a][b]=tmp[a][b];
	}
	int res = 0;
	FOR(a,2) FOR(b,3) res=max(res,best[a][b]);
	printf("%d\n", res);
	return 0;
}
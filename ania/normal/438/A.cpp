#include <cstdio>
#include <algorithm>
using namespace std;

using namespace std;

#define REP(i,a,b) for (int i = (a); i <= (b); i++)
#define REPD(i,a,b) for (int i = (a); i >=(b); i--)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); i++)
#define fi first
#define se second

int n,m;
int v[2222];

int main() {
	int res = 0;
	scanf("%d%d", &n, &m);
	FOR(i,n) scanf("%d", &v[i]);
	FOR(i,m) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		res += min(v[a], v[b]);
	}
	printf("%d\n", res);
	return 0;
}
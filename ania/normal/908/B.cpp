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

int p[4];
char t[333];
char s[333][333];
int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	FOR(i,n) scanf("%s", s[i]);
	scanf("%s", t);
	FOR(i,4) p[i]=i;
	int res=0;
	do {
		int x = -1, y = -1;
		FOR(i,n) FOR(j,m) if (s[i][j]=='S') x=i, y=j;
		bool ok=false;
		for (int i = 0; t[i]; i++) {
			x += dx[p[t[i]-'0']];
			y += dy[p[t[i]-'0']];
			if (x<0 || y<0 || x>=n || y>=m) {
				ok=false;
				break;
			}
			if (s[x][y]=='#') {
				ok=false;
				break;
			}
			if (s[x][y]=='E') {
				ok=true;
				break;
			}
		}
		res += ok;
	} while (next_permutation(p,p+4));
	printf("%d\n", res);
	return 0;
}
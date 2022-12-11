#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second


int n;
int c[100100];
vi g[100100];

int main() {
	scanf("%d", &n);
	FOR(i,n-1) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].push_back(b);
	}
	FOR(i,n) scanf("%d", &c[i]);
	int x = -1, y = -1;
	FOR(i,n) FOR(j,SZ(g[i])) {
		int k = g[i][j];
		if (c[i] != c[k]) {
			//printf("try %d %d vs %d %d\n", i, k, x, y);
			if (x==-1) {
				x=i;
				y=k;
			} else {
				if (i==x || k==x) {
					y=-1;
				} else if (i==y || k==y) {
					x=y;
					y=-1;
				} else {
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n%d\n", (x<0 ? 1 : x+1));
	return 0;
}
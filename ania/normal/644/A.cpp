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

int main() {
	int n,a,b;
	scanf("%d%d%d", &n, &a, &b);
	if (a*b < n) {
		printf("-1\n");
		return 0;
	}
	FOR(i,a) {
		FOR(j,b) {
			int cur = i*b;
			if (i&1) cur += b-j;
			else cur += j+1;
			if (cur <= n) printf("%d ", cur);
			else printf("0 ");
		}
		printf("\n");
	}
	return 0;
}
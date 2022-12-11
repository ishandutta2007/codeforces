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

const int maxn = 100100;

char s[maxn];
int p[3][maxn];

int main() {
	int n,m;
	scanf("%s%d", s, &m);
	for (n=0; s[n]; n++) {
		FOR(i,3) p[i][n] = (s[n]=='x'+i) + (n==0?0:p[i][n-1]);
	}
	FOR(i,m) {
		int a,b;
		scanf("%d%d", &a, &b);
		a--; b--;
		int l = b-a+1;
		if (l < 3) {
			printf("YES\n");
			continue;
		}
		vi x,y;
		FOR(j,3) x.pb(p[j][b]-(a==0?0:p[j][a-1]));
		sort(x.begin(), x.end());
		FOR(j,3-l%3) y.pb(l/3);
		FOR(j,l%3) y.pb(l/3+1);
		printf("%s\n", x==y ? "YES" : "NO");
	}
	return 0;
}
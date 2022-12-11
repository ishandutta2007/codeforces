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

const int maxn = 300300;

vi ev[maxn];
int a[maxn], p[maxn];
long long res = 0;

int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	FOR(i,n) {
		scanf("%d", &a[i]);
		p[a[i]] = i;
	}
	multiset<int> all;
	all.insert(n);
	FOR(i,m) {
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		xx = p[xx];
		yy = p[yy];
		if (xx > yy) swap(xx, yy);
		//printf("add %d %d\n", xx, yy);
		all.insert(yy);
		ev[xx].pb(yy);
	}
	FOR(i,n) {
		//printf("seg %d %d\n", i, *all.begin());
		res += *all.begin()-i;
		FOR(j,SZ(ev[i])) all.erase(all.find(ev[i][j]));
	}
	cout << res << "\n";
	return 0;
}
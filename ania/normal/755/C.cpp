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

int par[12345];
int cnt[12345];

int fin(int x) {
	return par[x]==x ? x : par[x]=fin(par[x]);
}

void uni(int x, int y) {
	int fx=fin(x);
	int fy=fin(y);
	par[fx]=fy;
}

int main() {
	int n,p;
	scanf("%d", &n);
	FOR(i,n) par[i]=i;
	FOR(i,n) {
		scanf("%d", &p);
		p--;
		uni(i,p);
	}
	FOR(i,n) cnt[fin(i)]++;
	int res=0;
	FOR(i,n) if (cnt[i]>0) res++;
	printf("%d\n", res);
	return 0;
}
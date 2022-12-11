#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int inf = 1000100100;

int n;
pii t[111];
int s[111];
bool vis[1<<20];
int res[1<<20];

int rec(int mask, int pos) {
	if (vis[mask]) return res[mask];
	if (pos == n) return 0;
	int best = 0;
	if (t[pos].se == 1) best = -inf;
	else best = inf;
	FOR(i,n) if (!(mask & (1<<i))) {
		int nres = rec(mask | (1<<i), pos+1);
		int add = 0;
		if (t[pos].fi) add = s[i];
		if (t[pos].se == 1) {
			nres += add;
			best = max(best, nres);
		} else {
			nres -= add;
			best = min(best, nres);
		}
	}
	vis[mask] = 1;
	res[mask] = best;
	return best;
}

char ac[4];

int main() {
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &s[i]);
	sort(s,s+n,greater<int>());
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%s%d", ac, &t[i].se);
		if (ac[0] == 'b') t[i].fi = 0;
		else t[i].fi = 1;
	}
	printf("%d\n", rec(0,0));
	return 0;
}
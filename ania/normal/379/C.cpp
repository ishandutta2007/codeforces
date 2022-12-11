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

int a[1001000];
pii t[1001000];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) scanf("%d", &a[i]);
	FOR(i,n) t[i] = mp(a[i], i);
	sort(t,t+n);
	int last = 0;
	FOR(i,n) {
		a[t[i].se] = max(last+1, t[i].fi);
		last = a[t[i].se];
	}
	FOR(i,n) printf("%d ", a[i]);
	printf("\n");
}
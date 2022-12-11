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

int main() {
	int x,y,z,t1,t2,t3;
	scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);\
	int stairs = abs(x-y) * t1;
	int elevator = abs(x-y) * t2 + abs(x-z) * t2 + 3*t3;
	if (stairs < elevator) printf("NO\n");
	else printf("YES\n");
	return 0;
}
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

const int N = 100100;

int a[N], b[N], pos[N], used[N];

int main() {
	int n;
	scanf("%d", &n);
	FORI(i,n) scanf("%d", &a[i]);
	FORI(i,n) scanf("%d", &b[i]);
	FORI(i,n) pos[b[i]] = i;
	int lastid = n, res = 0;
	for (int i = n; i >= 1; i--) {
		while (used[lastid]) lastid--;
		if (a[i] != b[lastid]) { res++; }
		used[pos[a[i]]] = 1;
	}
	printf("%d\n", res);
	return 0;
}
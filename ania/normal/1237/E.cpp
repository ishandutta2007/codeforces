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
	int n;
	scanf("%d", &n);
	for (int k = 1; k <= 10; k++) {
		int p4k = 1<<(2*k);
		p4k = (p4k-1) / 3;
		if (n == p4k*2 || n == p4k*2-1 || n == p4k*4 || n == p4k*4+1) {
			printf("1\n");
			return 0;
		}
	}
	if (n == 1) printf("1\n");
	else printf("0\n");
	return 0;
}
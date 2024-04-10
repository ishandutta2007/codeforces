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

int a[123];

int main() {
	int n;
	scanf("%d", &n);
	FOR(i,n) {
		scanf("%d", &a[i]);
	}
	for (int m = n; m >= 1; m /= 2) {
		for (int f = 0; f < n; f += m) {
			bool ok=true;
			FOR(i,m-1) if (a[f+i] > a[f+i+1]) ok=false;
			if (ok) {
				printf("%d\n", m);
				return 0;
			}
		}
	}
	return 0;
}
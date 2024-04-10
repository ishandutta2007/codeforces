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

int n;
int par[N], s[N], a[N];

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) scanf("%d", &par[i]);
	FORI(i,n) scanf("%d", &s[i]);
	FOR(i,n) a[i] = 1e9+5;
	a[1] = s[1];
	for (int i = 2; i <= n; i++) {
		if (s[i] != -1) {
			int pa = par[i], paa = par[pa];
			if (s[paa] > s[i]) {
				printf("-1\n");
				return 0;
			}
			a[pa] = min(a[pa], s[i] - s[paa]);
		}
	}
	for (int i = 2; i <= n; i++) {
		if (s[i] != -1) {
			int pa = par[i], paa = par[pa];
			a[i] = s[i] - a[pa] - s[paa];
		}
	}
	FORI(i,n) if (a[i] > 1e9) a[i] = 0;
	//FORI(i,n) printf("%d ", a[i]); printf("\n");
	long long sum = 0;
	FORI(i,n) sum += a[i];
	cout << sum << "\n";
	return 0;
}